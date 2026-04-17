`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`timescale 1ns/1ps

module tb_compare5;
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

    // NEW design forwarding signals
    wire [2:0] new_fwd_a_rs1 = u_new.u_cpu.fwd_a_rs1;
    wire [2:0] new_fwd_a_rs2 = u_new.u_cpu.fwd_a_rs2;

    // NEW design exmem forwarding data
    wire [31:0] new_exmem_fwd_data = u_new.u_cpu.exmem_a_fwd_data;
    wire        new_exmem_rw       = u_new.u_cpu.exmem_a_reg_write;
    wire [4:0]  new_exmem_rd       = u_new.u_cpu.exmem_a_rd_addr;
    wire [31:0] new_exmem_alu      = u_new.u_cpu.exmem_a_alu_result;

    // NEW memwb
    wire        new_memwb_rw       = u_new.u_cpu.memwb_a_reg_write;
    wire [4:0]  new_memwb_rd       = u_new.u_cpu.memwb_a_rd_addr;
    wire [31:0] new_memwb_data     = u_new.u_cpu.memwb_a_write_data;

    // NEW IDEX
    wire [31:0] new_idex_pc        = u_new.u_cpu.idex_a_pc;
    wire [4:0]  new_idex_rs1       = u_new.u_cpu.idex_a_rs1_addr;
    wire [4:0]  new_idex_rd        = u_new.u_cpu.idex_a_rd_addr;
    wire        new_idex_rw        = u_new.u_cpu.idex_a_reg_write;
    wire [31:0] new_idex_rs1_data  = u_new.u_cpu.idex_a_rs1_data;

    // NEW EX outputs
    wire [31:0] new_ex_alu_result  = u_new.u_cpu.ex_a_alu_result;

    // OLD design forwarding
    wire [1:0]  old_fwd_a  = u_old.u_cpu.forward_a;
    wire [31:0] old_exmem_fwd = u_old.u_cpu.exmem_fwd_data;
    wire        old_exmem_rw  = u_old.u_cpu.exmem_reg_write;
    wire [4:0]  old_exmem_rd  = u_old.u_cpu.exmem_rd_addr;
    wire [31:0] old_exmem_alu = u_old.u_cpu.exmem_alu_result;

    wire [31:0] old_memwb_data = u_old.u_cpu.memwb_write_data;
    wire        old_memwb_rw   = u_old.u_cpu.memwb_reg_write;
    wire [4:0]  old_memwb_rd   = u_old.u_cpu.memwb_rd_addr;

    wire [31:0] old_idex_pc    = u_old.u_cpu.idex_pc;
    wire [4:0]  old_idex_rs1   = u_old.u_cpu.idex_rs1_addr;
    // removed old internal ref

    wire [31:0] new_pc = u_new.u_cpu.u_if.pc_out;
    wire        new_stall = u_new.u_cpu.pipeline_stall;
    wire        new_flush = u_new.u_cpu.flush;
    wire        new_hz_stall = u_new.u_cpu.hz_stall;

    integer cycle = 0;

    always @(posedge clk) begin
        if (rst_n) begin
            cycle <= cycle + 1;

            if (cycle >= 54 && cycle <= 60) begin
                $display("=== C%03d hz=%b stl=%b fl=%b ===", cycle, new_hz_stall, new_stall, new_flush);

                $display("  NEW idex: pc=%08h rs1=%02d rs1_data=%08h rd=%02d rw=%b",
                    new_idex_pc, new_idex_rs1, new_idex_rs1_data, new_idex_rd, new_idex_rw);
                $display("  NEW exmem: rd=%02d rw=%b alu=%08h fwd=%08h",
                    new_exmem_rd, new_exmem_rw, new_exmem_alu, new_exmem_fwd_data);
                $display("  NEW memwb: rd=%02d rw=%b data=%08h",
                    new_memwb_rd, new_memwb_rw, new_memwb_data);
                $display("  NEW fwd: a_rs1=%03b a_rs2=%03b | ex_alu=%08h",
                    new_fwd_a_rs1, new_fwd_a_rs2, new_ex_alu_result);

                $display("  OLD idex: pc=%08h rs1=%02d",
                    old_idex_pc, old_idex_rs1);
                $display("  OLD exmem: rd=%02d rw=%b alu=%08h fwd=%08h",
                    old_exmem_rd, old_exmem_rw, old_exmem_alu, old_exmem_fwd);
                $display("  OLD memwb: rd=%02d rw=%b data=%08h",
                    old_memwb_rd, old_memwb_rw, old_memwb_data);
                $display("  OLD fwd: a=%02b",
                    old_fwd_a);
            end

            if (cycle == 62) $finish;
        end
    end
endmodule
