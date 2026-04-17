// Debug testbench: trace pipeline state to find dual-issue bugs.
// Traces around the point where the CPU gets stuck.
`timescale 1ns/1ps

module tb_debug_dual;

    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    sim_soc u_soc (.clk(clk), .rst_n(rst_n));

    integer ii;
    initial begin
        for (ii = 0; ii < 4096; ii = ii + 1)
            u_soc.imem[ii] = 32'h0000_0013;
        for (ii = 0; ii < 65536; ii = ii + 1)
            u_soc.dmem[ii] = 32'h0;
        $readmemh("src0_irom.hex", u_soc.imem);
        $readmemh("src0_dram.hex", u_soc.dmem);
        rst_n = 0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1;
    end

    wire [31:0] pc       = u_soc.u_cpu.u_if.pc_out;
    wire [31:0] inst_a   = u_soc.u_cpu.u_if.inst_a;
    wire [31:0] inst_b   = u_soc.u_cpu.u_if.inst_b;
    wire        bv_if    = u_soc.u_cpu.u_if.b_valid;
    wire        pred_a   = u_soc.u_cpu.u_if.predicted_a;
    wire        can_dual = u_soc.u_cpu.u_if.can_dual_raw;
    wire        can_fin  = u_soc.u_cpu.u_if.can_dual_final;
    wire        stall    = u_soc.u_cpu.pipeline_stall;
    wire        flush    = u_soc.u_cpu.flush;
    wire        hz_stall = u_soc.u_cpu.hz_stall;
    wire        ex_stall = u_soc.u_cpu.ex_stall;

    // ID/EX outputs
    wire [31:0] idex_a_pc = u_soc.u_cpu.idex_a_pc;
    wire        idex_b_v  = u_soc.u_cpu.idex_b_valid;
    wire [4:0]  idex_a_rd = u_soc.u_cpu.idex_a_rd_addr;
    wire [4:0]  idex_b_rd = u_soc.u_cpu.idex_b_rd_addr;
    wire        idex_a_rw = u_soc.u_cpu.idex_a_reg_write;
    wire        idex_b_rw = u_soc.u_cpu.idex_b_reg_write;
    wire        idex_a_mr = u_soc.u_cpu.idex_a_mem_read;
    wire        idex_a_mw = u_soc.u_cpu.idex_a_mem_write;
    wire        idex_b_mr = u_soc.u_cpu.idex_b_mem_read;
    wire        idex_b_mw = u_soc.u_cpu.idex_b_mem_write;

    // EX/MEM
    wire        exmem_b_v = u_soc.u_cpu.exmem_b_valid;
    wire [4:0]  exmem_a_rd= u_soc.u_cpu.exmem_a_rd_addr;
    wire [4:0]  exmem_b_rd= u_soc.u_cpu.exmem_b_rd_addr;

    // MEM/WB
    wire        memwb_b_v = u_soc.u_cpu.memwb_b_valid;
    wire [4:0]  memwb_a_rd= u_soc.u_cpu.memwb_a_rd_addr;
    wire [4:0]  memwb_b_rd= u_soc.u_cpu.memwb_b_rd_addr;
    wire        memwb_a_rw= u_soc.u_cpu.memwb_a_reg_write;
    wire        memwb_b_rw= u_soc.u_cpu.memwb_b_reg_write;
    wire [31:0] memwb_a_wd= u_soc.u_cpu.memwb_a_write_data;
    wire [31:0] memwb_b_wd= u_soc.u_cpu.memwb_b_write_data;

    // Forwarding
    wire [2:0] fwd_a1 = u_soc.u_cpu.fwd_a_rs1;
    wire [2:0] fwd_a2 = u_soc.u_cpu.fwd_a_rs2;
    wire [2:0] fwd_b1 = u_soc.u_cpu.fwd_b_rs1;
    wire [2:0] fwd_b2 = u_soc.u_cpu.fwd_b_rs2;

    reg [63:0] cyc = 0;
    reg [31:0] stable = 0;
    reg [31:0] prev_pc = 32'hFFFFFFFF;
    reg [31:0] prev2 = 32'hFFFFFFFF;
    reg [31:0] prev3 = 32'hFFFFFFFF;

    // Trace control: trace the last 300 cycles before stuck detection
    reg tracing = 0;

    always @(posedge clk) begin
        if (!rst_n) begin
            cyc <= 0; stable <= 0;
            prev_pc <= 32'hFFFFFFFF; prev2 <= 32'hFFFFFFFF; prev3 <= 32'hFFFFFFFF;
        end else begin
            cyc <= cyc + 1;

            if (pc == prev3 && pc != 32'hFFFFFFFF)
                stable <= stable + 1;
            else
                stable <= 0;

            prev3 <= prev2; prev2 <= prev_pc; prev_pc <= pc;

            // Start tracing ~300 cycles before the expected stuck point
            if (cyc > 736000 || tracing) begin
                tracing <= 1;
                $display("C%0d PC=%h A=%h B=%h bv=%b cd=%b cf=%b pa=%b | stl=%b fl=%b hz=%b ex=%b | EX:bv=%b rd_a=x%0d rd_b=x%0d rw_a=%b rw_b=%b mr_a=%b mw_a=%b mr_b=%b mw_b=%b | MEM:bv=%b | WB:bv=%b a_rd=x%0d(%b)=%h b_rd=x%0d(%b)=%h | fwd:%b%b%b%b",
                    cyc, pc, inst_a, inst_b, bv_if, can_dual, can_fin, pred_a,
                    stall, flush, hz_stall, ex_stall,
                    idex_b_v, idex_a_rd, idex_b_rd, idex_a_rw, idex_b_rw, idex_a_mr, idex_a_mw, idex_b_mr, idex_b_mw,
                    exmem_b_v,
                    memwb_b_v, memwb_a_rd, memwb_a_rw, memwb_a_wd, memwb_b_rd, memwb_b_rw, memwb_b_wd,
                    fwd_a1, fwd_a2, fwd_b1, fwd_b2);
            end

            if (stable >= 20) begin
                $display("\n=== STUCK at PC=%h after %0d cycles ===", pc, cyc);
                dump_regs;
                $finish;
            end
            if (cyc >= 800000) begin
                $display("\n=== TIMEOUT at %0d cycles, PC=%h ===", cyc, pc);
                dump_regs;
                $finish;
            end
        end
    end

    task dump_regs;
        integer k; reg [31:0] rv;
        begin
            for (k = 0; k < 32; k = k + 1) begin
                if (k == 0) rv = 0; else rv = u_soc.u_cpu.u_stage_id.regfile[k];
                if (rv !== 32'h0) $display("  x%0d = 0x%08h", k, rv);
            end
        end
    endtask

endmodule
