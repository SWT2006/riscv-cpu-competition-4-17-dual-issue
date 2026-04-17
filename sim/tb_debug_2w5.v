`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_debug_2w5;
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
    wire [31:0] inst_a = u_soc.u_cpu.u_if.inst_a;
    wire [31:0] inst_b = u_soc.u_cpu.u_if.inst_b;
    wire b_valid = u_soc.u_cpu.u_if.b_valid;
    wire stall = u_soc.u_cpu.pipeline_stall;
    wire flush = u_soc.u_cpu.flush;
    wire predict_a = u_soc.u_cpu.u_if.predicted_a;
    wire ex_redirect = u_soc.u_cpu.ex_redirect;
    wire [31:0] ex_redir_tgt = u_soc.u_cpu.ex_redirect_target;

    // ID/EX stage
    wire [31:0] idex_a_pc = u_soc.u_cpu.idex_a_pc;
    wire idex_a_ecall = u_soc.u_cpu.idex_a_ecall;
    wire idex_a_mret = u_soc.u_cpu.idex_a_mret;
    wire idex_a_branch = u_soc.u_cpu.idex_a_branch;
    wire idex_a_jal = u_soc.u_cpu.idex_a_jal;
    wire idex_a_jalr = u_soc.u_cpu.idex_a_jalr;
    wire idex_a_pred = u_soc.u_cpu.idex_a_predicted;

    // CSR
    wire [31:0] csr_mtvec = u_soc.u_cpu.csr_mtvec;
    wire [31:0] csr_mepc = u_soc.u_cpu.csr_mepc;

    // EX outputs
    wire ex_branch_taken = u_soc.u_cpu.ex_a_branch_taken;
    wire [31:0] ex_branch_target = u_soc.u_cpu.ex_a_branch_target;
    wire ex_trap_valid = u_soc.u_cpu.ex_a_trap_valid;

    integer cycle = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;
            if (cycle >= 515 && cycle <= 560) begin
                $display("C%04d PC=%08h A=%08h B=%08h bv=%b stl=%b fl=%b pr=%b | idex=%08h ecall=%b mret=%b br=%b jal=%b jalr=%b pred=%b | mtvec=%08h mepc=%08h | exbr=%b extgt=%08h trap=%b redir=%b rtgt=%08h",
                    cycle, pc, inst_a, inst_b, b_valid, stall, flush, predict_a,
                    idex_a_pc, idex_a_ecall, idex_a_mret, idex_a_branch, idex_a_jal, idex_a_jalr, idex_a_pred,
                    csr_mtvec, csr_mepc,
                    ex_branch_taken, ex_branch_target, ex_trap_valid, ex_redirect, ex_redir_tgt);
            end
            if (cycle == 570) $finish;
        end
    end
endmodule
