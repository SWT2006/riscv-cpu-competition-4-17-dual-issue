module stage_ex (
    input  wire [31:0] idex_pc,
    input  wire [31:0] idex_pc_plus4,
    input  wire [31:0] idex_rs1_data,
    input  wire [31:0] idex_rs2_data,
    input  wire [31:0] idex_imm,
    input  wire [ 4:0] idex_rs1_addr,
    input  wire [ 4:0] idex_rs2_addr,
    input  wire [ 4:0] idex_rd_addr,
    input  wire [ 4:0] idex_alu_op,
    input  wire        idex_alu_src,
    input  wire        idex_branch,
    input  wire        idex_jal,
    input  wire        idex_jalr,
    input  wire        idex_lui,
    input  wire        idex_auipc,
    input  wire [ 2:0] idex_funct3,
    input  wire        idex_mem_read,
    input  wire        idex_mem_write,
    input  wire        idex_ecall,
    input  wire        idex_mret,
    input  wire        idex_csr_op,
    input  wire [31:0] idex_csr_rdata,
    input  wire [11:0] idex_csr_addr,
    // CSR register values for ECALL/MRET branch targets
    input  wire [31:0] csr_mtvec,
    input  wire [31:0] csr_mepc,
    // Forwarding inputs
    input  wire [ 1:0] forward_a,
    input  wire [ 1:0] forward_b,
    input  wire [31:0] exmem_alu_result,
    input  wire [31:0] wb_write_data,
    input  wire [31:0] exmem_pc_plus4,
    input  wire [ 1:0] exmem_wb_sel,
    input  wire [ 1:0] memwb_wb_sel,
    input  wire [31:0] memwb_pc_plus4,
    // Outputs
    output wire [31:0] alu_result,
    output wire [31:0] rs2_data_fwd,
    output wire        branch_taken,
    output wire [31:0] branch_target,
    // CSR write port (to csr_unit in cpu_top)
    output wire        trap_ecall,
    output wire [31:0] trap_epc,
    output wire [31:0] trap_mcause,   // 0=inst_misalign, 3=EBREAK, 4=load_misalign, 6=store_misalign, 11=ECALL
    output wire [31:0] trap_mtval,    // faulting address for misaligned exceptions
    output wire        csr_wen,
    output wire [11:0] csr_waddr,
    output wire [31:0] csr_wdata,
    // Suppress memory operation in MEM stage (for misaligned stores)
    output wire        suppress_mem,
    // Suppress register writeback in WB stage (for misaligned loads/jumps)
    output wire        suppress_wb
);

    // ALU operation encoding (must match control_unit)
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

    // ---------------------------------------------------------------
    // Forwarding Muxes
    // ---------------------------------------------------------------
    reg [31:0] fwd_a_data;  // Forwarded rs1
    reg [31:0] fwd_b_data;  // Forwarded rs2

    // For EX/MEM forwarding, when the previous instruction is JAL/JALR
    // (wb_sel == 2'b10), we need to forward pc_plus4 instead of alu_result
    wire [31:0] exmem_fwd_data = (exmem_wb_sel == 2'b10) ? exmem_pc_plus4 : exmem_alu_result;
    wire [31:0] memwb_fwd_data = wb_write_data;  // WB stage already muxes correctly

    always @(*) begin
        case (forward_a)
            2'b00:   fwd_a_data = idex_rs1_data;
            2'b10:   fwd_a_data = exmem_fwd_data;
            2'b01:   fwd_a_data = memwb_fwd_data;
            default: fwd_a_data = idex_rs1_data;
        endcase
    end

    always @(*) begin
        case (forward_b)
            2'b00:   fwd_b_data = idex_rs2_data;
            2'b10:   fwd_b_data = exmem_fwd_data;
            2'b01:   fwd_b_data = memwb_fwd_data;
            default: fwd_b_data = idex_rs2_data;
        endcase
    end

    assign rs2_data_fwd = fwd_b_data;

    // ---------------------------------------------------------------
    // ALU Input Selection
    // ---------------------------------------------------------------
    wire [31:0] alu_operand_a;
    wire [31:0] alu_operand_b;

    assign alu_operand_a = idex_auipc ? idex_pc : fwd_a_data;
    assign alu_operand_b = idex_alu_src ? idex_imm : fwd_b_data;

    // ---------------------------------------------------------------
    // ALU (including M-extension)
    // ---------------------------------------------------------------
    reg [31:0] alu_out;

    // Signed/unsigned helpers for M-extension
    wire signed [31:0] signed_a   = $signed(alu_operand_a);
    wire signed [31:0] signed_b   = $signed(alu_operand_b);
    wire        [63:0] mul_uu     = alu_operand_a * alu_operand_b;
    wire signed [63:0] mul_ss     = signed_a * signed_b;
    wire signed [63:0] mul_su     = signed_a * $signed({1'b0, alu_operand_b});

    always @(*) begin
        case (idex_alu_op)
            ALU_ADD:    alu_out = alu_operand_a + alu_operand_b;
            ALU_SUB:    alu_out = alu_operand_a - alu_operand_b;
            ALU_SLL:    alu_out = alu_operand_a << alu_operand_b[4:0];
            ALU_SLT:    alu_out = ($signed(alu_operand_a) < $signed(alu_operand_b)) ? 32'd1 : 32'd0;
            ALU_SLTU:   alu_out = (alu_operand_a < alu_operand_b) ? 32'd1 : 32'd0;
            ALU_XOR:    alu_out = alu_operand_a ^ alu_operand_b;
            ALU_SRL:    alu_out = alu_operand_a >> alu_operand_b[4:0];
            ALU_SRA:    alu_out = $signed(alu_operand_a) >>> alu_operand_b[4:0];
            ALU_OR:     alu_out = alu_operand_a | alu_operand_b;
            ALU_AND:    alu_out = alu_operand_a & alu_operand_b;
            ALU_PASS_B: alu_out = alu_operand_b;
            // M extension
            ALU_MUL:    alu_out = mul_ss[31:0];
            ALU_MULH:   alu_out = mul_ss[63:32];
            ALU_MULHSU: alu_out = mul_su[63:32];
            ALU_MULHU:  alu_out = mul_uu[63:32];
            ALU_DIV:    alu_out = (alu_operand_b == 32'b0) ? 32'hFFFF_FFFF :
                                  (alu_operand_a == 32'h8000_0000 && alu_operand_b == 32'hFFFF_FFFF) ? 32'h8000_0000 :
                                  $signed(signed_a / signed_b);
            ALU_DIVU:   alu_out = (alu_operand_b == 32'b0) ? 32'hFFFF_FFFF :
                                  (alu_operand_a / alu_operand_b);
            ALU_REM:    alu_out = (alu_operand_b == 32'b0) ? alu_operand_a :
                                  (alu_operand_a == 32'h8000_0000 && alu_operand_b == 32'hFFFF_FFFF) ? 32'h0 :
                                  $signed(signed_a % signed_b);
            ALU_REMU:   alu_out = (alu_operand_b == 32'b0) ? alu_operand_a :
                                  (alu_operand_a % alu_operand_b);
            default:    alu_out = 32'b0;
        endcase
    end

    // For CSR instructions the old CSR value is the write-back data (rd = old_csr)
    assign alu_result = idex_csr_op ? idex_csr_rdata : alu_out;

    // ---------------------------------------------------------------
    // Branch Comparison Unit
    // ---------------------------------------------------------------
    reg  branch_cond;

    always @(*) begin
        case (idex_funct3)
            3'b000:  branch_cond = (fwd_a_data == fwd_b_data);
            3'b001:  branch_cond = (fwd_a_data != fwd_b_data);
            3'b100:  branch_cond = ($signed(fwd_a_data) < $signed(fwd_b_data));
            3'b101:  branch_cond = ($signed(fwd_a_data) >= $signed(fwd_b_data));
            3'b110:  branch_cond = (fwd_a_data < fwd_b_data);
            3'b111:  branch_cond = (fwd_a_data >= fwd_b_data);
            default: branch_cond = 1'b0;
        endcase
    end

    // ---------------------------------------------------------------
    // Branch / Jump Target Calculation
    // ---------------------------------------------------------------
    wire [31:0] pc_branch_target = idex_pc + idex_imm;
    wire [31:0] jalr_target      = (fwd_a_data + idex_imm) & 32'hFFFFFFFE;

    // ---------------------------------------------------------------
    // Misaligned exception detection
    // ---------------------------------------------------------------
    // Instruction address misaligned: JAL/JALR to a non-4-byte-aligned address
    wire [31:0] jmp_target = idex_jalr ? jalr_target : pc_branch_target;
    wire misalign_jmp    = (idex_jal | idex_jalr) && jmp_target[1];
    // Taken conditional branch to a non-4-byte-aligned address
    wire misalign_branch = idex_branch && branch_cond && pc_branch_target[1];

    // Load address misaligned
    wire lw_misalign   = idex_mem_read  && (idex_funct3 == 3'b010) && (alu_out[1:0] != 2'b00);
    wire lh_misalign   = idex_mem_read  && (idex_funct3 == 3'b001 || idex_funct3 == 3'b101) && alu_out[0];
    wire misalign_load = lw_misalign | lh_misalign;

    // Store address misaligned
    wire sw_misalign    = idex_mem_write && (idex_funct3 == 3'b010) && (alu_out[1:0] != 2'b00);
    wire sh_misalign    = idex_mem_write && (idex_funct3 == 3'b001) && alu_out[0];
    wire misalign_store = sw_misalign | sh_misalign;

    wire any_misalign = misalign_jmp | misalign_branch | misalign_load | misalign_store;

    assign branch_taken  = idex_jal | idex_jalr | (idex_branch & branch_cond)
                         | idex_ecall | idex_mret | any_misalign;
    assign branch_target = (any_misalign)  ? csr_mtvec :
                           idex_ecall      ? csr_mtvec :
                           idex_mret       ? csr_mepc  :
                           idex_jalr       ? jalr_target :
                                             pc_branch_target;

    // ---------------------------------------------------------------
    // CSR write data computation
    // ---------------------------------------------------------------
    wire [31:0] zimm = {27'b0, idex_rs1_addr};  // zero-extended rs1 field for CSRRxI

    reg [31:0] csr_wdata_reg;
    always @(*) begin
        case (idex_funct3)
            3'b001: csr_wdata_reg = fwd_a_data;                    // CSRRW
            3'b010: csr_wdata_reg = idex_csr_rdata | fwd_a_data;  // CSRRS
            3'b011: csr_wdata_reg = idex_csr_rdata & ~fwd_a_data; // CSRRC
            3'b101: csr_wdata_reg = zimm;                          // CSRRWI
            3'b110: csr_wdata_reg = idex_csr_rdata | zimm;        // CSRRSI
            3'b111: csr_wdata_reg = idex_csr_rdata & ~zimm;       // CSRRCI
            default: csr_wdata_reg = fwd_a_data;
        endcase
    end

    assign trap_ecall  = idex_ecall | any_misalign;
    assign trap_epc    = idex_pc;
    // mcause: 0=inst_misalign, 3=EBREAK, 4=load_misalign, 6=store_misalign, 11=ECALL
    assign trap_mcause = (misalign_jmp | misalign_branch) ? 32'd0  :
                         misalign_load              ? 32'd4  :
                         misalign_store             ? 32'd6  :
                         (idex_rs2_addr == 5'd1)    ? 32'd3  :  // EBREAK
                                                       32'd11;   // ECALL
    assign trap_mtval  = (misalign_load | misalign_store) ? alu_out : jmp_target;
    assign suppress_mem = misalign_store;
    assign suppress_wb  = misalign_load | misalign_jmp | misalign_branch;
    assign csr_wen    = idex_csr_op;
    assign csr_waddr  = idex_csr_addr;
    assign csr_wdata  = csr_wdata_reg;

endmodule
