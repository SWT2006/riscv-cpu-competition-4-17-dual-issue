`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`define TEST_NAME "src0_debug"
`timescale 1ns/1ps

module tb_debug_2w;
    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    sim_soc u_soc (.clk(clk), .rst_n(rst_n));

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

    wire [31:0] pc = u_soc.u_cpu.u_if.pc_out;
    wire b_valid = u_soc.u_cpu.u_if.b_valid;
    wire stall = u_soc.u_cpu.pipeline_stall;
    wire flush = u_soc.u_cpu.flush;
    wire [31:0] inst_a = u_soc.u_cpu.u_if.inst_a;
    wire [31:0] inst_b = u_soc.u_cpu.u_if.inst_b;
    wire predict_a = u_soc.u_cpu.u_if.predicted_a;

    integer cycle = 0;
    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;
            if (cycle < 200) begin
                $display("C%04d PC=%08h A=%08h B=%08h bv=%b stl=%b fl=%b pr=%b",
                    cycle, pc, inst_a, inst_b, b_valid, stall, flush, predict_a);
            end
            if (cycle == 500) begin
                $display("--- Register dump at cycle 500 ---");
                for (i = 1; i < 32; i = i + 1) begin
                    if (u_soc.u_cpu.u_stage_id.regfile[i] !== 32'h0)
                        $display("  x%0d = %08h", i, u_soc.u_cpu.u_stage_id.regfile[i]);
                end
                $finish;
            end
        end
    end
endmodule
