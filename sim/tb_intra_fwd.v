`timescale 1ns/1ps
// Test: Intra-group A→B forwarding
// Validates that when A is a fast ALU op writing rd, and B reads rd,
// the pair dual-issues correctly with A's result forwarded to B in the same cycle.
module tb_intra_fwd;
    reg clk, rst_n;
    always #5 clk = ~clk;

    sim_soc u_soc (.clk(clk), .rst_n(rst_n));

    // Monitor for self-loop
    reg [31:0] prev_pc;
    integer stable;
    always @(posedge clk) begin
        if (u_soc.u_cpu.irom_addr == prev_pc)
            stable <= stable + 1;
        else begin
            stable <= 0;
            prev_pc <= u_soc.u_cpu.irom_addr;
        end
    end

    integer cycle_count;
    always @(posedge clk) if (rst_n) cycle_count <= cycle_count + 1;

    // Count dual-issue cycles
    integer dual_count;
    always @(posedge clk) begin
        if (rst_n && u_soc.u_cpu.u_ex.idex_b_valid)
            dual_count <= dual_count + 1;
    end

    integer pass_count;
    integer fail_count;

    task check;
        input [4:0] reg_num;
        input [31:0] expected;
        input [255:0] label;
        reg [31:0] actual;
        begin
            actual = (reg_num == 0) ? 32'b0 : u_soc.u_cpu.u_stage_id.regfile[reg_num];
            if (actual === expected) begin
                $display("  [PASS] x%0d = 0x%08x  (%0s)", reg_num, actual, label);
                pass_count = pass_count + 1;
            end else begin
                $display("  [FAIL] x%0d = 0x%08x  expected 0x%08x  (%0s)", reg_num, actual, expected, label);
                fail_count = fail_count + 1;
            end
        end
    endtask

    localparam BASE = 32'h8000_0000;
    integer i;

    initial begin
        clk = 0; rst_n = 0; stable = 0; prev_pc = 0;
        cycle_count = 0; dual_count = 0;
        pass_count = 0; fail_count = 0;

        // Clear memories
        for (i = 0; i < 4096; i = i + 1) u_soc.imem[i] = 32'h0000_0013;
        for (i = 0; i < 65536; i = i + 1) u_soc.dmem[i] = 32'h0;
        i = 0;

        // =================================================================
        // T1: Basic ADDI → ADD chain (A writes x1, B reads x1)
        // ADDI x1, x0, 10     =>  x1 = 10
        // ADD  x2, x1, x0     =>  x2 = 10 (forwarded from A)
        // =================================================================
        u_soc.imem[i] = 32'h00A00093; i=i+1; // addi x1, x0, 10
        u_soc.imem[i] = 32'h00008133; i=i+1; // add  x2, x1, x0

        // =================================================================
        // T2: ADDI → ADDI chain (A writes x3, B reads x3)
        // ADDI x3, x0, 20     =>  x3 = 20
        // ADDI x4, x3, 5      =>  x4 = 25
        // =================================================================
        u_soc.imem[i] = 32'h01400193; i=i+1; // addi x3, x0, 20
        u_soc.imem[i] = 32'h00518213; i=i+1; // addi x4, x3, 5

        // =================================================================
        // T3: R-type → ADD chain (SUB writes x5, ADD reads x5)
        // ADDI x6, x0, 50     =>  x6 = 50
        // NOP (padding to separate from above)
        // ADDI x7, x0, 20     =>  x7 = 20
        // NOP
        // SUB  x5, x6, x7     =>  x5 = 30
        // ADD  x8, x5, x0     =>  x8 = 30 (forwarded from A)
        // =================================================================
        u_soc.imem[i] = 32'h03200313; i=i+1; // addi x6, x0, 50
        u_soc.imem[i] = 32'h00000013; i=i+1; // nop
        u_soc.imem[i] = 32'h01400393; i=i+1; // addi x7, x0, 20
        u_soc.imem[i] = 32'h00000013; i=i+1; // nop
        u_soc.imem[i] = 32'h407302B3; i=i+1; // sub  x5, x6, x7
        u_soc.imem[i] = 32'h00028433; i=i+1; // add  x8, x5, x0

        // =================================================================
        // T4: LUI → ADD chain (LUI writes x9, ADD reads x9)
        // LUI  x9, 0xABCDE    =>  x9 = 0xABCDE000
        // ADD  x10, x9, x0    =>  x10 = 0xABCDE000 (forwarded)
        // =================================================================
        u_soc.imem[i] = 32'hABCDE4B7; i=i+1; // lui  x9, 0xABCDE
        u_soc.imem[i] = 32'h00048533; i=i+1; // add  x10, x9, x0

        // =================================================================
        // T5: AUIPC → ADD chain (AUIPC writes x11, ADD reads x11)
        // Current PC = BASE + i*4.  AUIPC x11, 0 => x11 = PC
        // ADD x12, x11, x0   => x12 = PC (forwarded)
        // =================================================================
        u_soc.imem[i] = 32'h00000597; i=i+1; // auipc x11, 0  => x11 = BASE + 10*4 = BASE+0x28
        u_soc.imem[i] = 32'h00058633; i=i+1; // add   x12, x11, x0

        // =================================================================
        // T6: Triple chain: A→B in cycle1, then result in B→A next pair
        // ADDI x13, x0, 3     =>  x13 = 3
        // ADDI x14, x13, 7    =>  x14 = 10 (intra-group from A)
        // ADDI x15, x14, 5    =>  x15 = 15 (uses x14 from prior pair's B)
        // ADD  x16, x15, x13  =>  x16 = 18 (intra-group from A; x13=3 via regfile or fwd)
        // =================================================================
        u_soc.imem[i] = 32'h00300693; i=i+1; // addi x13, x0, 3
        u_soc.imem[i] = 32'h00768713; i=i+1; // addi x14, x13, 7
        u_soc.imem[i] = 32'h00570793; i=i+1; // addi x15, x14, 5
        u_soc.imem[i] = 32'h00D78833; i=i+1; // add  x16, x15, x13

        // =================================================================
        // T7: A→B with B being a STORE (A writes x17, B uses x17 as store data)
        // ADDI x17, x0, 99
        // SW   x17, 0(x6)     => store 99 to addr 50... wait, need DRAM addr
        // Use DRAM base 0x80100000
        // =================================================================
        u_soc.imem[i] = 32'h80100937; i=i+1; // lui  x18, 0x80100  => x18 = 0x80100000
        u_soc.imem[i] = 32'h00000013; i=i+1; // nop
        u_soc.imem[i] = 32'h06300893; i=i+1; // addi x17, x0, 99
        u_soc.imem[i] = 32'h01192023; i=i+1; // sw   x17, 0(x18)  => store 99 to DRAM[0]

        // Verify: load back from DRAM[0] into x19
        u_soc.imem[i] = 32'h00000013; i=i+1; // nop (avoid load-use on x18)
        u_soc.imem[i] = 32'h00092983; i=i+1; // lw   x19, 0(x18)

        // =================================================================
        // T8: A→B with BOTH rs1 and rs2 of B matching A's rd
        // ADDI x20, x0, 7     =>  x20 = 7
        // ADD  x21, x20, x20  =>  x21 = 14 (both operands forwarded from A)
        // =================================================================
        u_soc.imem[i] = 32'h00700A13; i=i+1; // addi x20, x0, 7
        u_soc.imem[i] = 32'h014A0AB3; i=i+1; // add  x21, x20, x20

        // =================================================================
        // T9: Long producer-consumer chain (5 dependent pairs)
        // x22 = 1 → x23 = x22+1=2 → x24 = x23+1=3 → x25 = x24+1=4 → x26 = x25+1=5
        // Each pair should dual-issue with intra-group forwarding
        // =================================================================
        u_soc.imem[i] = 32'h00100B13; i=i+1; // addi x22, x0, 1
        u_soc.imem[i] = 32'h001B0B93; i=i+1; // addi x23, x22, 1
        u_soc.imem[i] = 32'h001B8C13; i=i+1; // addi x24, x23, 1
        u_soc.imem[i] = 32'h001C0C93; i=i+1; // addi x25, x24, 1
        u_soc.imem[i] = 32'h001C8D13; i=i+1; // addi x26, x25, 1
        u_soc.imem[i] = 32'h001D0D93; i=i+1; // addi x27, x26, 1

        // =================================================================
        // Self-loop: jump to self
        // =================================================================
        u_soc.imem[i] = 32'h0000006F; i=i+1; // jal x0, 0 (self-loop)

        // Release reset
        #20 rst_n = 1;

        // Wait for self-loop
        wait(stable > 10);
        #10;

        $display("=== INTRA-GROUP A→B FORWARDING TEST ===");
        $display("  Finished after %0d cycles, dual=%0d (%0d%%)",
                 cycle_count, dual_count, (dual_count*100)/cycle_count);

        check(1,  32'h0000_000A, "T1: ADDI x1=10");
        check(2,  32'h0000_000A, "T1: ADD x2=x1(fwd)=10");
        check(3,  32'h0000_0014, "T2: ADDI x3=20");
        check(4,  32'h0000_0019, "T2: ADDI x4=x3(fwd)+5=25");
        check(5,  32'h0000_001E, "T3: SUB x5=50-20=30");
        check(8,  32'h0000_001E, "T3: ADD x8=x5(fwd)=30");
        check(9,  32'hABCDE000, "T4: LUI x9=0xABCDE000");
        check(10, 32'hABCDE000, "T4: ADD x10=x9(fwd)=0xABCDE000");
        check(11, BASE + 32'h30, "T5: AUIPC x11=PC");
        check(12, BASE + 32'h30, "T5: ADD x12=x11(fwd)=PC");
        check(13, 32'h0000_0003, "T6: ADDI x13=3");
        check(14, 32'h0000_000A, "T6: ADDI x14=x13(fwd)+7=10");
        check(15, 32'h0000_000F, "T6: ADDI x15=x14+5=15");
        check(16, 32'h0000_0012, "T6: ADD x16=x15(fwd)+x13=18");
        check(17, 32'h0000_0063, "T7: ADDI x17=99");
        check(19, 32'h0000_0063, "T7: LW x19=store(99 via fwd)");
        check(20, 32'h0000_0007, "T8: ADDI x20=7");
        check(21, 32'h0000_000E, "T8: ADD x21=x20+x20(both fwd)=14");
        check(22, 32'h0000_0001, "T9: x22=1");
        check(23, 32'h0000_0002, "T9: x23=x22+1=2");
        check(24, 32'h0000_0003, "T9: x24=x23+1=3");
        check(25, 32'h0000_0004, "T9: x25=x24+1=4");
        check(26, 32'h0000_0005, "T9: x26=x25+1=5");
        check(27, 32'h0000_0006, "T9: x27=x26+1=6");

        $display("");
        if (fail_count == 0)
            $display("  RESULT: *** ALL %0d CHECKS PASSED ***", pass_count);
        else
            $display("  RESULT: *** %0d FAILED, %0d passed ***", fail_count, pass_count);
        $display("  Dual-issue rate: %0d%% (%0d / %0d cycles)", (dual_count*100)/cycle_count, dual_count, cycle_count);

        $finish;
    end

    // Timeout
    initial begin
        #100000;
        $display("TIMEOUT");
        $finish;
    end
endmodule
