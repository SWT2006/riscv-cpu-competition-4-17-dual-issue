`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_compare2;
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

    // ---- NEW design ----
    wire [31:0] new_pc   = u_new.u_cpu.u_if.pc_out;
    wire        new_stall = u_new.u_cpu.pipeline_stall;
    wire        new_flush = u_new.u_cpu.flush;
    wire [31:0] new_ifid_pc   = u_new.u_cpu.ifid_pc_a;
    wire [31:0] new_ifid_inst = u_new.u_cpu.ifid_inst_a;
    wire [31:0] new_idex_pc   = u_new.u_cpu.idex_a_pc;
    wire        new_idex_rw   = u_new.u_cpu.idex_a_reg_write;
    wire [4:0]  new_idex_rd   = u_new.u_cpu.idex_a_rd_addr;
    // WB stage
    wire        new_wb_we   = u_new.u_cpu.memwb_a_reg_write;
    wire [4:0]  new_wb_rd   = u_new.u_cpu.memwb_a_rd_addr;
    wire [31:0] new_wb_data = u_new.u_cpu.memwb_a_write_data;

    // ---- OLD design ----
    wire [31:0] old_pc   = u_old.u_cpu.u_if.pc_out;
    wire        old_stall = u_old.u_cpu.pipeline_stall;
    wire        old_flush = u_old.u_cpu.flush;
    wire [31:0] old_ifid_pc   = u_old.u_cpu.ifid_pc;
    wire [31:0] old_ifid_inst = u_old.u_cpu.ifid_instruction;
    wire [31:0] old_idex_pc   = u_old.u_cpu.idex_pc;
    wire        old_idex_rw   = u_old.u_cpu.idex_reg_write;
    wire [4:0]  old_idex_rd   = u_old.u_cpu.idex_rd_addr;
    // WB stage
    wire        old_wb_we   = u_old.u_cpu.memwb_reg_write;
    wire [4:0]  old_wb_rd   = u_old.u_cpu.memwb_rd_addr;
    wire [31:0] old_wb_data = u_old.u_cpu.memwb_write_data;

    integer cycle = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            if (cycle >= 45 && cycle <= 70) begin
                $display("C%03d NEW: PC=%08h stl=%b fl=%b | ifid_pc=%08h i=%08h | idex_pc=%08h rw=%b rd=%02d | wb_we=%b rd=%02d d=%08h",
                    cycle, new_pc, new_stall, new_flush,
                    new_ifid_pc, new_ifid_inst,
                    new_idex_pc, new_idex_rw, new_idex_rd,
                    new_wb_we, new_wb_rd, new_wb_data);
                $display("C%03d OLD: PC=%08h stl=%b fl=%b | ifid_pc=%08h i=%08h | idex_pc=%08h rw=%b rd=%02d | wb_we=%b rd=%02d d=%08h",
                    cycle, old_pc, old_stall, old_flush,
                    old_ifid_pc, old_ifid_inst,
                    old_idex_pc, old_idex_rw, old_idex_rd,
                    old_wb_we, old_wb_rd, old_wb_data);

                for (i = 1; i < 32; i = i + 1) begin
                    if (u_new.u_cpu.u_stage_id.regfile[i] !== u_old.u_cpu.u_stage_id.regfile[i]) begin
                        $display("  >>> REG DIFF x%0d: NEW=%08h OLD=%08h", i,
                            u_new.u_cpu.u_stage_id.regfile[i],
                            u_old.u_cpu.u_stage_id.regfile[i]);
                    end
                end
            end

            if (cycle == 75) $finish;
        end
    end
endmodule
