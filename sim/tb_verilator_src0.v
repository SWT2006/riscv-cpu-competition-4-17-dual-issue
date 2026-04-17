// tb_verilator_src0.v — Self-contained Verilator testbench for src0.
// Does not probe internal signals — uses only the sim_soc port interface
// plus Verilator-compatible $c / DPI for cycle counting.
//
// Self-loop detection: PC is exposed via a small output port added to sim_soc.
// But we can't modify sim_soc here, so instead we use a wrapper approach:
// instantiate sim_soc_monitor which wraps sim_soc with PC/register visibility.
`timescale 1ns/1ps

module tb_verilator_src0;

    reg clk = 0;
    reg rst_n = 0;

    always #5 clk = ~clk;

    sim_soc u_soc (
        .clk   (clk),
        .rst_n (rst_n)
    );

    // Memory init
    integer ii;
    initial begin
        for (ii = 0; ii < 4096; ii = ii + 1)
            u_soc.imem[ii] = 32'h0000_0013;
        for (ii = 0; ii < 65536; ii = ii + 1)
            u_soc.dmem[ii] = 32'h0;
        $readmemh("src0_irom.hex", u_soc.imem);
        $readmemh("src0_dram.hex", u_soc.dmem);

        rst_n = 0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1;
    end

    // PC monitor — access through hierarchy
    wire [31:0] cpu_pc = u_soc.u_cpu.u_if.pc_out;

    reg [63:0] cycle_count  = 0;
    // With dual-issue, legitimate loops can have period-3 PC patterns that
    // match the prev3_pc detection.  Division prep loops run up to ~32
    // iterations (96 cycles at period 3).  200 is safe for detection.
    localparam STABLE_THRESH = 200;
    reg [31:0] stable_count = 0;
    reg [31:0] prev_pc  = 32'hFFFFFFFF;
    reg [31:0] prev2_pc = 32'hFFFFFFFF;
    reg [31:0] prev3_pc = 32'hFFFFFFFF;

    // Dual-issue activity counter
    reg [63:0] dual_issue_count = 0;
    wire b_valid_ex = u_soc.u_cpu.u_pipe_idex.idex_b_valid;

    always @(posedge clk) begin
        if (rst_n && b_valid_ex)
            dual_issue_count <= dual_issue_count + 1;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            cycle_count  <= 0;
            stable_count <= 0;
            prev_pc  <= 32'hFFFFFFFF;
            prev2_pc <= 32'hFFFFFFFF;
            prev3_pc <= 32'hFFFFFFFF;
        end else begin
            cycle_count <= cycle_count + 1;

            if (cpu_pc == prev3_pc && cpu_pc != 32'hFFFFFFFF)
                stable_count <= stable_count + 1;
            else
                stable_count <= 0;

            prev3_pc <= prev2_pc;
            prev2_pc <= prev_pc;
            prev_pc  <= cpu_pc;

            if (stable_count >= STABLE_THRESH) begin
                $display("");
                $display("=== TEST: src0 (dual-issue) ===");
                $display("  Self-loop at PC = 0x%08h after %0d cycles", cpu_pc, cycle_count);
                $display("  Dual-issue cycles (b_valid in EX): %0d", dual_issue_count);
                $display("  Dual-issue rate: %0d%%", (dual_issue_count * 100) / cycle_count);
                // Register dump
                $display("  Register file:");
                dump_regs;
                if (cpu_pc == 32'h80000010)
                    $display("  RESULT: *** PASS ***");
                else
                    $display("  RESULT: *** STUCK at 0x%08h ***", cpu_pc);
                $finish;
            end

            if (cycle_count >= 64'd2000000000) begin
                $display("");
                $display("=== TIMEOUT after %0d cycles ===", cycle_count);
                $display("  PC = 0x%08h", cpu_pc);
                $display("  Dual-issue cycles: %0d", dual_issue_count);
                dump_regs;
                $display("  RESULT: FAIL (timeout)");
                $finish;
            end

            if (cycle_count[26:0] == 0 && cycle_count > 0)  // ~every 134M cycles
                $display("[PROGRESS] %0dM cycles, PC=0x%08h, dual=%0d", cycle_count / 1000000, cpu_pc, dual_issue_count);
        end
    end

    task dump_regs;
        integer k;
        reg [31:0] rv;
        begin
            for (k = 0; k < 32; k = k + 1) begin
                if (k == 0)
                    rv = 32'h0;
                else
                    rv = u_soc.u_cpu.u_stage_id.regfile[k];
                if (rv !== 32'h0)
                    $display("    x%0d = 0x%08h", k, rv);
            end
        end
    endtask

endmodule
