`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_compare;
    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    // NEW design (2-wide, forced single-issue)
    sim_soc u_new (.clk(clk), .rst_n(rst_n));

    // OLD design (original single-issue)
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

    integer cycle = 0;
    reg found = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            // Compare PCs
            if (!found && new_pc !== old_pc) begin
                found <= 1;
                $display("*** PC DIVERGENCE at cycle %0d ***", cycle);
                $display("  NEW PC = %08h", new_pc);
                $display("  OLD PC = %08h", old_pc);
            end

            // Compare registers every cycle
            if (!found) begin
                for (i = 1; i < 32; i = i + 1) begin
                    if (u_new.u_cpu.u_stage_id.regfile[i] !== u_old.u_cpu.u_stage_id.regfile[i]) begin
                        found <= 1;
                        $display("*** REGISTER DIVERGENCE at cycle %0d x%0d ***", cycle, i);
                        $display("  NEW x%0d = %08h  OLD x%0d = %08h", i, u_new.u_cpu.u_stage_id.regfile[i], i, u_old.u_cpu.u_stage_id.regfile[i]);
                        $display("  NEW PC = %08h  OLD PC = %08h", new_pc, old_pc);
                    end
                end
            end

            // Print context after divergence
            if (found && cycle <= 100000) begin
                $display("C%04d NEW_PC=%08h OLD_PC=%08h", cycle, new_pc, old_pc);
            end

            if (cycle >= 100000 || (found && cycle >= 100000)) begin
                $display("--- NEW registers ---");
                for (i = 1; i < 32; i = i + 1)
                    if (u_new.u_cpu.u_stage_id.regfile[i] !== 0)
                        $display("  x%0d = %08h", i, u_new.u_cpu.u_stage_id.regfile[i]);
                $display("--- OLD registers ---");
                for (i = 1; i < 32; i = i + 1)
                    if (u_old.u_cpu.u_stage_id.regfile[i] !== 0)
                        $display("  x%0d = %08h", i, u_old.u_cpu.u_stage_id.regfile[i]);
                $finish;
            end
        end
    end
endmodule
