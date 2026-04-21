`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/16/2025 06:21:13 PM
// Design Name: 
// Module Name: student_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module student_top#(
    parameter                           P_SW_CNT            = 64,
    parameter                           P_LED_CNT           = 32,
    parameter                           P_SEG_CNT           = 40,
    parameter                           P_KEY_CNT           = 8
) (
    input                                       w_cpu_clk     ,
    input                                       w_clk_50Mhz   ,
    input                                       w_clk_rst     ,
    input  [P_KEY_CNT - 1:0]                    virtual_key   ,
    input  [P_SW_CNT  - 1:0]                    virtual_sw    ,

    output [P_LED_CNT - 1:0]                    virtual_led   ,
    output [P_SEG_CNT - 1:0]                    virtual_seg   
);

    // IROM — 2-wide fetch for dual-issue pipeline
    logic [31:0] pc;
    logic [11:0] inst_addr;
    logic [31:0] instruction_0;    // slot A: instruction at PC
    logic [31:0] instruction_1;    // slot B: instruction at PC+4

    // perip
    logic [31:0] perip_addr, perip_wdata, perip_rdata;
    logic perip_wen;
    logic [1:0] perip_mask;
    logic [31:0] dram_raddr;

    // 16KB = 2^12 * 32bit
    assign inst_addr = pc[13:2];

    myCPU Core_cpu (
        .cpu_rst            (w_clk_rst),
        .cpu_clk            (w_cpu_clk),

        // Interface to IROM — 2-wide fetch
        .irom_addr          (pc),
        .irom_data_0        (instruction_0),
        .irom_data_1        (instruction_1),

        // Interface to DRAM & periphera
        .perip_addr         (perip_addr),
        .perip_wen          (perip_wen),
        .perip_mask         (perip_mask),
        .perip_wdata        (perip_wdata),
        .perip_rdata        (perip_rdata),
        .dram_raddr         (dram_raddr)
    );

    // Block-RAM IROM with dual read ports (replaces single-port Xilinx IP)
    irom_driver Mem_IROM (
        .clk        (w_cpu_clk),
        .addr       (inst_addr),
        .rdata_0    (instruction_0),
        .rdata_1    (instruction_1)
    );
    
    perip_bridge bridge_inst (
        .clk				(w_cpu_clk),
        .cnt_clk            (w_clk_50Mhz),
        .rst                (w_clk_rst),
        .perip_addr			(perip_addr),
        .perip_wdata		(perip_wdata),
        .perip_wen			(perip_wen),
        .perip_mask			(perip_mask),
        .perip_rdata		(perip_rdata),
        .dram_raddr         (dram_raddr),
        .virtual_sw_input	(virtual_sw),
        .virtual_key_input	(virtual_key),
        .virtual_seg_output	(virtual_seg),
        .virtual_led_output (virtual_led)
    );

endmodule
