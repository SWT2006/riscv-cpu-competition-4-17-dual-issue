`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`define TEST_NAME "src0_old"
`define MAX_CYCLES 3000000
`define STABLE_CYCLES 20
`timescale 1ns/1ps

module tb_src0_old;
    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    old_sim_soc u_soc (.clk(clk), .rst_n(rst_n));

    integer i;
    initial begin
        for (i = 0; i < 4096; i = i + 1)
            u_soc.imem[i] = 32'h0000_0013;
        for (i = 0; i < 65536; i = i + 1)
            u_soc.dmem[i] = 32'h0;
        $readmemh(`IROM_HEX, u_soc.imem);
        $readmemh(`DRAM_HEX, u_soc.dmem);
        rst_n = 0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1;
    end

    integer  cycle_count  = 0;
    integer  stable_count = 0;
    reg [31:0] prev_pc    = 32'hFFFF_FFFF;
    wire [31:0] cpu_pc = u_soc.u_cpu.u_if.pc_out;

    always @(posedge clk) begin
        if (!rst_n) begin
            cycle_count  <= 0;
            stable_count <= 0;
            prev_pc      <= 32'hFFFF_FFFF;
        end else begin
            cycle_count <= cycle_count + 1;
            if (cpu_pc == prev_pc)
                stable_count <= stable_count + 1;
            else
                stable_count <= 0;
            prev_pc <= cpu_pc;

            if (stable_count >= `STABLE_CYCLES) begin
                $display("=== TEST: %s ===", `TEST_NAME);
                $display("  Terminated at PC=0x%08h after %0d cycles", cpu_pc, cycle_count);
                $display("  RESULT: PASS");
                $finish;
            end
            if (cycle_count >= `MAX_CYCLES) begin
                $display("=== TEST: %s ===", `TEST_NAME);
                $display("  TIMEOUT after %0d cycles, PC=0x%08h", cycle_count, cpu_pc);
                $display("  RESULT: FAIL (timeout)");
                $finish;
            end
        end
    end
endmodule
