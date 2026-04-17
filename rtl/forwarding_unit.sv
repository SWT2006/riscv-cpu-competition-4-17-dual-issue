`timescale 1ns/1ps
// 2-wide data forwarding unit.
//
// Provides forwarding select signals for 4 operand sinks:
//   Pipe A: rs1_a, rs2_a
//   Pipe B: rs1_b, rs2_b
//
// Forwarding sources (4 sources, priority order):
//   3'b100 = exmem pipe B  (most recent, later in program order)
//   3'b011 = exmem pipe A  (most recent, earlier in program order)
//   3'b010 = memwb pipe B  (2nd most recent, later)
//   3'b001 = memwb pipe A  (2nd most recent, earlier)
//   3'b000 = no forwarding (use register file value)
//
// Within the same pipeline stage, pipe B has priority over pipe A because
// B is later in program order and its value shadows A's if both write the
// same register.
module forwarding_unit (
    // EX-stage source addresses
    input  wire [4:0] idex_a_rs1_addr,
    input  wire [4:0] idex_a_rs2_addr,
    input  wire [4:0] idex_b_rs1_addr,
    input  wire [4:0] idex_b_rs2_addr,
    input  wire       idex_b_valid,
    // EX/MEM forwarding sources
    input  wire [4:0] exmem_a_rd_addr,
    input  wire       exmem_a_reg_write,
    input  wire [4:0] exmem_b_rd_addr,
    input  wire       exmem_b_reg_write,
    input  wire       exmem_b_valid,
    // MEM/WB forwarding sources
    input  wire [4:0] memwb_a_rd_addr,
    input  wire       memwb_a_reg_write,
    input  wire [4:0] memwb_b_rd_addr,
    input  wire       memwb_b_reg_write,
    input  wire       memwb_b_valid,
    // Forwarding select outputs (3-bit encoding)
    output reg  [2:0] fwd_a_rs1,
    output reg  [2:0] fwd_a_rs2,
    output reg  [2:0] fwd_b_rs1,
    output reg  [2:0] fwd_b_rs2
);

    // Encoding constants
    localparam FWD_NONE     = 3'b000;
    localparam FWD_MEMWB_A  = 3'b001;
    localparam FWD_MEMWB_B  = 3'b010;
    localparam FWD_EXMEM_A  = 3'b011;
    localparam FWD_EXMEM_B  = 3'b100;

    // ---------------------------------------------------------------
    // Forwarding select for each operand — explicit always blocks
    // (avoids iverilog function evaluation order issues)
    // ---------------------------------------------------------------
    always @(*) begin
        if (exmem_b_valid && exmem_b_reg_write && exmem_b_rd_addr != 5'b0 && exmem_b_rd_addr == idex_a_rs1_addr)
            fwd_a_rs1 = FWD_EXMEM_B;
        else if (exmem_a_reg_write && exmem_a_rd_addr != 5'b0 && exmem_a_rd_addr == idex_a_rs1_addr)
            fwd_a_rs1 = FWD_EXMEM_A;
        else if (memwb_b_valid && memwb_b_reg_write && memwb_b_rd_addr != 5'b0 && memwb_b_rd_addr == idex_a_rs1_addr)
            fwd_a_rs1 = FWD_MEMWB_B;
        else if (memwb_a_reg_write && memwb_a_rd_addr != 5'b0 && memwb_a_rd_addr == idex_a_rs1_addr)
            fwd_a_rs1 = FWD_MEMWB_A;
        else
            fwd_a_rs1 = FWD_NONE;
    end

    always @(*) begin
        if (exmem_b_valid && exmem_b_reg_write && exmem_b_rd_addr != 5'b0 && exmem_b_rd_addr == idex_a_rs2_addr)
            fwd_a_rs2 = FWD_EXMEM_B;
        else if (exmem_a_reg_write && exmem_a_rd_addr != 5'b0 && exmem_a_rd_addr == idex_a_rs2_addr)
            fwd_a_rs2 = FWD_EXMEM_A;
        else if (memwb_b_valid && memwb_b_reg_write && memwb_b_rd_addr != 5'b0 && memwb_b_rd_addr == idex_a_rs2_addr)
            fwd_a_rs2 = FWD_MEMWB_B;
        else if (memwb_a_reg_write && memwb_a_rd_addr != 5'b0 && memwb_a_rd_addr == idex_a_rs2_addr)
            fwd_a_rs2 = FWD_MEMWB_A;
        else
            fwd_a_rs2 = FWD_NONE;
    end

    always @(*) begin
        if (exmem_b_valid && exmem_b_reg_write && exmem_b_rd_addr != 5'b0 && exmem_b_rd_addr == idex_b_rs1_addr)
            fwd_b_rs1 = FWD_EXMEM_B;
        else if (exmem_a_reg_write && exmem_a_rd_addr != 5'b0 && exmem_a_rd_addr == idex_b_rs1_addr)
            fwd_b_rs1 = FWD_EXMEM_A;
        else if (memwb_b_valid && memwb_b_reg_write && memwb_b_rd_addr != 5'b0 && memwb_b_rd_addr == idex_b_rs1_addr)
            fwd_b_rs1 = FWD_MEMWB_B;
        else if (memwb_a_reg_write && memwb_a_rd_addr != 5'b0 && memwb_a_rd_addr == idex_b_rs1_addr)
            fwd_b_rs1 = FWD_MEMWB_A;
        else
            fwd_b_rs1 = FWD_NONE;
    end

    always @(*) begin
        if (exmem_b_valid && exmem_b_reg_write && exmem_b_rd_addr != 5'b0 && exmem_b_rd_addr == idex_b_rs2_addr)
            fwd_b_rs2 = FWD_EXMEM_B;
        else if (exmem_a_reg_write && exmem_a_rd_addr != 5'b0 && exmem_a_rd_addr == idex_b_rs2_addr)
            fwd_b_rs2 = FWD_EXMEM_A;
        else if (memwb_b_valid && memwb_b_reg_write && memwb_b_rd_addr != 5'b0 && memwb_b_rd_addr == idex_b_rs2_addr)
            fwd_b_rs2 = FWD_MEMWB_B;
        else if (memwb_a_reg_write && memwb_a_rd_addr != 5'b0 && memwb_a_rd_addr == idex_b_rs2_addr)
            fwd_b_rs2 = FWD_MEMWB_A;
        else
            fwd_b_rs2 = FWD_NONE;
    end

endmodule
