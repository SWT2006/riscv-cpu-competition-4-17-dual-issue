`timescale 1ns/1ps
// 2-wide ID/EX pipeline register.
//
// Carries decoded signals for both pipe A and pipe B, plus b_valid.
//
// Priority: reset > hold > flush > normal latch.
//   hold:  multi-cycle EX op (div/mul) — keep both slots in EX.
//   flush: load-use stall or branch mispredict — insert NOP pair.
//
// IMPORTANT: hold takes priority over flush.  In the 2-wide pipeline,
// it is possible for both to be active simultaneously (e.g. MUL in pipe A
// + load in pipe B creates ex_stall, while the next instruction in ID has
// a load-use dependency on pipe B's load).  Flushing while holding would
// destroy the in-progress multi-cycle operation.
module pipe_idex (
    input  wire        clk,
    input  wire        cpu_rst,
    input  wire        flush,
    input  wire        hold,
    // ---- Slot A inputs from ID ----
    input  wire [31:0] id_a_pc,
    input  wire [31:0] id_a_pc_plus4,
    input  wire [31:0] id_a_rs1_data,
    input  wire [31:0] id_a_rs2_data,
    input  wire [31:0] id_a_imm,
    input  wire [4:0]  id_a_rs1_addr,
    input  wire [4:0]  id_a_rs2_addr,
    input  wire [4:0]  id_a_rd_addr,
    input  wire [4:0]  id_a_alu_op,
    input  wire        id_a_alu_src,
    input  wire        id_a_mem_read,
    input  wire        id_a_mem_write,
    input  wire [2:0]  id_a_mem_funct3,
    input  wire        id_a_reg_write,
    input  wire [1:0]  id_a_wb_sel,
    input  wire        id_a_branch,
    input  wire        id_a_jal,
    input  wire        id_a_jalr,
    input  wire        id_a_auipc,
    input  wire [2:0]  id_a_funct3,
    input  wire        id_a_ecall,
    input  wire        id_a_mret,
    input  wire        id_a_csr_op,
    input  wire [31:0] id_a_csr_rdata,
    input  wire [11:0] id_a_csr_addr,
    input  wire        id_a_predicted,
    input  wire [31:0] id_a_predicted_target,
    // ---- Slot B inputs from ID ----
    input  wire        id_b_valid,
    input  wire [31:0] id_b_pc,
    input  wire [31:0] id_b_pc_plus4,
    input  wire [31:0] id_b_rs1_data,
    input  wire [31:0] id_b_rs2_data,
    input  wire [31:0] id_b_imm,
    input  wire [4:0]  id_b_rs1_addr,
    input  wire [4:0]  id_b_rs2_addr,
    input  wire [4:0]  id_b_rd_addr,
    input  wire [4:0]  id_b_alu_op,
    input  wire        id_b_alu_src,
    input  wire        id_b_mem_read,
    input  wire        id_b_mem_write,
    input  wire [2:0]  id_b_mem_funct3,
    input  wire        id_b_reg_write,
    input  wire [1:0]  id_b_wb_sel,
    input  wire        id_b_auipc,
    // ---- Slot A outputs to EX ----
    output reg  [31:0] idex_a_pc,
    output reg  [31:0] idex_a_pc_plus4,
    output reg  [31:0] idex_a_rs1_data,
    output reg  [31:0] idex_a_rs2_data,
    output reg  [31:0] idex_a_imm,
    output reg  [4:0]  idex_a_rs1_addr,
    output reg  [4:0]  idex_a_rs2_addr,
    output reg  [4:0]  idex_a_rd_addr,
    output reg  [4:0]  idex_a_alu_op,
    output reg         idex_a_alu_src,
    output reg         idex_a_mem_read,
    output reg         idex_a_mem_write,
    output reg  [2:0]  idex_a_mem_funct3,
    output reg         idex_a_reg_write,
    output reg  [1:0]  idex_a_wb_sel,
    output reg         idex_a_branch,
    output reg         idex_a_jal,
    output reg         idex_a_jalr,
    output reg         idex_a_auipc,
    output reg  [2:0]  idex_a_funct3,
    output reg         idex_a_ecall,
    output reg         idex_a_mret,
    output reg         idex_a_csr_op,
    output reg  [31:0] idex_a_csr_rdata,
    output reg  [11:0] idex_a_csr_addr,
    output reg         idex_a_predicted,
    output reg  [31:0] idex_a_predicted_target,
    // ---- Slot B outputs to EX ----
    output reg         idex_b_valid,
    output reg  [31:0] idex_b_pc,
    output reg  [31:0] idex_b_pc_plus4,
    output reg  [31:0] idex_b_rs1_data,
    output reg  [31:0] idex_b_rs2_data,
    output reg  [31:0] idex_b_imm,
    output reg  [4:0]  idex_b_rs1_addr,
    output reg  [4:0]  idex_b_rs2_addr,
    output reg  [4:0]  idex_b_rd_addr,
    output reg  [4:0]  idex_b_alu_op,
    output reg         idex_b_alu_src,
    output reg         idex_b_mem_read,
    output reg         idex_b_mem_write,
    output reg  [2:0]  idex_b_mem_funct3,
    output reg         idex_b_reg_write,
    output reg  [1:0]  idex_b_wb_sel,
    output reg         idex_b_auipc
);

    always @(posedge clk) begin
        if (cpu_rst) begin
            // ---- Zero everything (NOP pair) ----
            idex_a_pc               <= 32'b0;
            idex_a_pc_plus4         <= 32'b0;
            idex_a_rs1_data         <= 32'b0;
            idex_a_rs2_data         <= 32'b0;
            idex_a_imm              <= 32'b0;
            idex_a_rs1_addr         <= 5'b0;
            idex_a_rs2_addr         <= 5'b0;
            idex_a_rd_addr          <= 5'b0;
            idex_a_alu_op           <= 5'b0;
            idex_a_alu_src          <= 1'b0;
            idex_a_mem_read         <= 1'b0;
            idex_a_mem_write        <= 1'b0;
            idex_a_mem_funct3       <= 3'b0;
            idex_a_reg_write        <= 1'b0;
            idex_a_wb_sel           <= 2'b0;
            idex_a_branch           <= 1'b0;
            idex_a_jal              <= 1'b0;
            idex_a_jalr             <= 1'b0;
            idex_a_auipc            <= 1'b0;
            idex_a_funct3           <= 3'b0;
            idex_a_ecall            <= 1'b0;
            idex_a_mret             <= 1'b0;
            idex_a_csr_op           <= 1'b0;
            idex_a_csr_rdata        <= 32'b0;
            idex_a_csr_addr         <= 12'b0;
            idex_a_predicted        <= 1'b0;
            idex_a_predicted_target <= 32'b0;
            idex_b_valid            <= 1'b0;
            idex_b_pc               <= 32'b0;
            idex_b_pc_plus4         <= 32'b0;
            idex_b_rs1_data         <= 32'b0;
            idex_b_rs2_data         <= 32'b0;
            idex_b_imm              <= 32'b0;
            idex_b_rs1_addr         <= 5'b0;
            idex_b_rs2_addr         <= 5'b0;
            idex_b_rd_addr          <= 5'b0;
            idex_b_alu_op           <= 5'b0;
            idex_b_alu_src          <= 1'b0;
            idex_b_mem_read         <= 1'b0;
            idex_b_mem_write        <= 1'b0;
            idex_b_mem_funct3       <= 3'b0;
            idex_b_reg_write        <= 1'b0;
            idex_b_wb_sel           <= 2'b0;
            idex_b_auipc            <= 1'b0;
        end else if (hold) begin
            // Multi-cycle EX: retain all values (both pipes)
        end else if (flush) begin
            // Load-use stall or branch flush: insert NOP pair
            idex_a_pc               <= 32'b0;
            idex_a_pc_plus4         <= 32'b0;
            idex_a_rs1_data         <= 32'b0;
            idex_a_rs2_data         <= 32'b0;
            idex_a_imm              <= 32'b0;
            idex_a_rs1_addr         <= 5'b0;
            idex_a_rs2_addr         <= 5'b0;
            idex_a_rd_addr          <= 5'b0;
            idex_a_alu_op           <= 5'b0;
            idex_a_alu_src          <= 1'b0;
            idex_a_mem_read         <= 1'b0;
            idex_a_mem_write        <= 1'b0;
            idex_a_mem_funct3       <= 3'b0;
            idex_a_reg_write        <= 1'b0;
            idex_a_wb_sel           <= 2'b0;
            idex_a_branch           <= 1'b0;
            idex_a_jal              <= 1'b0;
            idex_a_jalr             <= 1'b0;
            idex_a_auipc            <= 1'b0;
            idex_a_funct3           <= 3'b0;
            idex_a_ecall            <= 1'b0;
            idex_a_mret             <= 1'b0;
            idex_a_csr_op           <= 1'b0;
            idex_a_csr_rdata        <= 32'b0;
            idex_a_csr_addr         <= 12'b0;
            idex_a_predicted        <= 1'b0;
            idex_a_predicted_target <= 32'b0;
            idex_b_valid            <= 1'b0;
            idex_b_pc               <= 32'b0;
            idex_b_pc_plus4         <= 32'b0;
            idex_b_rs1_data         <= 32'b0;
            idex_b_rs2_data         <= 32'b0;
            idex_b_imm              <= 32'b0;
            idex_b_rs1_addr         <= 5'b0;
            idex_b_rs2_addr         <= 5'b0;
            idex_b_rd_addr          <= 5'b0;
            idex_b_alu_op           <= 5'b0;
            idex_b_alu_src          <= 1'b0;
            idex_b_mem_read         <= 1'b0;
            idex_b_mem_write        <= 1'b0;
            idex_b_mem_funct3       <= 3'b0;
            idex_b_reg_write        <= 1'b0;
            idex_b_wb_sel           <= 2'b0;
            idex_b_auipc            <= 1'b0;
        end else begin
            // ---- Normal latch ----
            idex_a_pc               <= id_a_pc;
            idex_a_pc_plus4         <= id_a_pc_plus4;
            idex_a_rs1_data         <= id_a_rs1_data;
            idex_a_rs2_data         <= id_a_rs2_data;
            idex_a_imm              <= id_a_imm;
            idex_a_rs1_addr         <= id_a_rs1_addr;
            idex_a_rs2_addr         <= id_a_rs2_addr;
            idex_a_rd_addr          <= id_a_rd_addr;
            idex_a_alu_op           <= id_a_alu_op;
            idex_a_alu_src          <= id_a_alu_src;
            idex_a_mem_read         <= id_a_mem_read;
            idex_a_mem_write        <= id_a_mem_write;
            idex_a_mem_funct3       <= id_a_mem_funct3;
            idex_a_reg_write        <= id_a_reg_write;
            idex_a_wb_sel           <= id_a_wb_sel;
            idex_a_branch           <= id_a_branch;
            idex_a_jal              <= id_a_jal;
            idex_a_jalr             <= id_a_jalr;
            idex_a_auipc            <= id_a_auipc;
            idex_a_funct3           <= id_a_funct3;
            idex_a_ecall            <= id_a_ecall;
            idex_a_mret             <= id_a_mret;
            idex_a_csr_op           <= id_a_csr_op;
            idex_a_csr_rdata        <= id_a_csr_rdata;
            idex_a_csr_addr         <= id_a_csr_addr;
            idex_a_predicted        <= id_a_predicted;
            idex_a_predicted_target <= id_a_predicted_target;
            idex_b_valid            <= id_b_valid;
            idex_b_pc               <= id_b_pc;
            idex_b_pc_plus4         <= id_b_pc_plus4;
            idex_b_rs1_data         <= id_b_rs1_data;
            idex_b_rs2_data         <= id_b_rs2_data;
            idex_b_imm              <= id_b_imm;
            idex_b_rs1_addr         <= id_b_rs1_addr;
            idex_b_rs2_addr         <= id_b_rs2_addr;
            idex_b_rd_addr          <= id_b_rd_addr;
            idex_b_alu_op           <= id_b_alu_op;
            idex_b_alu_src          <= id_b_alu_src;
            idex_b_mem_read         <= id_b_mem_read;
            idex_b_mem_write        <= id_b_mem_write;
            idex_b_mem_funct3       <= id_b_mem_funct3;
            idex_b_reg_write        <= id_b_reg_write;
            idex_b_wb_sel           <= id_b_wb_sel;
            idex_b_auipc            <= id_b_auipc;
        end
    end

endmodule
