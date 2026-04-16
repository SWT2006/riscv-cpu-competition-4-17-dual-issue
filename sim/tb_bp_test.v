`define IROM_HEX "bp_test_irom.hex"
`define DRAM_HEX "bp_test_dram.hex"
`define TEST_NAME "bp_test"
`define MAX_CYCLES 2000
`define STABLE_CYCLES 20

`timescale 1ns/1ps

module tb_coe;

    reg clk  = 1'b0;
    reg rst_n = 1'b0;

    always #5 clk = ~clk;

    sim_soc u_soc (
        .clk   (clk),
        .rst_n (rst_n)
    );

    integer i;
    initial begin
        for (i = 0; i < 4096; i = i + 1)
            u_soc.imem[i] = 32'h0000_0013;
        for (i = 0; i < 65536; i = i + 1)
            u_soc.dmem[i] = 32'h0;
        $readmemh(`IROM_HEX, u_soc.imem);
        $readmemh(`DRAM_HEX, u_soc.dmem);
        rst_n = 1'b0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
    end

    integer  cycle_count   = 0;
    integer  stable_count  = 0;
    reg [31:0] prev_pc     = 32'hFFFF_FFFF;

    wire [31:0] cpu_pc = u_soc.u_cpu.u_if.pc_out;

    always @(posedge clk) begin
        if (!rst_n) begin
            cycle_count  <= 0;
            stable_count <= 0;
            prev_pc      <= 32'hFFFF_FFFF;
        end else begin
            cycle_count <= cycle_count + 1;

            // Print PC trace for debugging
            if (cycle_count < 80)
                $display("  cycle %0d: PC=0x%08h", cycle_count, cpu_pc);

            if (cpu_pc == prev_pc)
                stable_count <= stable_count + 1;
            else
                stable_count <= 0;

            prev_pc <= cpu_pc;

            if (stable_count >= `STABLE_CYCLES) begin
                $display("");
                $display("=== TEST: %s ===", `TEST_NAME);
                $display("  Terminated: self-loop at PC = 0x%08h after %0d cycles",
                         cpu_pc, cycle_count);

                // Register checks
                $display("  Registers:");
                $display("    x1  = 0x%08h (expect 0x80000030)", u_soc.u_cpu.u_stage_id.regfile[1]);
                $display("    x2  = 0x%08h (expect 0x00000039)", u_soc.u_cpu.u_stage_id.regfile[2]);
                $display("    x3  = 0x%08h (expect 0x00000000, skipped)", u_soc.u_cpu.u_stage_id.regfile[3]);
                $display("    x4  = 0x%08h (expect 0x00000055)", u_soc.u_cpu.u_stage_id.regfile[4]);
                $display("    x5  = 0x%08h (expect 0x00000001)", u_soc.u_cpu.u_stage_id.regfile[5]);
                $display("    x6  = 0x%08h (expect 0x00000000, skipped)", u_soc.u_cpu.u_stage_id.regfile[6]);
                $display("    x7  = 0x%08h (expect 0x00000077)", u_soc.u_cpu.u_stage_id.regfile[7]);
                $display("    x8  = 0x%08h (expect 0x00000033)", u_soc.u_cpu.u_stage_id.regfile[8]);

                // DRAM checks
                $display("  DRAM:");
                $display("    [0x80100000] = 0x%08h (expect 0x00000039)", u_soc.dmem[0]);
                $display("    [0x80100004] = 0x%08h (expect 0x00000055)", u_soc.dmem[1]);
                $display("    [0x80100008] = 0x%08h (expect 0x00000000)", u_soc.dmem[2]);
                $display("    [0x8010000C] = 0x%08h (expect 0x00000077)", u_soc.dmem[3]);
                $display("    [0x80100010] = 0x%08h (expect 0x00000000)", u_soc.dmem[4]);
                $display("    [0x80100014] = 0x%08h (expect 0x00000033)", u_soc.dmem[5]);

                // Automated pass/fail
                if (u_soc.u_cpu.u_stage_id.regfile[1]  == 32'h80000030 &&
                    u_soc.u_cpu.u_stage_id.regfile[2]  == 32'h00000039 &&
                    u_soc.u_cpu.u_stage_id.regfile[3]  == 32'h00000000 &&
                    u_soc.u_cpu.u_stage_id.regfile[4]  == 32'h00000055 &&
                    u_soc.u_cpu.u_stage_id.regfile[5]  == 32'h00000001 &&
                    u_soc.u_cpu.u_stage_id.regfile[6]  == 32'h00000000 &&
                    u_soc.u_cpu.u_stage_id.regfile[7]  == 32'h00000077 &&
                    u_soc.u_cpu.u_stage_id.regfile[8]  == 32'h00000033 &&
                    u_soc.dmem[0] == 32'h00000039 &&
                    u_soc.dmem[1] == 32'h00000055 &&
                    u_soc.dmem[2] == 32'h00000000 &&
                    u_soc.dmem[3] == 32'h00000077 &&
                    u_soc.dmem[4] == 32'h00000000 &&
                    u_soc.dmem[5] == 32'h00000033 &&
                    cpu_pc == 32'h80000064)
                    $display("  RESULT: PASS (all 15 checks OK)");
                else
                    $display("  RESULT: FAIL (mismatch)");
                $finish;
            end

            if (cycle_count >= `MAX_CYCLES) begin
                $display("");
                $display("=== TEST: %s ===", `TEST_NAME);
                $display("  TIMEOUT after %0d cycles, PC = 0x%08h", cycle_count, cpu_pc);
                $finish;
            end
        end
    end

endmodule
