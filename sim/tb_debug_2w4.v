`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_debug_2w4;
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
    wire ex_redirect = u_soc.u_cpu.ex_redirect;
    wire [31:0] ex_redir_tgt = u_soc.u_cpu.ex_redirect_target;
    wire stall = u_soc.u_cpu.pipeline_stall;
    wire flush = u_soc.u_cpu.flush;
    wire predict_a = u_soc.u_cpu.u_if.predicted_a;
    wire [31:0] pred_tgt_a = u_soc.u_cpu.u_if.predict_target_a;
    wire b_valid = u_soc.u_cpu.u_if.b_valid;

    integer cycle = 0;
    reg found = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            // Detect when PC drops below 0x80000000
            if (!found && pc < 32'h80000000 && pc != 32'h0) begin
                found <= 1;
                $display("*** PC CORRUPTION at cycle %0d: PC=%08h ***", cycle, pc);
                $display("    stl=%b fl=%b pr=%b redir=%b rtgt=%08h ptgt=%08h bv=%b",
                    stall, flush, predict_a, ex_redirect, ex_redir_tgt, pred_tgt_a, b_valid);
            end

            // Print 30 cycles after corruption found
            if (found && cycle <= 5050) begin
                $display("C%05d PC=%08h stl=%b fl=%b pr=%b redir=%b rtgt=%08h",
                    cycle, pc, stall, flush, predict_a, ex_redirect, ex_redir_tgt);
            end

            // Also log any redirects for context leading up to corruption
            if (!found && ex_redirect) begin
                $display("REDIR C%05d PC=%08h -> %08h", cycle, pc, ex_redir_tgt);
            end

            if (cycle >= 6000) begin
                $display("--- Final PC=%08h at cycle %0d ---", pc, cycle);
                $finish;
            end
        end
    end
endmodule
