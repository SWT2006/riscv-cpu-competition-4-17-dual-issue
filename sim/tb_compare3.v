`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_compare3;
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

    // Memory bus signals
    wire        new_wen  = u_new.u_cpu.perip_wen;
    wire [31:0] new_addr = u_new.u_cpu.perip_addr;
    wire [31:0] new_wdata= u_new.u_cpu.perip_wdata;
    wire [1:0]  new_mask = u_new.u_cpu.perip_mask;
    wire [31:0] new_rdata= u_new.perip_rdata;

    wire        old_wen  = u_old.u_cpu.perip_wen;
    wire [31:0] old_addr = u_old.u_cpu.perip_addr;
    wire [31:0] old_wdata= u_old.u_cpu.perip_wdata;
    wire [1:0]  old_mask = u_old.u_cpu.perip_mask;
    wire [31:0] old_rdata= u_old.perip_rdata;

    // PC and pipeline
    wire [31:0] new_pc = u_new.u_cpu.u_if.pc_out;
    wire [31:0] old_pc = u_old.u_cpu.u_if.pc_out;
    wire        new_stall = u_new.u_cpu.pipeline_stall;
    wire        old_stall = u_old.u_cpu.pipeline_stall;
    wire        new_flush = u_new.u_cpu.flush;
    wire        old_flush = u_old.u_cpu.flush;

    integer cycle = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            // Log ALL memory writes for first 60 cycles
            if (new_wen && cycle <= 65) begin
                $display("C%03d NEW_STORE: addr=%08h wdata=%08h mask=%b",
                    cycle, new_addr, new_wdata, new_mask);
            end
            if (old_wen && cycle <= 65) begin
                $display("C%03d OLD_STORE: addr=%08h wdata=%08h mask=%b",
                    cycle, old_addr, old_wdata, old_mask);
            end

            // Log memory reads (load instructions) - detect when address targets dmem[0]
            if (!new_wen && new_addr == 32'h80100000 && cycle <= 65) begin
                $display("C%03d NEW_LOAD:  addr=%08h rdata=%08h mask=%b", cycle, new_addr, new_rdata, new_mask);
            end
            if (!old_wen && old_addr == 32'h80100000 && cycle <= 65) begin
                $display("C%03d OLD_LOAD:  addr=%08h rdata=%08h mask=%b", cycle, old_addr, old_rdata, old_mask);
            end

            // Trace stores specifically to address 0x80100000
            if (new_wen && new_addr == 32'h80100000) begin
                $display("*** NEW writes dmem[0] = %08h at cycle %0d ***", new_wdata, cycle);
            end
            if (old_wen && old_addr == 32'h80100000) begin
                $display("*** OLD writes dmem[0] = %08h at cycle %0d ***", old_wdata, cycle);
            end

            // Also trace pipeline around the interesting region
            if (cycle >= 38 && cycle <= 60) begin
                $display("C%03d NEW: PC=%08h stl=%b fl=%b  OLD: PC=%08h stl=%b fl=%b",
                    cycle, new_pc, new_stall, new_flush, old_pc, old_stall, old_flush);
            end

            // Check DRAM[0] directly
            if (cycle >= 50 && cycle <= 60) begin
                $display("  dmem[0]: NEW=%08h OLD=%08h", u_new.dmem[0], u_old.dmem[0]);
            end

            if (cycle == 65) $finish;
        end
    end
endmodule
