`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2025/04/22 10:25:24
// Design Name: 
// Module Name: perip_bridge
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

module perip_bridge(
    input  logic         clk				,
    input  logic         cnt_clk			,
    input  logic         rst                ,

    input  logic [31:0]  perip_addr			,
    input  logic [31:0]  perip_wdata		,
    input  logic         perip_wen			,
	input  logic [1:0]	 perip_mask			,
    output logic [31:0]  perip_rdata		,

    input  logic [63:0]  virtual_sw_input	,
    input  logic [7:0]   virtual_key_input	,	

	output logic [39:0]  virtual_seg_output	,
    output logic [31:0]  virtual_led_output
);
    localparam DRAM_ADDR_START = 32'h8010_0000;
    localparam DRAM_ADDR_END   = 32'h8013_FFFF;
    localparam SW0_ADDR  = 32'h8020_0000;  // sw[31:0]
    localparam SW1_ADDR  = 32'h8020_0004;  // sw[63:32]
    localparam KEY_ADDR  = 32'h8020_0010;  // key[7:0]
    localparam SEG_ADDR  = 32'h8020_0020;  // seg
    localparam LED_ADDR  = 32'h8020_0040;  // led[31:0]
    localparam CNT_ADDR  = 32'h8020_0050;  // counter
    localparam CNT_START_CMD = 32'h8000_0000;
    localparam CNT_STOP_CMD  = 32'hFFFF_FFFF;

    logic [31:0] LED;
    logic [31:0] seg_wdata, cnt_rdata, dram_rdata;
    logic [39:0] seg_output;
    logic cnt_enable_cfg;

    // ---- Address decode ----
    // DRAM: 0x80100000–0x8013FFFF ⇒ addr[31:18] == 14'h2004
    // Single 14-bit compare instead of two 32-bit >= / < comparisons.
    wire dram_sel = (perip_addr[31:18] == 14'h2004);
    // MMIO: 0x802000xx ⇒ addr[31:8] == 24'h802000
    wire mmio_sel = (perip_addr[31:8] == 24'h802000);

    // write process
    always_ff @(posedge clk) begin
        if (rst) begin
            LED            <= 32'd0;
            seg_wdata      <= 32'd0;
            cnt_enable_cfg <= 1'b0;
        end else if (perip_wen & mmio_sel) begin
            case (perip_addr[7:0])
                8'h40:   LED <= perip_wdata;
                8'h20:   seg_wdata <= perip_wdata;
                8'h50: begin
                    if (perip_wdata == CNT_START_CMD)
                        cnt_enable_cfg <= 1'b1;
                    else if (perip_wdata == CNT_STOP_CMD)
                        cnt_enable_cfg <= 1'b0;
                end
            endcase
        end
    end

    // seg driver
    display_seg seg_driver (
        .clk    (clk),
        .rst    (rst),
        .s      (seg_wdata),
        .seg1   (seg_output[6:0]),
        .seg2   (seg_output[16:10]),
        .seg3   (seg_output[26:20]),
        .seg4   (seg_output[36:30]),
        .ans    ({seg_output[39:38], seg_output[29:28], seg_output[19:18], seg_output[9:8]})
    ); 
   
    assign seg_output[7]  = 0;
    assign seg_output[17] = 0;
    assign seg_output[27] = 0;
    assign seg_output[37] = 0;
    

    // dram rw — use pre-decoded dram_sel instead of inline range comparison
    dram_driver dram_driver_inst (
        .clk				(clk),
        .perip_addr			(perip_addr[17:0]),
        .perip_wdata		(perip_wdata),
        .perip_mask			(perip_mask),
        .dram_wen 			(perip_wen & dram_sel),
        .perip_rdata		(dram_rdata)
    );

    // counter rw
    counter counter_inst (
        .cpu_clk            (clk),
        .cnt_clk            (cnt_clk),
        .rst                (rst),
        .cnt_enable_cpu     (cnt_enable_cfg),
        .perip_rdata		(cnt_rdata)
    );

    // Read data mux: priority DRAM → MMIO → CNT
    // Single mux tree instead of 6 parallel AND-OR terms with full-width
    // address comparators.  DRAM is the hot path; MMIO/CNT are rare reads.
    always_comb begin
        if (dram_sel)
            perip_rdata = dram_rdata;
        else if (mmio_sel) begin
            case (perip_addr[7:0])
                8'h00:   perip_rdata = virtual_sw_input[31:0];
                8'h04:   perip_rdata = virtual_sw_input[63:32];
                8'h10:   perip_rdata = {24'd0, virtual_key_input};
                8'h20:   perip_rdata = seg_wdata;
                8'h50:   perip_rdata = cnt_rdata;
                default: perip_rdata = 32'h0;
            endcase
        end else
            perip_rdata = 32'h0;
    end
    
    assign virtual_led_output = LED;
    assign virtual_seg_output = seg_output;

endmodule
