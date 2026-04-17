`timescale 1ns/1ps
// 2-wide ID stage: dual instruction decode, 4-read / 2-write register file.
//
// Instantiates two control_unit and two imm_gen modules (one per slot).
// The register file has 4 combinational read ports (rs1_a, rs2_a, rs1_b, rs2_b)
// and 2 synchronous write ports (from WB pipe A and pipe B).
// Write priority: pipe B > pipe A for same-address writes (B is later in program order).
// WB-to-ID bypass is applied on all 4 read ports.
//
// CSR read is only for slot A (slot B never executes CSR instructions).
module stage_id (
    input  wire        clk,
    input  wire        cpu_rst,
    // Slot A instruction (from IF/ID)
    input  wire [31:0] inst_a,
    // Slot B instruction (from IF/ID)
    input  wire [31:0] inst_b,
    input  wire        b_valid,
    // Write-back port A (from WB stage, pipe A)
    input  wire        wb_reg_write_a,
    input  wire [4:0]  wb_rd_addr_a,
    input  wire [31:0] wb_write_data_a,
    // Write-back port B (from WB stage, pipe B)
    input  wire        wb_reg_write_b,
    input  wire [4:0]  wb_rd_addr_b,
    input  wire [31:0] wb_write_data_b,
    // CSR read (combinational, from csr_unit — slot A only)
    input  wire [31:0] csr_rdata,
    // ---- Slot A decoded outputs ----
    output wire [31:0] a_rs1_data,
    output wire [31:0] a_rs2_data,
    output wire [31:0] a_imm,
    output wire [4:0]  a_rs1_addr,
    output wire [4:0]  a_rs2_addr,
    output wire [4:0]  a_rd_addr,
    output wire [11:0] a_csr_addr,
    output wire [31:0] a_csr_rdata_out,
    output wire [4:0]  a_alu_op,
    output wire        a_alu_src,
    output wire        a_mem_read,
    output wire        a_mem_write,
    output wire [2:0]  a_mem_funct3,
    output wire        a_reg_write,
    output wire [1:0]  a_wb_sel,
    output wire        a_branch,
    output wire        a_jal,
    output wire        a_jalr,
    output wire        a_auipc,
    output wire        a_ecall,
    output wire        a_mret,
    output wire        a_csr_op,
    // ---- Slot B decoded outputs ----
    output wire [31:0] b_rs1_data,
    output wire [31:0] b_rs2_data,
    output wire [31:0] b_imm,
    output wire [4:0]  b_rs1_addr,
    output wire [4:0]  b_rs2_addr,
    output wire [4:0]  b_rd_addr,
    output wire [4:0]  b_alu_op,
    output wire        b_alu_src,
    output wire        b_mem_read,
    output wire        b_mem_write,
    output wire [2:0]  b_mem_funct3,
    output wire        b_reg_write,
    output wire [1:0]  b_wb_sel,
    output wire        b_branch,
    output wire        b_jal,
    output wire        b_jalr,
    output wire        b_auipc,
    output wire        b_ecall,
    output wire        b_mret,
    output wire        b_csr_op
);

    // =================================================================
    // Slot A field extraction
    // =================================================================
    assign a_rs1_addr      = inst_a[19:15];
    assign a_rs2_addr      = inst_a[24:20];
    assign a_rd_addr       = inst_a[11:7];
    assign a_mem_funct3    = inst_a[14:12];
    assign a_csr_addr      = inst_a[31:20];
    assign a_csr_rdata_out = csr_rdata;

    // =================================================================
    // Slot B field extraction
    // =================================================================
    assign b_rs1_addr   = inst_b[19:15];
    assign b_rs2_addr   = inst_b[24:20];
    assign b_rd_addr    = inst_b[11:7];
    assign b_mem_funct3 = inst_b[14:12];

    // =================================================================
    // Register file (x0 hardwired to 0)
    // 4 read ports (combinational), 2 write ports (synchronous)
    // =================================================================
    reg [31:0] regfile [1:31];
    integer i;

    always @(posedge clk) begin
        if (cpu_rst) begin
            for (i = 1; i < 32; i = i + 1)
                regfile[i] <= 32'b0;
        end else begin
            // Write port A
            if (wb_reg_write_a && wb_rd_addr_a != 5'b0)
                regfile[wb_rd_addr_a] <= wb_write_data_a;
            // Write port B (higher priority — overwrites A if same register)
            if (wb_reg_write_b && wb_rd_addr_b != 5'b0)
                regfile[wb_rd_addr_b] <= wb_write_data_b;
        end
    end

    // ---------------------------------------------------------------
    // Combinational read with WB-to-ID bypass.
    // Bypass priority: pipe B > pipe A (B is later in program order).
    // Explicit always blocks avoid iverilog function evaluation bug.
    // ---------------------------------------------------------------
    reg [31:0] a_rs1_data_r, a_rs2_data_r, b_rs1_data_r, b_rs2_data_r;

    always @(*) begin
        if (a_rs1_addr == 5'b0)
            a_rs1_data_r = 32'b0;
        else if (wb_reg_write_b && wb_rd_addr_b == a_rs1_addr)
            a_rs1_data_r = wb_write_data_b;
        else if (wb_reg_write_a && wb_rd_addr_a == a_rs1_addr)
            a_rs1_data_r = wb_write_data_a;
        else
            a_rs1_data_r = regfile[a_rs1_addr];
    end

    always @(*) begin
        if (a_rs2_addr == 5'b0)
            a_rs2_data_r = 32'b0;
        else if (wb_reg_write_b && wb_rd_addr_b == a_rs2_addr)
            a_rs2_data_r = wb_write_data_b;
        else if (wb_reg_write_a && wb_rd_addr_a == a_rs2_addr)
            a_rs2_data_r = wb_write_data_a;
        else
            a_rs2_data_r = regfile[a_rs2_addr];
    end

    always @(*) begin
        if (b_rs1_addr == 5'b0)
            b_rs1_data_r = 32'b0;
        else if (wb_reg_write_b && wb_rd_addr_b == b_rs1_addr)
            b_rs1_data_r = wb_write_data_b;
        else if (wb_reg_write_a && wb_rd_addr_a == b_rs1_addr)
            b_rs1_data_r = wb_write_data_a;
        else
            b_rs1_data_r = regfile[b_rs1_addr];
    end

    always @(*) begin
        if (b_rs2_addr == 5'b0)
            b_rs2_data_r = 32'b0;
        else if (wb_reg_write_b && wb_rd_addr_b == b_rs2_addr)
            b_rs2_data_r = wb_write_data_b;
        else if (wb_reg_write_a && wb_rd_addr_a == b_rs2_addr)
            b_rs2_data_r = wb_write_data_a;
        else
            b_rs2_data_r = regfile[b_rs2_addr];
    end

    assign a_rs1_data = a_rs1_data_r;
    assign a_rs2_data = a_rs2_data_r;
    assign b_rs1_data = b_rs1_data_r;
    assign b_rs2_data = b_rs2_data_r;

    // =================================================================
    // Slot A: immediate generator + control unit
    // =================================================================
    imm_gen u_imm_a (
        .instruction (inst_a),
        .imm         (a_imm)
    );

    wire a_lui;   // unused downstream (alu_op=PASS_B handles it)
    control_unit u_ctrl_a (
        .opcode    (inst_a[6:0]),
        .funct3    (inst_a[14:12]),
        .funct7    (inst_a[31:25]),
        .funct12   (inst_a[31:20]),
        .alu_op    (a_alu_op),
        .alu_src   (a_alu_src),
        .mem_read  (a_mem_read),
        .mem_write (a_mem_write),
        .reg_write (a_reg_write),
        .wb_sel    (a_wb_sel),
        .branch    (a_branch),
        .jal       (a_jal),
        .jalr      (a_jalr),
        .lui       (a_lui),
        .auipc     (a_auipc),
        .ecall     (a_ecall),
        .mret      (a_mret),
        .csr_op    (a_csr_op)
    );

    // =================================================================
    // Slot B: immediate generator + control unit
    // =================================================================
    imm_gen u_imm_b (
        .instruction (inst_b),
        .imm         (b_imm)
    );

    wire b_lui;
    control_unit u_ctrl_b (
        .opcode    (inst_b[6:0]),
        .funct3    (inst_b[14:12]),
        .funct7    (inst_b[31:25]),
        .funct12   (inst_b[31:20]),
        .alu_op    (b_alu_op),
        .alu_src   (b_alu_src),
        .mem_read  (b_mem_read),
        .mem_write (b_mem_write),
        .reg_write (b_reg_write),
        .wb_sel    (b_wb_sel),
        .branch    (b_branch),
        .jal       (b_jal),
        .jalr      (b_jalr),
        .lui       (b_lui),
        .auipc     (b_auipc),
        .ecall     (b_ecall),
        .mret      (b_mret),
        .csr_op    (b_csr_op)
    );

endmodule
