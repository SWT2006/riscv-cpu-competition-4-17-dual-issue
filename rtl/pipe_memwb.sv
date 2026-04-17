`timescale 1ns/1ps
// 2-wide MEM/WB pipeline register.
//
// Pre-computes writeback data for both pipes (removes 3:1 mux from
// WB→ID bypass and WB→EX forwarding critical paths).
module pipe_memwb (
    input  wire        clk,
    input  wire        cpu_rst,
    // ---- Pipe A inputs ----
    input  wire [31:0] mem_a_pc_plus4,
    input  wire [31:0] mem_a_alu_result,
    input  wire [31:0] mem_a_read_data,
    input  wire [4:0]  mem_a_rd_addr,
    input  wire        mem_a_reg_write,
    input  wire [1:0]  mem_a_wb_sel,
    // ---- Pipe B inputs ----
    input  wire        mem_b_valid,
    input  wire [31:0] mem_b_pc_plus4,
    input  wire [31:0] mem_b_alu_result,
    input  wire [31:0] mem_b_read_data,
    input  wire [4:0]  mem_b_rd_addr,
    input  wire        mem_b_reg_write,
    input  wire [1:0]  mem_b_wb_sel,
    // ---- Pipe A outputs ----
    output reg  [4:0]  memwb_a_rd_addr,
    output reg         memwb_a_reg_write,
    output reg  [31:0] memwb_a_write_data,
    // ---- Pipe B outputs ----
    output reg         memwb_b_valid,
    output reg  [4:0]  memwb_b_rd_addr,
    output reg         memwb_b_reg_write,
    output reg  [31:0] memwb_b_write_data
);

    always @(posedge clk) begin
        if (cpu_rst) begin
            memwb_a_rd_addr    <= 5'b0;
            memwb_a_reg_write  <= 1'b0;
            memwb_a_write_data <= 32'b0;
            memwb_b_valid      <= 1'b0;
            memwb_b_rd_addr    <= 5'b0;
            memwb_b_reg_write  <= 1'b0;
            memwb_b_write_data <= 32'b0;
        end else begin
            // Pipe A
            memwb_a_rd_addr    <= mem_a_rd_addr;
            memwb_a_reg_write  <= mem_a_reg_write;
            memwb_a_write_data <= (mem_a_wb_sel == 2'b01) ? mem_a_read_data :
                                  (mem_a_wb_sel == 2'b10) ? mem_a_pc_plus4  :
                                                            mem_a_alu_result;
            // Pipe B
            memwb_b_valid      <= mem_b_valid;
            memwb_b_rd_addr    <= mem_b_valid ? mem_b_rd_addr   : 5'b0;
            memwb_b_reg_write  <= mem_b_valid ? mem_b_reg_write : 1'b0;
            memwb_b_write_data <= mem_b_valid ?
                                  ((mem_b_wb_sel == 2'b01) ? mem_b_read_data :
                                   (mem_b_wb_sel == 2'b10) ? mem_b_pc_plus4  :
                                                             mem_b_alu_result)
                                  : 32'b0;
        end
    end

endmodule
