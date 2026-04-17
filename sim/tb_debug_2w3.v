`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_debug_2w3;
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
    wire predict_a = u_soc.u_cpu.u_if.predicted_a;
    wire ex_redirect = u_soc.u_cpu.ex_redirect;
    wire [31:0] ex_redir_tgt = u_soc.u_cpu.ex_redirect_target;

    // ID/EX stage
    wire [31:0] idex_a_pc = u_soc.u_cpu.idex_a_pc;
    wire idex_a_pred = u_soc.u_cpu.idex_a_predicted;
    wire idex_a_branch = u_soc.u_cpu.idex_a_branch;
    wire idex_a_jal = u_soc.u_cpu.idex_a_jal;
    wire idex_a_jalr = u_soc.u_cpu.idex_a_jalr;

    // EX outputs
    wire ex_branch = u_soc.u_cpu.ex_a_branch_taken;
    wire [31:0] ex_target = u_soc.u_cpu.ex_a_branch_target;

    integer cycle = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            // Trace cycles 245–275 in detail
            if (cycle >= 245 && cycle <= 290) begin
                $display("C%04d PC=%08h bv=%b stl=%b fl=%b pr=%b redir=%b rtgt=%08h | idex_pc=%08h pred=%b br=%b jal=%b jalr=%b | exbr=%b extgt=%08h",
                    cycle, pc, b_valid, stall, flush, predict_a, ex_redirect, ex_redir_tgt,
                    idex_a_pc, idex_a_pred, idex_a_branch, idex_a_jal, idex_a_jalr,
                    ex_branch, ex_target);
            end

            if (cycle == 300) begin
                $display("--- Register dump ---");
                $display("  PC = %08h", pc);
                for (i = 1; i < 32; i = i + 1) begin
                    if (u_soc.u_cpu.u_stage_id.regfile[i] !== 32'h0)
                        $display("  x%0d = %08h", i, u_soc.u_cpu.u_stage_id.regfile[i]);
                end
                $finish;
            end
        end
    end
endmodule
