`timescale 1ns / 1ps
// =============================================================================
// student_top.sv
//
// Competition top-level wrapper that connects the RISC-V 5-stage pipeline SoC
// to the virtual-I/O platform provided by the organisers.
//
// Virtual I/O mapping
// -------------------
//  virtual_sw[31: 0]  →  gpio_in  (switches as CPU general-purpose inputs)
//  virtual_sw[63:32]  →  value shown on the 7-segment display (raw hex)
//  virtual_key[ 7: 0] →  unused (exposed on decimal-point bits of each digit)
//  gpio_out[31: 0]    →  virtual_led[31:0]
//  seg_display[31: 0] →  driven to the on-board 7-segment display driver
//
// Reset polarity
// --------------
//  w_clk_rst inside student_top is ACTIVE-HIGH  (= ~PLL_locked from top.sv).
//  Our SoC uses active-LOW rst_n, so connect rst_n = ~w_clk_rst.
// =============================================================================

module student_top #(
    parameter                       P_SW_CNT  = 64,
    parameter                       P_LED_CNT = 32,
    parameter                       P_SEG_CNT = 40,
    parameter                       P_KEY_CNT = 8
) (
    input                                   w_clk_50Mhz,
    input                                   w_clk_rst,      // active-HIGH reset
    input  [P_KEY_CNT - 1 : 0]             virtual_key,
    input  [P_SW_CNT  - 1 : 0]             virtual_sw,

    output [P_LED_CNT - 1 : 0]             virtual_led,
    output [P_SEG_CNT - 1 : 0]             virtual_seg
);

    // -------------------------------------------------------------------------
    // Internal signals
    // -------------------------------------------------------------------------
    wire        clk   = w_clk_50Mhz;
    wire        rst_n = ~w_clk_rst;        // convert to active-LOW

    wire [31:0] gpio_out;
    wire [31:0] gpio_in;
    wire [31:0] seg_display;
    wire        uart_tx;
    wire [ 7:0] leds;

    // Switches drive gpio_in; upper 32 switch bits go to the segment display
    assign gpio_in = virtual_sw[31:0];

    // -------------------------------------------------------------------------
    // RISC-V SoC (CPU + memory + peripherals)
    // INIT_FILE: set to the program hex file for FPGA synthesis.
    // -------------------------------------------------------------------------
    riscv_soc #(
        .INIT_FILE ("program.hex")
    ) u_soc (
        .clk         (clk),
        .rst_n       (rst_n),
        .gpio_out    (gpio_out),
        .gpio_in     (gpio_in),
        .seg_display (seg_display),
        .uart_tx     (uart_tx),
        .uart_rx     (1'b1),        // UART RX tied idle
        .leds        (leds)
    );

    // -------------------------------------------------------------------------
    // LED output – map gpio_out to virtual_led
    // -------------------------------------------------------------------------
    assign virtual_led = gpio_out;

    // -------------------------------------------------------------------------
    // Seven-segment display driver
    //
    // The platform encodes virtual_seg[39:0] as four 10-bit groups:
    //   bits [6:0]   – 7-segment data for digit N
    //   bit  [7]     – decimal point (we wire to virtual_key[N])
    //   bits [9:8]   – digit-select (ans) bits, driven by display_seg
    //
    // We show the lower 32 bits of seg_display on the four hex digits.
    // -------------------------------------------------------------------------
    display_seg seg_driver (
        .clk  (clk),
        .rst  (w_clk_rst),              // display_seg uses active-HIGH reset
        .s    (seg_display),            // 32-bit value from SoC
        .seg1 (virtual_seg[6:0]),
        .seg2 (virtual_seg[16:10]),
        .seg3 (virtual_seg[26:20]),
        .seg4 (virtual_seg[36:30]),
        .ans  ({virtual_seg[39:38], virtual_seg[29:28],
                virtual_seg[19:18], virtual_seg[9:8]})
    );

    // Decimal-point bits carry key state (matches template convention)
    assign virtual_seg[7]  = virtual_key[0];
    assign virtual_seg[17] = virtual_key[1];
    assign virtual_seg[27] = virtual_key[2];
    assign virtual_seg[37] = virtual_key[3];

endmodule
