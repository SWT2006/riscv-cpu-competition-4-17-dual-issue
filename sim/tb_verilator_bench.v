// tb_verilator_bench.v — Parameterized Verilator testbench for benchmarks.
// Use -DIROM_FILE="srcN_irom.hex" -DDRAM_FILE="srcN_dram.hex" -DTEST_LABEL="srcN"
// to select which benchmark to run.
`timescale 1ns/1ps

`ifndef IROM_FILE
  `define IROM_FILE "src0_irom.hex"
`endif
`ifndef DRAM_FILE
  `define DRAM_FILE "src0_dram.hex"
`endif
`ifndef TEST_LABEL
  `define TEST_LABEL "benchmark"
`endif

module tb_verilator_bench;

    reg clk = 0;
    reg rst_n = 0;

    always #5 clk = ~clk;

    sim_soc u_soc (
        .clk   (clk),
        .rst_n (rst_n)
    );

    integer ii;
    initial begin
        for (ii = 0; ii < 4096; ii = ii + 1)
            u_soc.imem[ii] = 32'h0000_0013;
        for (ii = 0; ii < 65536; ii = ii + 1)
            u_soc.dmem[ii] = 32'h0;
        $readmemh(`IROM_FILE, u_soc.imem);
        $readmemh(`DRAM_FILE, u_soc.dmem);

        rst_n = 0;
        #105;  // 10.5 clock cycles (negedge of cycle 10)
        rst_n = 1;
    end

    wire [31:0] cpu_pc = u_soc.u_cpu.u_if.pc_out;

    reg [63:0] cycle_count  = 0;
    localparam STABLE_THRESH = 200;
    reg [31:0] stable_count = 0;
    reg [31:0] prev_pc  = 32'hFFFFFFFF;
    reg [31:0] prev2_pc = 32'hFFFFFFFF;
    reg [31:0] prev3_pc = 32'hFFFFFFFF;

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
                $display("=== TEST: %0s (dual-issue) ===", `TEST_LABEL);
                $display("  Self-loop at PC = 0x%08h after %0d cycles", cpu_pc, cycle_count);
                $display("  Dual-issue cycles (b_valid in EX): %0d", dual_issue_count);
                if (cycle_count > 0)
                    $display("  Dual-issue rate: %0d%%", (dual_issue_count * 100) / cycle_count);
                $display("  Register file:");
                dump_regs;
                if (cpu_pc == 32'h80000010)
                    $display("  RESULT: *** PASS ***");
                else
                    $display("  RESULT: *** STUCK at 0x%08h ***", cpu_pc);
                $finish;
            end

            if (cycle_count >= 64'd3000000000) begin
                $display("");
                $display("=== TIMEOUT after %0d cycles ===", cycle_count);
                $display("  PC = 0x%08h", cpu_pc);
                $display("  Dual-issue cycles: %0d", dual_issue_count);
                dump_regs;
                $display("  RESULT: FAIL (timeout)");
                $finish;
            end

            if (cycle_count[26:0] == 0 && cycle_count > 0)
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
