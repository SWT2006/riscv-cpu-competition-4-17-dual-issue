`timescale 1ns/1ps
// 2-wide load-use hazard detection.
//
// Checks if either EX pipe (A or B) has a load whose destination register
// is read by either ID slot (A or B).  When detected, the pipeline stalls
// for one cycle so forwarding from MEM/WB can supply the loaded value.
//
// With 2-wide issue, there are 4 potential hazard pairs:
//   EX pipe A load → ID slot A source
//   EX pipe A load → ID slot B source
//   EX pipe B load → ID slot A source
//   EX pipe B load → ID slot B source
module hazard_unit (
    // EX pipe A
    input  wire        idex_a_mem_read,
    input  wire [4:0]  idex_a_rd_addr,
    // EX pipe B
    input  wire        idex_b_valid,
    input  wire        idex_b_mem_read,
    input  wire [4:0]  idex_b_rd_addr,
    // ID slot A sources (from IF/ID instruction bits)
    input  wire [4:0]  ifid_a_rs1_addr,
    input  wire [4:0]  ifid_a_rs2_addr,
    // ID slot B sources
    input  wire        ifid_b_valid,
    input  wire [4:0]  ifid_b_rs1_addr,
    input  wire [4:0]  ifid_b_rs2_addr,
    // Output
    output wire        stall
);

    // EX pipe A load hazard against ID slot A
    wire hz_a_a = idex_a_mem_read
               && (idex_a_rd_addr != 5'b0)
               && ((idex_a_rd_addr == ifid_a_rs1_addr) || (idex_a_rd_addr == ifid_a_rs2_addr));

    // EX pipe A load hazard against ID slot B
    wire hz_a_b = idex_a_mem_read && ifid_b_valid
               && (idex_a_rd_addr != 5'b0)
               && ((idex_a_rd_addr == ifid_b_rs1_addr) || (idex_a_rd_addr == ifid_b_rs2_addr));

    // EX pipe B load hazard against ID slot A
    wire hz_b_a = idex_b_valid && idex_b_mem_read
               && (idex_b_rd_addr != 5'b0)
               && ((idex_b_rd_addr == ifid_a_rs1_addr) || (idex_b_rd_addr == ifid_a_rs2_addr));

    // EX pipe B load hazard against ID slot B
    wire hz_b_b = idex_b_valid && idex_b_mem_read && ifid_b_valid
               && (idex_b_rd_addr != 5'b0)
               && ((idex_b_rd_addr == ifid_b_rs1_addr) || (idex_b_rd_addr == ifid_b_rs2_addr));

    assign stall = hz_a_a | hz_a_b | hz_b_a | hz_b_b;

endmodule
