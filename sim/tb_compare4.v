`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_compare4;
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
    wire [31:0] new_addr = u_new.u_cpu.perip_addr;
    wire        new_wen  = u_new.u_cpu.perip_wen;
    wire [1:0]  new_mask = u_new.u_cpu.perip_mask;
    wire [31:0] new_wdata= u_new.u_cpu.perip_wdata;
    wire [31:0] new_rdata= u_new.perip_rdata;

    wire [31:0] old_addr = u_old.u_cpu.perip_addr;
    wire        old_wen  = u_old.u_cpu.perip_wen;
    wire [1:0]  old_mask = u_old.u_cpu.perip_mask;
    wire [31:0] old_wdata= u_old.u_cpu.perip_wdata;
    wire [31:0] old_rdata= u_old.perip_rdata;

    // EXMEM registers to see what's in MEM stage
    wire        new_exmem_mem_read  = u_new.u_cpu.exmem_a_mem_read;
    wire        new_exmem_mem_write = u_new.u_cpu.exmem_a_mem_write;
    wire [31:0] new_exmem_alu      = u_new.u_cpu.exmem_a_alu_result;
    wire [2:0]  new_exmem_funct3   = u_new.u_cpu.exmem_a_mem_funct3;
    wire [4:0]  new_exmem_rd       = u_new.u_cpu.exmem_a_rd_addr;

    wire        old_exmem_mem_read  = u_old.u_cpu.exmem_mem_read;
    wire        old_exmem_mem_write = u_old.u_cpu.exmem_mem_write;
    wire [31:0] old_exmem_alu      = u_old.u_cpu.exmem_alu_result;
    wire [2:0]  old_exmem_funct3   = u_old.u_cpu.exmem_mem_funct3;
    wire [4:0]  old_exmem_rd       = u_old.u_cpu.exmem_rd_addr;

    // MEMWB to see what WB gets
    wire        new_memwb_rw   = u_new.u_cpu.memwb_a_reg_write;
    wire [4:0]  new_memwb_rd   = u_new.u_cpu.memwb_a_rd_addr;
    wire [31:0] new_memwb_data = u_new.u_cpu.memwb_a_write_data;

    wire        old_memwb_rw   = u_old.u_cpu.memwb_reg_write;
    wire [4:0]  old_memwb_rd   = u_old.u_cpu.memwb_rd_addr;
    wire [31:0] old_memwb_data = u_old.u_cpu.memwb_write_data;

    // PC and stall
    wire [31:0] new_pc = u_new.u_cpu.u_if.pc_out;
    wire [31:0] old_pc = u_old.u_cpu.u_if.pc_out;
    wire new_stall = u_new.u_cpu.pipeline_stall;
    wire old_stall = u_old.u_cpu.pipeline_stall;
    wire new_flush = u_new.u_cpu.flush;
    wire old_flush = u_old.u_cpu.flush;

    // stage_mem read data outputs
    wire [31:0] new_mem_rdata_a = u_new.u_cpu.mem_read_data_a;
    wire [31:0] old_mem_rdata   = u_old.u_cpu.mem_read_data;

    integer cycle = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            if (cycle >= 3 && cycle <= 12) begin
                $display("C%03d NEW: PC=%08h stl=%b fl=%b | exmem: mr=%b mw=%b alu=%08h f3=%03b rd=%02d | bus: addr=%08h wen=%b mask=%b wdata=%08h rdata=%08h | mem_rdata_a=%08h | memwb: rw=%b rd=%02d data=%08h",
                    cycle, new_pc, new_stall, new_flush,
                    new_exmem_mem_read, new_exmem_mem_write, new_exmem_alu, new_exmem_funct3, new_exmem_rd,
                    new_addr, new_wen, new_mask, new_wdata, new_rdata,
                    new_mem_rdata_a,
                    new_memwb_rw, new_memwb_rd, new_memwb_data);
                $display("C%03d OLD: PC=%08h stl=%b fl=%b | exmem: mr=%b mw=%b alu=%08h f3=%03b rd=%02d | bus: addr=%08h wen=%b mask=%b wdata=%08h rdata=%08h | mem_rdata=%08h | memwb: rw=%b rd=%02d data=%08h",
                    cycle, old_pc, old_stall, old_flush,
                    old_exmem_mem_read, old_exmem_mem_write, old_exmem_alu, old_exmem_funct3, old_exmem_rd,
                    old_addr, old_wen, old_mask, old_wdata, old_rdata,
                    old_mem_rdata,
                    old_memwb_rw, old_memwb_rd, old_memwb_data);
            end

            // Focus on the load at cycles 54-60
            if (cycle >= 54 && cycle <= 62) begin
                $display("C%03d NEW: PC=%08h stl=%b fl=%b | exmem: mr=%b mw=%b alu=%08h f3=%03b rd=%02d | bus: addr=%08h wen=%b mask=%b rdata=%08h | mem_rdata_a=%08h | memwb: rw=%b rd=%02d data=%08h",
                    cycle, new_pc, new_stall, new_flush,
                    new_exmem_mem_read, new_exmem_mem_write, new_exmem_alu, new_exmem_funct3, new_exmem_rd,
                    new_addr, new_wen, new_mask, new_rdata,
                    new_mem_rdata_a,
                    new_memwb_rw, new_memwb_rd, new_memwb_data);
                $display("C%03d OLD: PC=%08h stl=%b fl=%b | exmem: mr=%b mw=%b alu=%08h f3=%03b rd=%02d | bus: addr=%08h wen=%b mask=%b rdata=%08h | mem_rdata=%08h | memwb: rw=%b rd=%02d data=%08h",
                    cycle, old_pc, old_stall, old_flush,
                    old_exmem_mem_read, old_exmem_mem_write, old_exmem_alu, old_exmem_funct3, old_exmem_rd,
                    old_addr, old_wen, old_mask, old_rdata,
                    old_mem_rdata,
                    old_memwb_rw, old_memwb_rd, old_memwb_data);
            end

            if (cycle == 65) $finish;
        end
    end
endmodule
