`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_compare7;
    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    sim_soc u_new (.clk(clk), .rst_n(rst_n));
    old_sim_soc u_old (.clk(clk), .rst_n(rst_n));

    integer i;
    initial begin
        for (i = 0; i < 4096; i = i + 1) begin
            u_new.imem[i] = 32'h0000_0013;
            u_old.imem[i] = 32'h0000_0013;
        end
        for (i = 0; i < 65536; i = i + 1) begin
            u_new.dmem[i] = 32'h0;
            u_old.dmem[i] = 32'h0;
        end
        $readmemh(`IROM_HEX, u_new.imem);
        $readmemh(`IROM_HEX, u_old.imem);
        $readmemh(`DRAM_HEX, u_new.dmem);
        $readmemh(`DRAM_HEX, u_old.dmem);
        rst_n = 0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1;
    end

    // === NEW design signals ===
    wire [31:0] new_pc = u_new.u_cpu.u_if.pc_out;
    wire new_stall     = u_new.u_cpu.pipeline_stall;
    wire new_flush     = u_new.u_cpu.flush;
    wire new_hz_stall  = u_new.u_cpu.hz_stall;
    wire new_ex_stall  = u_new.u_cpu.ex_stall;

    // IDEX signals
    wire [31:0] new_idex_pc        = u_new.u_cpu.idex_a_pc;
    wire        new_idex_branch    = u_new.u_cpu.idex_a_branch;
    wire        new_idex_jal       = u_new.u_cpu.idex_a_jal;
    wire        new_idex_jalr      = u_new.u_cpu.idex_a_jalr;
    wire        new_idex_predicted = u_new.u_cpu.idex_a_predicted;
    wire [31:0] new_idex_ptgt      = u_new.u_cpu.idex_a_predicted_target;
    wire [2:0]  new_idex_funct3    = u_new.u_cpu.idex_a_funct3;
    wire [4:0]  new_idex_rs1_addr  = u_new.u_cpu.idex_a_rs1_addr;
    wire [4:0]  new_idex_rs2_addr  = u_new.u_cpu.idex_a_rs2_addr;
    wire [31:0] new_idex_rs1_data  = u_new.u_cpu.idex_a_rs1_data;
    wire [31:0] new_idex_rs2_data  = u_new.u_cpu.idex_a_rs2_data;
    wire        new_idex_ecall     = u_new.u_cpu.idex_a_ecall;
    wire        new_idex_mret      = u_new.u_cpu.idex_a_mret;

    // EX-stage outputs
    wire        new_ex_branch_taken = u_new.u_cpu.ex_a_branch_taken;
    wire [31:0] new_ex_branch_tgt   = u_new.u_cpu.ex_a_branch_target;
    wire        new_ex_redirect     = u_new.u_cpu.ex_redirect;
    wire [31:0] new_ex_redirect_tgt = u_new.u_cpu.ex_redirect_target;
    wire        new_dir_mismatch    = u_new.u_cpu.direction_mismatch;
    wire        new_tgt_mismatch    = u_new.u_cpu.target_mismatch;

    // Forwarding selects
    wire [2:0]  new_fwd_a_rs1 = u_new.u_cpu.fwd_a_rs1;
    wire [2:0]  new_fwd_a_rs2 = u_new.u_cpu.fwd_a_rs2;

    // Forwarding data sources
    wire [31:0] new_exmem_a_fwd = u_new.u_cpu.exmem_a_fwd_data;
    wire [31:0] new_memwb_a_wd  = u_new.u_cpu.memwb_a_write_data;
    wire [4:0]  new_exmem_a_rd  = u_new.u_cpu.exmem_a_rd_addr;
    wire        new_exmem_a_rw  = u_new.u_cpu.exmem_a_reg_write;
    wire [4:0]  new_memwb_a_rd  = u_new.u_cpu.memwb_a_rd_addr;
    wire        new_memwb_a_rw  = u_new.u_cpu.memwb_a_reg_write;

    // IFID signals
    wire [31:0] new_ifid_pc_a   = u_new.u_cpu.ifid_pc_a;
    wire [31:0] new_ifid_inst_a = u_new.u_cpu.ifid_inst_a;
    wire        new_ifid_pred_a = u_new.u_cpu.ifid_predicted_a;

    // === OLD design signals ===
    wire [31:0] old_pc = u_old.u_cpu.u_if.pc_out;
    wire old_stall     = u_old.u_cpu.pipeline_stall;
    wire old_flush     = u_old.u_cpu.flush;
    wire old_hz_stall  = u_old.u_cpu.hz_stall;
    wire old_ex_stall  = u_old.u_cpu.ex_stall;

    // IDEX signals
    wire [31:0] old_idex_pc        = u_old.u_cpu.idex_pc;
    wire        old_idex_branch    = u_old.u_cpu.idex_branch;
    wire        old_idex_jal       = u_old.u_cpu.idex_jal;
    wire        old_idex_jalr      = u_old.u_cpu.idex_jalr;
    wire        old_idex_predicted = u_old.u_cpu.idex_predicted;
    wire [31:0] old_idex_ptgt      = u_old.u_cpu.idex_predicted_target;
    wire [2:0]  old_idex_funct3    = u_old.u_cpu.idex_funct3;
    wire [4:0]  old_idex_rs1_addr  = u_old.u_cpu.idex_rs1_addr;
    wire [4:0]  old_idex_rs2_addr  = u_old.u_cpu.idex_rs2_addr;
    wire [31:0] old_idex_rs1_data  = u_old.u_cpu.idex_rs1_data;
    wire [31:0] old_idex_rs2_data  = u_old.u_cpu.idex_rs2_data;
    wire        old_idex_ecall     = u_old.u_cpu.idex_ecall;
    wire        old_idex_mret      = u_old.u_cpu.idex_mret;

    // EX-stage outputs
    wire        old_ex_branch_taken = u_old.u_cpu.ex_branch_taken;
    wire [31:0] old_ex_branch_tgt   = u_old.u_cpu.ex_branch_target;
    wire        old_ex_redirect     = u_old.u_cpu.ex_redirect;
    wire [31:0] old_ex_redirect_tgt = u_old.u_cpu.ex_redirect_target;
    wire        old_dir_mismatch    = u_old.u_cpu.direction_mismatch;
    wire        old_tgt_mismatch    = u_old.u_cpu.target_mismatch;

    // Forwarding
    wire [1:0]  old_fwd_a  = u_old.u_cpu.forward_a;
    wire [1:0]  old_fwd_b  = u_old.u_cpu.forward_b;
    wire [31:0] old_exmem_fwd = u_old.u_cpu.exmem_fwd_data;
    wire [31:0] old_memwb_wd  = u_old.u_cpu.memwb_write_data;
    wire [4:0]  old_exmem_rd  = u_old.u_cpu.exmem_rd_addr;
    wire        old_exmem_rw  = u_old.u_cpu.exmem_reg_write;
    wire [4:0]  old_memwb_rd  = u_old.u_cpu.memwb_rd_addr;
    wire        old_memwb_rw  = u_old.u_cpu.memwb_reg_write;

    // IFID signals
    wire [31:0] old_ifid_pc   = u_old.u_cpu.ifid_pc;
    wire [31:0] old_ifid_inst = u_old.u_cpu.ifid_instruction;
    wire        old_ifid_pred = u_old.u_cpu.ifid_predicted;

    integer cycle = 0;
    reg found = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            // Detect first divergence
            if (!found && new_pc !== old_pc) begin
                found <= 1;
                $display("*** PC DIVERGENCE at cycle %0d ***", cycle);
            end

            // Trace 15 cycles before and at divergence
            if (cycle >= 435 && cycle <= 450) begin
                $display("===== C%04d =====", cycle);
                $display("  NEW: PC=%08h stl=%b hz=%b exs=%b fl=%b",
                    new_pc, new_stall, new_hz_stall, new_ex_stall, new_flush);
                $display("  OLD: PC=%08h stl=%b hz=%b exs=%b fl=%b",
                    old_pc, old_stall, old_hz_stall, old_ex_stall, old_flush);

                // IFID
                $display("  NEW ifid: pc=%08h inst=%08h pred=%b",
                    new_ifid_pc_a, new_ifid_inst_a, new_ifid_pred_a);
                $display("  OLD ifid: pc=%08h inst=%08h pred=%b",
                    old_ifid_pc, old_ifid_inst, old_ifid_pred);

                // IDEX
                $display("  NEW idex: pc=%08h br=%b jal=%b jalr=%b ecall=%b mret=%b pred=%b ptgt=%08h f3=%03b",
                    new_idex_pc, new_idex_branch, new_idex_jal, new_idex_jalr,
                    new_idex_ecall, new_idex_mret, new_idex_predicted, new_idex_ptgt, new_idex_funct3);
                $display("  OLD idex: pc=%08h br=%b jal=%b jalr=%b ecall=%b mret=%b pred=%b ptgt=%08h f3=%03b",
                    old_idex_pc, old_idex_branch, old_idex_jal, old_idex_jalr,
                    old_idex_ecall, old_idex_mret, old_idex_predicted, old_idex_ptgt, old_idex_funct3);

                // IDEX operands
                $display("  NEW idex_data: rs1=%02d=%08h rs2=%02d=%08h",
                    new_idex_rs1_addr, new_idex_rs1_data, new_idex_rs2_addr, new_idex_rs2_data);
                $display("  OLD idex_data: rs1=%02d=%08h rs2=%02d=%08h",
                    old_idex_rs1_addr, old_idex_rs1_data, old_idex_rs2_addr, old_idex_rs2_data);

                // Forwarding
                $display("  NEW fwd: a_rs1=%03b a_rs2=%03b | exmem: rd=%02d rw=%b fwd=%08h | memwb: rd=%02d rw=%b wd=%08h",
                    new_fwd_a_rs1, new_fwd_a_rs2, new_exmem_a_rd, new_exmem_a_rw, new_exmem_a_fwd,
                    new_memwb_a_rd, new_memwb_a_rw, new_memwb_a_wd);
                $display("  OLD fwd: a=%02b b=%02b | exmem: rd=%02d rw=%b fwd=%08h | memwb: rd=%02d rw=%b wd=%08h",
                    old_fwd_a, old_fwd_b, old_exmem_rd, old_exmem_rw, old_exmem_fwd,
                    old_memwb_rd, old_memwb_rw, old_memwb_wd);

                // EX redirect
                $display("  NEW ex: taken=%b tgt=%08h dir_mm=%b tgt_mm=%b redir=%b rtgt=%08h",
                    new_ex_branch_taken, new_ex_branch_tgt, new_dir_mismatch, new_tgt_mismatch,
                    new_ex_redirect, new_ex_redirect_tgt);
                $display("  OLD ex: taken=%b tgt=%08h dir_mm=%b tgt_mm=%b redir=%b rtgt=%08h",
                    old_ex_branch_taken, old_ex_branch_tgt, old_dir_mismatch, old_tgt_mismatch,
                    old_ex_redirect, old_ex_redirect_tgt);

                // Check register differences
                for (i = 1; i < 32; i = i + 1) begin
                    if (u_new.u_cpu.u_stage_id.regfile[i] !== u_old.u_cpu.u_stage_id.regfile[i]) begin
                        $display("  >>> REG DIFF x%0d: NEW=%08h OLD=%08h", i,
                            u_new.u_cpu.u_stage_id.regfile[i],
                            u_old.u_cpu.u_stage_id.regfile[i]);
                    end
                end
            end

            if (cycle == 455) $finish;
        end
    end
endmodule
