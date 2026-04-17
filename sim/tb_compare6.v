`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_compare6;
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

    wire [31:0] new_pc = u_new.u_cpu.u_if.pc_out;
    wire [31:0] old_pc = u_old.u_cpu.u_if.pc_out;
    wire new_stall = u_new.u_cpu.pipeline_stall;
    wire old_stall = u_old.u_cpu.pipeline_stall;
    wire new_flush = u_new.u_cpu.flush;
    wire old_flush = u_old.u_cpu.flush;

    // Prediction signals
    wire new_pred = u_new.u_cpu.u_if.predicted_a;
    wire old_pred = u_old.u_cpu.u_if.predicted;
    wire [31:0] new_pred_tgt = u_new.u_cpu.u_if.predict_target_a;
    wire [31:0] old_pred_tgt = u_old.u_cpu.u_if.predicted_target;

    // EX redirect
    wire new_redir = u_new.u_cpu.ex_redirect;
    wire [31:0] new_rtgt = u_new.u_cpu.ex_redirect_target;
    wire old_redir = u_old.u_cpu.ex_redirect;
    wire [31:0] old_rtgt = u_old.u_cpu.ex_redirect_target;

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

            // Trace 10 cycles before divergence
            if (cycle >= 430 && cycle <= 455) begin
                $display("C%04d NEW: PC=%08h stl=%b fl=%b pred=%b ptgt=%08h redir=%b rtgt=%08h",
                    cycle, new_pc, new_stall, new_flush, new_pred, new_pred_tgt, new_redir, new_rtgt);
                $display("C%04d OLD: PC=%08h stl=%b fl=%b pred=%b ptgt=%08h redir=%b rtgt=%08h",
                    cycle, old_pc, old_stall, old_flush, old_pred, old_pred_tgt, old_redir, old_rtgt);

                // Check register differences
                for (i = 1; i < 32; i = i + 1) begin
                    if (u_new.u_cpu.u_stage_id.regfile[i] !== u_old.u_cpu.u_stage_id.regfile[i]) begin
                        $display("  >>> REG DIFF x%0d: NEW=%08h OLD=%08h", i,
                            u_new.u_cpu.u_stage_id.regfile[i],
                            u_old.u_cpu.u_stage_id.regfile[i]);
                    end
                end
            end

            if (cycle == 460) $finish;
        end
    end
endmodule
