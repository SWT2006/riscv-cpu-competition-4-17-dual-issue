`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_debug_2w2;
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

    // Forwarding signals
    wire [2:0] fwd_a1 = u_soc.u_cpu.fwd_a_rs1;
    wire [2:0] fwd_a2 = u_soc.u_cpu.fwd_a_rs2;
    wire [2:0] fwd_b1 = u_soc.u_cpu.fwd_b_rs1;
    wire [2:0] fwd_b2 = u_soc.u_cpu.fwd_b_rs2;

    // EX stage info
    wire [31:0] ex_a_result = u_soc.u_cpu.ex_a_alu_result;
    wire ex_branch = u_soc.u_cpu.ex_a_branch_taken;
    wire [31:0] ex_target = u_soc.u_cpu.ex_a_branch_target;

    integer cycle = 0;
    reg [31:0] prev_pc = 0;
    integer stuck_cnt = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            // Detect if PC gets stuck (same PC for multiple cycles)
            if (pc == prev_pc)
                stuck_cnt <= stuck_cnt + 1;
            else
                stuck_cnt <= 0;
            prev_pc <= pc;

            // Print every 10000th cycle to see progress
            if (cycle % 10000 == 0 && cycle > 0)
                $display("PROGRESS C%0d PC=%08h", cycle, pc);

            // Print when PC is near the stuck address 0x16c4
            if (pc >= 32'h800016c0 && pc <= 32'h800016d8) begin
                $display("C%06d PC=%08h bv=%b stl=%b fl=%b pr=%b redir=%b fA1=%b fA2=%b brk=%b btgt=%08h exres=%08h",
                    cycle, pc, b_valid, stall, flush, predict_a, ex_redirect,
                    fwd_a1, fwd_a2, ex_branch, ex_target, ex_a_result);
            end

            // Give up after enough cycles
            if (cycle >= 100000) begin
                $display("--- Register dump at cycle %0d ---", cycle);
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
