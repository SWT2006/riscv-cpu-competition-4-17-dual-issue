`timescale 1ns/1ps
// 2-wide EX stage: dual execution pipes.
//
// Pipe A (primary): Full ALU, branch comparison, pipelined multiply,
//   sequential divide, CSR operations, ECALL/MRET, load/store address.
// Pipe B (secondary): Simple ALU, load/store address computation.
//   No branch, no mul/div, no CSR.
//
// Forwarding muxes: each operand (a_rs1, a_rs2, b_rs1, b_rs2) selects
// from 5 sources based on the forwarding_unit's 3-bit encoding:
//   000 = register file value (from ID/EX register)
//   001 = memwb pipe A
//   010 = memwb pipe B
//   011 = exmem pipe A
//   100 = exmem pipe B
module stage_ex (
    input  wire        clk,
    input  wire        cpu_rst,
    // ---- Pipe A inputs (from ID/EX) ----
    input  wire [31:0] idex_a_pc,
    input  wire [31:0] idex_a_pc_plus4,
    input  wire [31:0] idex_a_rs1_data,
    input  wire [31:0] idex_a_rs2_data,
    input  wire [31:0] idex_a_imm,
    input  wire [4:0]  idex_a_rs1_addr,
    input  wire [4:0]  idex_a_rs2_addr,
    input  wire [4:0]  idex_a_alu_op,
    input  wire        idex_a_alu_src,
    input  wire        idex_a_branch,
    input  wire        idex_a_jal,
    input  wire        idex_a_jalr,
    input  wire        idex_a_auipc,
    input  wire [2:0]  idex_a_funct3,
    input  wire        idex_a_ecall,
    input  wire        idex_a_mret,
    input  wire        idex_a_csr_op,
    input  wire [31:0] idex_a_csr_rdata,
    input  wire [11:0] idex_a_csr_addr,
    input  wire [31:0] csr_mtvec,
    input  wire [31:0] csr_mepc,
    // ---- Pipe B inputs (from ID/EX) ----
    input  wire        idex_b_valid,
    input  wire [31:0] idex_b_pc,
    input  wire [31:0] idex_b_rs1_data,
    input  wire [31:0] idex_b_rs2_data,
    input  wire [31:0] idex_b_imm,
    input  wire [4:0]  idex_b_alu_op,
    input  wire        idex_b_alu_src,
    input  wire        idex_b_auipc,
    // ---- Intra-group A→B forwarding detection ----
    input  wire [4:0]  idex_a_rd_addr,
    input  wire        idex_a_reg_write,
    input  wire [4:0]  idex_b_rs1_addr,
    input  wire [4:0]  idex_b_rs2_addr,
    // ---- Forwarding select signals ----
    input  wire [2:0]  fwd_a_rs1,
    input  wire [2:0]  fwd_a_rs2,
    input  wire [2:0]  fwd_b_rs1,
    input  wire [2:0]  fwd_b_rs2,
    // ---- Forwarding data sources ----
    input  wire [31:0] exmem_a_fwd_data,
    input  wire [31:0] exmem_b_fwd_data,
    input  wire [31:0] memwb_a_write_data,
    input  wire [31:0] memwb_b_write_data,
    // ---- Pipe A outputs ----
    output wire [31:0] a_alu_result,
    output wire [31:0] a_rs2_data_fwd,   // forwarded rs2 (for store data)
    output wire        a_branch_taken,
    output wire [31:0] a_branch_target,
    output wire        a_trap_valid,
    output wire [31:0] a_trap_epc,
    output wire [31:0] a_trap_mcause,
    output wire        a_csr_wen,
    output wire [11:0] a_csr_waddr,
    output wire [31:0] a_csr_wdata,
    output wire        div_stall,
    output wire        mul_stall,
    // ---- Pipe B outputs ----
    output wire [31:0] b_alu_result,
    output wire [31:0] b_rs2_data_fwd    // forwarded rs2 (for store data)
);

    // ALU operation encodings (must match control_unit.sv)
    localparam ALU_ADD    = 5'd0;
    localparam ALU_SUB    = 5'd1;
    localparam ALU_SLL    = 5'd2;
    localparam ALU_SLT    = 5'd3;
    localparam ALU_SLTU   = 5'd4;
    localparam ALU_XOR    = 5'd5;
    localparam ALU_SRL    = 5'd6;
    localparam ALU_SRA    = 5'd7;
    localparam ALU_OR     = 5'd8;
    localparam ALU_AND    = 5'd9;
    localparam ALU_PASS_B = 5'd10;
    localparam ALU_MUL    = 5'd11;
    localparam ALU_MULH   = 5'd12;
    localparam ALU_MULHSU = 5'd13;
    localparam ALU_MULHU  = 5'd14;
    localparam ALU_DIV    = 5'd15;
    localparam ALU_DIVU   = 5'd16;
    localparam ALU_REM    = 5'd17;
    localparam ALU_REMU   = 5'd18;

    // =================================================================
    // Forwarding muxes — explicit always-block for each operand
    // =================================================================
    reg [31:0] fwd_a1, fwd_a2, fwd_b1, fwd_b2;

    always @(*) begin
        case (fwd_a_rs1)
            3'b100:  fwd_a1 = exmem_b_fwd_data;
            3'b011:  fwd_a1 = exmem_a_fwd_data;
            3'b010:  fwd_a1 = memwb_b_write_data;
            3'b001:  fwd_a1 = memwb_a_write_data;
            default: fwd_a1 = idex_a_rs1_data;
        endcase
    end
    always @(*) begin
        case (fwd_a_rs2)
            3'b100:  fwd_a2 = exmem_b_fwd_data;
            3'b011:  fwd_a2 = exmem_a_fwd_data;
            3'b010:  fwd_a2 = memwb_b_write_data;
            3'b001:  fwd_a2 = memwb_a_write_data;
            default: fwd_a2 = idex_a_rs2_data;
        endcase
    end
    always @(*) begin
        case (fwd_b_rs1)
            3'b100:  fwd_b1 = exmem_b_fwd_data;
            3'b011:  fwd_b1 = exmem_a_fwd_data;
            3'b010:  fwd_b1 = memwb_b_write_data;
            3'b001:  fwd_b1 = memwb_a_write_data;
            default: fwd_b1 = idex_b_rs1_data;
        endcase
    end
    always @(*) begin
        case (fwd_b_rs2)
            3'b100:  fwd_b2 = exmem_b_fwd_data;
            3'b011:  fwd_b2 = exmem_a_fwd_data;
            3'b010:  fwd_b2 = memwb_b_write_data;
            3'b001:  fwd_b2 = memwb_a_write_data;
            default: fwd_b2 = idex_b_rs2_data;
        endcase
    end

    assign a_rs2_data_fwd = fwd_a2;

    // =================================================================
    // PIPE A: Full execution unit
    // =================================================================

    // ---- ALU operand selection ----
    wire [31:0] a_alu_a = idex_a_auipc ? idex_a_pc  : fwd_a1;
    wire [31:0] a_alu_b = idex_a_alu_src ? idex_a_imm : fwd_a2;

    // ---- Consolidated multiply (33x33 signed, pipelined) ----
    wire mul_a_sign = (idex_a_alu_op != ALU_MULHU);
    wire mul_b_sign = (idex_a_alu_op == ALU_MUL || idex_a_alu_op == ALU_MULH);

    wire signed [32:0] mul_op_a = {mul_a_sign & a_alu_a[31], a_alu_a};
    wire signed [32:0] mul_op_b = {mul_b_sign & a_alu_b[31], a_alu_b};

    // ---- Multi-cycle divider ----
    wire is_div_op = (idex_a_alu_op == ALU_DIV)  || (idex_a_alu_op == ALU_DIVU)
                   || (idex_a_alu_op == ALU_REM)  || (idex_a_alu_op == ALU_REMU);
    wire        div_busy, div_done;
    wire [31:0] div_result;
    wire div_start    = is_div_op && !div_busy && !div_done;
    wire div_op_signed = (idex_a_alu_op == ALU_DIV) || (idex_a_alu_op == ALU_REM);
    wire div_op_rem    = (idex_a_alu_op == ALU_REM) || (idex_a_alu_op == ALU_REMU);

    div_unit u_div (
        .clk       (clk),
        .rst       (cpu_rst),
        .start     (div_start),
        .dividend  (a_alu_a),
        .divisor   (a_alu_b),
        .op_signed (div_op_signed),
        .op_rem    (div_op_rem),
        .busy      (div_busy),
        .done      (div_done),
        .result    (div_result)
    );

    assign div_stall = is_div_op & ~div_done;

    // ---- Pipelined multiply ----
    wire is_mul_op = (idex_a_alu_op == ALU_MUL)    || (idex_a_alu_op == ALU_MULH)
                  || (idex_a_alu_op == ALU_MULHSU)  || (idex_a_alu_op == ALU_MULHU);

    reg mul_valid;
    always @(posedge clk) begin
        if (cpu_rst)
            mul_valid <= 1'b0;
        else
            mul_valid <= is_mul_op & ~mul_valid;
    end
    assign mul_stall = is_mul_op & ~mul_valid;

    (* use_dsp = "yes" *)
    reg signed [65:0] mul_result_r;
    always @(posedge clk) begin
        mul_result_r <= mul_op_a * mul_op_b;
    end

    // ---- Pipe A ALU ----
    reg [31:0] a_alu_out;
    always @(*) begin
        case (idex_a_alu_op)
            ALU_ADD:    a_alu_out = a_alu_a + a_alu_b;
            ALU_SUB:    a_alu_out = a_alu_a - a_alu_b;
            ALU_SLL:    a_alu_out = a_alu_a << a_alu_b[4:0];
            ALU_SLT:    a_alu_out = ($signed(a_alu_a) < $signed(a_alu_b)) ? 32'd1 : 32'd0;
            ALU_SLTU:   a_alu_out = (a_alu_a < a_alu_b) ? 32'd1 : 32'd0;
            ALU_XOR:    a_alu_out = a_alu_a ^ a_alu_b;
            ALU_SRL:    a_alu_out = a_alu_a >> a_alu_b[4:0];
            ALU_SRA:    a_alu_out = $signed(a_alu_a) >>> a_alu_b[4:0];
            ALU_OR:     a_alu_out = a_alu_a | a_alu_b;
            ALU_AND:    a_alu_out = a_alu_a & a_alu_b;
            ALU_PASS_B: a_alu_out = a_alu_b;
            ALU_MUL:    a_alu_out = mul_result_r[31:0];
            ALU_MULH:   a_alu_out = mul_result_r[63:32];
            ALU_MULHSU: a_alu_out = mul_result_r[63:32];
            ALU_MULHU:  a_alu_out = mul_result_r[63:32];
            ALU_DIV:    a_alu_out = div_result;
            ALU_DIVU:   a_alu_out = div_result;
            ALU_REM:    a_alu_out = div_result;
            ALU_REMU:   a_alu_out = div_result;
            default:    a_alu_out = 32'b0;
        endcase
    end

    // CSR read: rd gets old CSR value
    assign a_alu_result = idex_a_csr_op ? idex_a_csr_rdata : a_alu_out;

    // ---- Branch comparison (Pipe A only) ----
    reg a_branch_cond;
    always @(*) begin
        case (idex_a_funct3)
            3'b000:  a_branch_cond = (fwd_a1 == fwd_a2);
            3'b001:  a_branch_cond = (fwd_a1 != fwd_a2);
            3'b100:  a_branch_cond = ($signed(fwd_a1) < $signed(fwd_a2));
            3'b101:  a_branch_cond = ($signed(fwd_a1) >= $signed(fwd_a2));
            3'b110:  a_branch_cond = (fwd_a1 < fwd_a2);
            3'b111:  a_branch_cond = (fwd_a1 >= fwd_a2);
            default: a_branch_cond = 1'b0;
        endcase
    end

    // ---- Branch/jump targets ----
    wire [31:0] a_pc_branch = idex_a_pc + idex_a_imm;
    wire [31:0] a_jalr_tgt  = (fwd_a1 + idex_a_imm) & 32'hFFFF_FFFE;

    assign a_branch_taken = idex_a_jal | idex_a_jalr
                          | (idex_a_branch & a_branch_cond)
                          | idex_a_ecall | idex_a_mret;

    assign a_branch_target = idex_a_mret  ? csr_mepc  :
                             idex_a_ecall ? csr_mtvec :
                             idex_a_jalr  ? a_jalr_tgt :
                                            a_pc_branch;

    // ---- Trap output ----
    assign a_trap_valid  = idex_a_ecall;
    assign a_trap_epc    = idex_a_pc;
    assign a_trap_mcause = (idex_a_csr_addr == 12'h001) ? 32'd3 : 32'd11;

    // ---- CSR write data ----
    wire [31:0] a_zimm = {27'b0, idex_a_rs1_addr};
    reg [31:0] a_csr_wd;
    always @(*) begin
        case (idex_a_funct3)
            3'b001: a_csr_wd = fwd_a1;
            3'b010: a_csr_wd = idex_a_csr_rdata | fwd_a1;
            3'b011: a_csr_wd = idex_a_csr_rdata & ~fwd_a1;
            3'b101: a_csr_wd = a_zimm;
            3'b110: a_csr_wd = idex_a_csr_rdata | a_zimm;
            3'b111: a_csr_wd = idex_a_csr_rdata & ~a_zimm;
            default: a_csr_wd = fwd_a1;
        endcase
    end

    assign a_csr_wen   = idex_a_csr_op;
    assign a_csr_waddr = idex_a_csr_addr;
    assign a_csr_wdata = a_csr_wd;

    // =================================================================
    // Intra-group A→B forwarding (same-cycle EX dependency)
    //
    // When A is a fast ALU op and writes a register that B reads,
    // the issue unit allows dual-issue. A's combinational ALU result
    // is forwarded to B's operand mux with highest priority.
    // =================================================================
    wire a_intra_valid = idex_b_valid
                       & idex_a_reg_write
                       & (idex_a_rd_addr != 5'b0);
    wire b_intra_rs1 = a_intra_valid & (idex_a_rd_addr == idex_b_rs1_addr);
    wire b_intra_rs2 = a_intra_valid & (idex_a_rd_addr == idex_b_rs2_addr);

    wire [31:0] fwd_b1_eff = b_intra_rs1 ? a_alu_result : fwd_b1;
    wire [31:0] fwd_b2_eff = b_intra_rs2 ? a_alu_result : fwd_b2;

    assign b_rs2_data_fwd = fwd_b2_eff;

    // =================================================================
    // PIPE B: Simple ALU (no branch, mul, div, CSR)
    // =================================================================
    wire [31:0] b_alu_a = idex_b_auipc ? idex_b_pc  : fwd_b1_eff;
    wire [31:0] b_alu_b = idex_b_alu_src ? idex_b_imm : fwd_b2_eff;

    reg [31:0] b_alu_out;
    always @(*) begin
        case (idex_b_alu_op)
            ALU_ADD:    b_alu_out = b_alu_a + b_alu_b;
            ALU_SUB:    b_alu_out = b_alu_a - b_alu_b;
            ALU_SLL:    b_alu_out = b_alu_a << b_alu_b[4:0];
            ALU_SLT:    b_alu_out = ($signed(b_alu_a) < $signed(b_alu_b)) ? 32'd1 : 32'd0;
            ALU_SLTU:   b_alu_out = (b_alu_a < b_alu_b) ? 32'd1 : 32'd0;
            ALU_XOR:    b_alu_out = b_alu_a ^ b_alu_b;
            ALU_SRL:    b_alu_out = b_alu_a >> b_alu_b[4:0];
            ALU_SRA:    b_alu_out = $signed(b_alu_a) >>> b_alu_b[4:0];
            ALU_OR:     b_alu_out = b_alu_a | b_alu_b;
            ALU_AND:    b_alu_out = b_alu_a & b_alu_b;
            ALU_PASS_B: b_alu_out = b_alu_b;
            default:    b_alu_out = 32'b0;
        endcase
    end

    assign b_alu_result = b_alu_out;

endmodule
