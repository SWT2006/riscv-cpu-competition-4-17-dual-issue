`timescale 1ns/1ps
// =============================================================================
// Testbench for RISC-V 5-stage pipeline CPU – ISA regression tests
//
// Pass/fail detection:
//   The riscv-tests ISA suite signals result by writing:
//     s10 (x26) = 1  in both pass and fail paths
//     s11 (x27) = 1  → PASS
//     s11 (x27) = 0  → FAIL
//
// Memory initialisation:
//   inst.data is loaded (by BinToMem_CLI.py) before simulation starts.
//   The same image is loaded into BOTH instruction memory and data memory
//   because the ISA tests embed their .data section in the same flat binary
//   (lw/sw tests use PC-relative addressing into the .data section).
// =============================================================================

module tinyriscv_soc_tb;

    // -------------------------------------------------------------------------
    // Clock / reset
    // -------------------------------------------------------------------------
    reg clk;
    reg rst_n;

    // Clock: 50 MHz (20 ns period)
    initial clk = 0;
    always  #10 clk = ~clk;

    // Reset: assert for 10 cycles (200 ns), then release
    initial begin
        rst_n = 1'b0;
        #200;
        rst_n = 1'b1;
    end

    // -------------------------------------------------------------------------
    // DUT – SoC wrapper
    // -------------------------------------------------------------------------
    wire [31:0] gpio_out;
    wire [31:0] gpio_in;
    wire [31:0] seg_display;
    wire        uart_tx;
    wire [ 7:0] leds;

    assign gpio_in = 32'b0;

    riscv_soc u_soc (
        .clk         (clk),
        .rst_n       (rst_n),
        .gpio_out    (gpio_out),
        .gpio_in     (gpio_in),
        .seg_display (seg_display),
        .uart_tx     (uart_tx),
        .uart_rx     (1'b1),
        .leds        (leds)
    );

    // -------------------------------------------------------------------------
    // Load test program into instruction memory AND data memory.
    //
    // inst.data is produced by BinToMem_CLI.py from the raw .bin test binary.
    // It contains one little-endian 32-bit word per line covering the entire
    // flat binary image (code + padding + .data section).
    //
    // A small #1 delay ensures this load happens AFTER any initial $readmemh
    // calls inside the RTL modules (instruction memory default file).
    // -------------------------------------------------------------------------
    initial begin
        #1;
        $readmemh("inst.data", u_soc.u_imem.mem);
        $readmemh("inst.data", u_soc.u_dmem.mem);
    end

    // -------------------------------------------------------------------------
    // Pass / fail monitoring
    //
    // Poll the register file every clock cycle after reset is released.
    // x26 (s10) = 1 signals test completion.
    // x27 (s11) = 1 → TEST_PASS,  = 0 → TEST_FAIL.
    //
    // Timing note: in the RISC-V test suite pass path the sequence is:
    //   addi x26, x0, 1   (x26 becomes 1)
    //   addi x27, x0, 1   (x27 becomes 1 one cycle later in WB)
    // We wait 10 extra cycles after first seeing x26=1 before reading x27
    // to ensure x27 has fully propagated through the 5-stage pipeline.
    // -------------------------------------------------------------------------
    integer cycle_count;
    integer x26_seen_at;
    initial begin
        cycle_count  = 0;
        x26_seen_at  = -1;
    end

    always @(posedge clk) begin
        if (rst_n) begin
            cycle_count = cycle_count + 1;

            // Record first cycle where x26 becomes 1
            if (u_soc.u_cpu.u_stage_id.regfile[26] == 32'd1 && x26_seen_at < 0)
                x26_seen_at = cycle_count;

            // Wait 10 cycles after x26 first went high, then judge x27
            if (x26_seen_at >= 0 && (cycle_count - x26_seen_at) >= 10) begin
                if (u_soc.u_cpu.u_stage_id.regfile[27] == 32'd1)
                    $display("TEST_PASS");
                else
                    $display("TEST_FAIL (s11 = %0d)", u_soc.u_cpu.u_stage_id.regfile[27]);
                $finish;
            end

            // Safety timeout (100 000 cycles ≈ 2 ms at 50 MHz)
            if (cycle_count > 100000) begin
                $display("TEST_FAIL (timeout  s10=%0h  s11=%0h)",
                         u_soc.u_cpu.u_stage_id.regfile[26],
                         u_soc.u_cpu.u_stage_id.regfile[27]);
                $finish;
            end
        end
    end

endmodule
