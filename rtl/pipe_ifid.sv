`timescale 1ns/1ps
// 2-wide IF/ID pipeline register.
// Carries two instruction slots (A and B) with a validity flag for slot B.
// stall: hold all outputs (pipeline stall)
// flush: inject NOP pair (branch mispredict recovery)
module pipe_ifid (
    input  wire        clk,
    input  wire        cpu_rst,
    input  wire        stall,
    input  wire        flush,
    // Slot A inputs (always valid)
    input  wire [31:0] if_pc_a,
    input  wire [31:0] if_pc_a_plus4,
    input  wire [31:0] if_inst_a,
    input  wire        if_predicted_a,
    input  wire [31:0] if_predicted_target_a,
    // Slot B inputs
    input  wire [31:0] if_pc_b,
    input  wire [31:0] if_pc_b_plus4,
    input  wire [31:0] if_inst_b,
    input  wire        if_b_valid,
    input  wire        if_predicted_b,
    input  wire [31:0] if_predicted_target_b,
    // Slot A outputs
    output reg  [31:0] ifid_pc_a,
    output reg  [31:0] ifid_pc_a_plus4,
    output reg  [31:0] ifid_inst_a,
    output reg         ifid_predicted_a,
    output reg  [31:0] ifid_predicted_target_a,
    // Slot B outputs
    output reg  [31:0] ifid_pc_b,
    output reg  [31:0] ifid_pc_b_plus4,
    output reg  [31:0] ifid_inst_b,
    output reg         ifid_b_valid,
    output reg         ifid_predicted_b,
    output reg  [31:0] ifid_predicted_target_b
);
    always @(posedge clk) begin
        if (cpu_rst || flush) begin
            // NOP pair
            ifid_pc_a               <= 32'b0;
            ifid_pc_a_plus4         <= 32'b0;
            ifid_inst_a             <= 32'h0000_0013; // NOP = ADDI x0,x0,0
            ifid_predicted_a        <= 1'b0;
            ifid_predicted_target_a <= 32'b0;
            ifid_pc_b               <= 32'b0;
            ifid_pc_b_plus4         <= 32'b0;
            ifid_inst_b             <= 32'h0000_0013;
            ifid_b_valid            <= 1'b0;
            ifid_predicted_b        <= 1'b0;
            ifid_predicted_target_b <= 32'b0;
        end else if (!stall) begin
            ifid_pc_a               <= if_pc_a;
            ifid_pc_a_plus4         <= if_pc_a_plus4;
            ifid_inst_a             <= if_inst_a;
            ifid_predicted_a        <= if_predicted_a;
            ifid_predicted_target_a <= if_predicted_target_a;
            ifid_pc_b               <= if_pc_b;
            ifid_pc_b_plus4         <= if_pc_b_plus4;
            ifid_inst_b             <= if_inst_b;
            ifid_b_valid            <= if_b_valid;
            ifid_predicted_b        <= if_predicted_b;
            ifid_predicted_target_b <= if_predicted_target_b;
        end
        // stall && !flush: hold outputs
    end
endmodule
