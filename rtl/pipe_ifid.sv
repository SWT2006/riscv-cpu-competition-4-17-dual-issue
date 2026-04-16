`timescale 1ns/1ps
// IF/ID pipeline register.
// stall: hold outputs (load-use hazard, PC is also stalled)
// flush: inject NOP (branch taken / mispredict recovery)
// if_predicted:        carries the IF-stage prediction flag into the pipeline.
// if_predicted_target: carries the predicted next-PC for EX target verification.
module pipe_ifid (
    input  wire        clk,
    input  wire        cpu_rst,
    input  wire        stall,
    input  wire        flush,
    input  wire [31:0] if_pc,
    input  wire [31:0] if_pc_plus4,
    input  wire [31:0] if_instruction,
    input  wire        if_predicted,
    input  wire [31:0] if_predicted_target,
    output reg  [31:0] ifid_pc,
    output reg  [31:0] ifid_pc_plus4,
    output reg  [31:0] ifid_instruction,
    output reg         ifid_predicted,
    output reg  [31:0] ifid_predicted_target
);
    always @(posedge clk) begin
        if (cpu_rst || flush) begin
            ifid_pc               <= 32'b0;
            ifid_pc_plus4         <= 32'b0;
            ifid_instruction      <= 32'h0000_0013; // NOP = ADDI x0,x0,0
            ifid_predicted        <= 1'b0;
            ifid_predicted_target <= 32'b0;
        end else if (!stall) begin
            ifid_pc               <= if_pc;
            ifid_pc_plus4         <= if_pc_plus4;
            ifid_instruction      <= if_instruction;
            ifid_predicted        <= if_predicted;
            ifid_predicted_target <= if_predicted_target;
        end
        // stall && !flush: outputs hold (no else branch needed)
    end
endmodule
