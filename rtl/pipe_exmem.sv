`timescale 1ns/1ps
// 2-wide EX/MEM pipeline register.
//
// flush_all: zeros both pipes (multi-cycle EX stall — prevent false writes)
// flush_b:   zeros pipe B only (branch mispredict — pipe A is the branch
//            instruction itself and is correct; pipe B is on wrong path)
//
// Pre-computed forwarding data for each pipe (saves 1 mux level):
//   fwd_data = (wb_sel == 2'b10) ? pc_plus4 : alu_result
module pipe_exmem (
    input  wire        clk,
    input  wire        cpu_rst,
    input  wire        flush_all,    // ex_stall: zero both pipes
    input  wire        flush_b,      // branch mispredict: zero pipe B only
    // ---- Pipe A inputs ----
    input  wire [31:0] ex_a_pc_plus4,
    input  wire [31:0] ex_a_alu_result,
    input  wire [31:0] ex_a_rs2_data,
    input  wire [4:0]  ex_a_rd_addr,
    input  wire        ex_a_mem_read,
    input  wire        ex_a_mem_write,
    input  wire [2:0]  ex_a_mem_funct3,
    input  wire        ex_a_reg_write,
    input  wire [1:0]  ex_a_wb_sel,
    // ---- Pipe B inputs ----
    input  wire        ex_b_valid,
    input  wire [31:0] ex_b_pc_plus4,
    input  wire [31:0] ex_b_alu_result,
    input  wire [31:0] ex_b_rs2_data,
    input  wire [4:0]  ex_b_rd_addr,
    input  wire        ex_b_mem_read,
    input  wire        ex_b_mem_write,
    input  wire [2:0]  ex_b_mem_funct3,
    input  wire        ex_b_reg_write,
    input  wire [1:0]  ex_b_wb_sel,
    // ---- Pipe A outputs ----
    output reg  [31:0] exmem_a_pc_plus4,
    output reg  [31:0] exmem_a_alu_result,
    output reg  [31:0] exmem_a_rs2_data,
    output reg  [4:0]  exmem_a_rd_addr,
    output reg         exmem_a_mem_read,
    output reg         exmem_a_mem_write,
    output reg  [2:0]  exmem_a_mem_funct3,
    output reg         exmem_a_reg_write,
    output reg  [1:0]  exmem_a_wb_sel,
    output reg  [31:0] exmem_a_fwd_data,
    // ---- Pipe B outputs ----
    output reg         exmem_b_valid,
    output reg  [31:0] exmem_b_pc_plus4,
    output reg  [31:0] exmem_b_alu_result,
    output reg  [31:0] exmem_b_rs2_data,
    output reg  [4:0]  exmem_b_rd_addr,
    output reg         exmem_b_mem_read,
    output reg         exmem_b_mem_write,
    output reg  [2:0]  exmem_b_mem_funct3,
    output reg         exmem_b_reg_write,
    output reg  [1:0]  exmem_b_wb_sel,
    output reg  [31:0] exmem_b_fwd_data
);

    always @(posedge clk) begin
        if (cpu_rst || flush_all) begin
            // Zero everything (both pipes)
            exmem_a_pc_plus4   <= 32'b0;
            exmem_a_alu_result <= 32'b0;
            exmem_a_rs2_data   <= 32'b0;
            exmem_a_rd_addr    <= 5'b0;
            exmem_a_mem_read   <= 1'b0;
            exmem_a_mem_write  <= 1'b0;
            exmem_a_mem_funct3 <= 3'b0;
            exmem_a_reg_write  <= 1'b0;
            exmem_a_wb_sel     <= 2'b0;
            exmem_a_fwd_data   <= 32'b0;
            exmem_b_valid      <= 1'b0;
            exmem_b_pc_plus4   <= 32'b0;
            exmem_b_alu_result <= 32'b0;
            exmem_b_rs2_data   <= 32'b0;
            exmem_b_rd_addr    <= 5'b0;
            exmem_b_mem_read   <= 1'b0;
            exmem_b_mem_write  <= 1'b0;
            exmem_b_mem_funct3 <= 3'b0;
            exmem_b_reg_write  <= 1'b0;
            exmem_b_wb_sel     <= 2'b0;
            exmem_b_fwd_data   <= 32'b0;
        end else begin
            // Pipe A: always latch
            exmem_a_pc_plus4   <= ex_a_pc_plus4;
            exmem_a_alu_result <= ex_a_alu_result;
            exmem_a_rs2_data   <= ex_a_rs2_data;
            exmem_a_rd_addr    <= ex_a_rd_addr;
            exmem_a_mem_read   <= ex_a_mem_read;
            exmem_a_mem_write  <= ex_a_mem_write;
            exmem_a_mem_funct3 <= ex_a_mem_funct3;
            exmem_a_reg_write  <= ex_a_reg_write;
            exmem_a_wb_sel     <= ex_a_wb_sel;
            exmem_a_fwd_data   <= (ex_a_wb_sel == 2'b10) ? ex_a_pc_plus4
                                                          : ex_a_alu_result;

            // Pipe B: zero on flush_b (mispredict), otherwise latch
            if (flush_b || !ex_b_valid) begin
                exmem_b_valid      <= 1'b0;
                exmem_b_pc_plus4   <= 32'b0;
                exmem_b_alu_result <= 32'b0;
                exmem_b_rs2_data   <= 32'b0;
                exmem_b_rd_addr    <= 5'b0;
                exmem_b_mem_read   <= 1'b0;
                exmem_b_mem_write  <= 1'b0;
                exmem_b_mem_funct3 <= 3'b0;
                exmem_b_reg_write  <= 1'b0;
                exmem_b_wb_sel     <= 2'b0;
                exmem_b_fwd_data   <= 32'b0;
            end else begin
                exmem_b_valid      <= 1'b1;
                exmem_b_pc_plus4   <= ex_b_pc_plus4;
                exmem_b_alu_result <= ex_b_alu_result;
                exmem_b_rs2_data   <= ex_b_rs2_data;
                exmem_b_rd_addr    <= ex_b_rd_addr;
                exmem_b_mem_read   <= ex_b_mem_read;
                exmem_b_mem_write  <= ex_b_mem_write;
                exmem_b_mem_funct3 <= ex_b_mem_funct3;
                exmem_b_reg_write  <= ex_b_reg_write;
                exmem_b_wb_sel     <= ex_b_wb_sel;
                exmem_b_fwd_data   <= (ex_b_wb_sel == 2'b10) ? ex_b_pc_plus4
                                                              : ex_b_alu_result;
            end
        end
    end

endmodule
