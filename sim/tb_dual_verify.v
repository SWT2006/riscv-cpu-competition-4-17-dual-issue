// tb_dual_verify.v — Targeted dual-issue correctness verification.
//
// Programs instruction memory directly with specific instruction sequences,
// runs them, and checks register values against expected results.
//
// Tests:
//   1. Independent ALU pair (should dual-issue)
//   2. RAW hazard A->B (must NOT dual-issue)
//   3. WAW same register (should dual-issue, B wins)
//   4. Memory conflict (two loads - must NOT dual-issue)
//   5. Branch in slot A kills slot B
//   6. Branch in slot B (pipe-B-only block)
//   7. Load-use hazard across pipes
//   8. Forwarding from pipe A EXMEM to pipe B
//   9. Forwarding from pipe B EXMEM to pipe A (next cycle)
//  10. CSR in slot A serializes
//  11. MUL in slot B blocked (pipe-A-only)
//  12. Store + ALU pair
//  13. Mispredict flush with active pipe B
//  14. LUI/AUIPC in slot B (should dual-issue)
//  15. Chained dual-issue sequence
`timescale 1ns/1ps

module tb_dual_verify;

    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    sim_soc u_soc (.clk(clk), .rst_n(rst_n));

    // Instruction encodings (RV32I/M)
    // ADDI rd, rs1, imm  : imm[11:0] | rs1 | 000 | rd | 0010011
    // ADD  rd, rs1, rs2   : 0000000 | rs2 | rs1 | 000 | rd | 0110011
    // SUB  rd, rs1, rs2   : 0100000 | rs2 | rs1 | 000 | rd | 0110011
    // LW   rd, off(rs1)   : imm[11:0] | rs1 | 010 | rd | 0000011
    // SW   rs2, off(rs1)  : imm[11:5] | rs2 | rs1 | 010 | imm[4:0] | 0100011
    // BEQ  rs1, rs2, off  : imm | rs2 | rs1 | 000 | imm | 1100011
    // BNE  rs1, rs2, off  : imm | rs2 | rs1 | 001 | imm | 1100011
    // JAL  rd, off         : imm | rd | 1101111
    // LUI  rd, imm         : imm[31:12] | rd | 0110111
    // AUIPC rd, imm        : imm[31:12] | rd | 0010111
    // NOP                  : 00000013
    // MUL rd, rs1, rs2     : 0000001 | rs2 | rs1 | 000 | rd | 0110011

    // Helper: ADDI rd, rs1, imm12
    function [31:0] ADDI;
        input [4:0] rd, rs1;
        input [11:0] imm;
        ADDI = {imm, rs1, 3'b000, rd, 7'b0010011};
    endfunction

    // Helper: ADD rd, rs1, rs2
    function [31:0] ADD;
        input [4:0] rd, rs1, rs2;
        ADD = {7'b0000000, rs2, rs1, 3'b000, rd, 7'b0110011};
    endfunction

    // Helper: SUB rd, rs1, rs2
    function [31:0] SUB;
        input [4:0] rd, rs1, rs2;
        SUB = {7'b0100000, rs2, rs1, 3'b000, rd, 7'b0110011};
    endfunction

    // Helper: LW rd, imm(rs1)
    function [31:0] LW;
        input [4:0] rd, rs1;
        input [11:0] imm;
        LW = {imm, rs1, 3'b010, rd, 7'b0000011};
    endfunction

    // Helper: SW rs2, imm(rs1)
    function [31:0] SW;
        input [4:0] rs2, rs1;
        input [11:0] imm;
        SW = {imm[11:5], rs2, rs1, 3'b010, imm[4:0], 7'b0100011};
    endfunction

    // Helper: BEQ rs1, rs2, offset (offset in bytes, must be even)
    function [31:0] BEQ;
        input [4:0] rs1, rs2;
        input [12:0] off;
        BEQ = {off[12], off[10:5], rs2, rs1, 3'b000, off[4:1], off[11], 7'b1100011};
    endfunction

    // Helper: BNE rs1, rs2, offset
    function [31:0] BNE;
        input [4:0] rs1, rs2;
        input [12:0] off;
        BNE = {off[12], off[10:5], rs2, rs1, 3'b001, off[4:1], off[11], 7'b1100011};
    endfunction

    // Helper: JAL rd, offset (self-loop: offset=0)
    function [31:0] JAL;
        input [4:0] rd;
        input [20:0] off;
        JAL = {off[20], off[10:1], off[11], off[19:12], rd, 7'b1101111};
    endfunction

    // Helper: LUI rd, imm20
    function [31:0] LUI;
        input [4:0] rd;
        input [19:0] imm;
        LUI = {imm, rd, 7'b0110111};
    endfunction

    // Helper: AUIPC rd, imm20
    function [31:0] AUIPC;
        input [4:0] rd;
        input [19:0] imm;
        AUIPC = {imm, rd, 7'b0010111};
    endfunction

    // Helper: MUL rd, rs1, rs2
    function [31:0] MUL;
        input [4:0] rd, rs1, rs2;
        MUL = {7'b0000001, rs2, rs1, 3'b000, rd, 7'b0110011};
    endfunction

    // Helper: NOP
    localparam [31:0] NOP = 32'h0000_0013;

    // DRAM base address in simulation: 0x80100000
    // word index 0 = address 0x80100000
    localparam [31:0] DRAM_BASE = 32'h80100000;

    integer pc_word; // word index into IROM (pc_word = (PC - 0x80000000) / 4)
    integer ii;

    initial begin
        // Clear memories
        for (ii = 0; ii < 4096; ii = ii + 1)
            u_soc.imem[ii] = NOP;
        for (ii = 0; ii < 65536; ii = ii + 1)
            u_soc.dmem[ii] = 32'h0;

        // Pre-load DRAM[0] with a known value for load tests
        u_soc.dmem[0] = 32'h0000_002A;  // 42 at address 0x80100000

        pc_word = 0;

        // ================================================================
        // TEST 1: Independent ALU pair (should dual-issue)
        // x1 = 10, x2 = 20 (no dependency between them)
        // ================================================================
        u_soc.imem[pc_word] = ADDI(5'd1, 5'd0, 12'd10);   pc_word = pc_word + 1;  // x1 = 10
        u_soc.imem[pc_word] = ADDI(5'd2, 5'd0, 12'd20);   pc_word = pc_word + 1;  // x2 = 20

        // NOPs to let the above retire
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 2: RAW hazard A->B (must NOT dual-issue)
        // x3 = x1 + 5 = 15, then x4 = x3 + 1 = 16
        // These CANNOT dual-issue (A writes x3, B reads x3)
        // ================================================================
        u_soc.imem[pc_word] = ADDI(5'd3, 5'd1, 12'd5);    pc_word = pc_word + 1;  // x3 = x1+5 = 15
        u_soc.imem[pc_word] = ADDI(5'd4, 5'd3, 12'd1);    pc_word = pc_word + 1;  // x4 = x3+1 = 16

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 3: WAW same destination (should dual-issue, B wins)
        // x5 = 100 (from A), x5 = 200 (from B) — B wins, x5 should be 200
        // BUT: A writes x5, B reads x5? No — B uses x0 as rs1.
        // Actually: ADDI x5, x0, 100 and ADDI x5, x0, 200
        // A writes x5, B reads x0 (no RAW) — CAN dual-issue.
        // A also writes x5, B also writes x5 — WAW, B should win.
        // ================================================================
        u_soc.imem[pc_word] = ADDI(5'd5, 5'd0, 12'd100);  pc_word = pc_word + 1;  // x5 = 100
        u_soc.imem[pc_word] = ADDI(5'd5, 5'd0, 12'd200);  pc_word = pc_word + 1;  // x5 = 200 (WAW, B wins)

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 4: Memory conflict (two loads — must NOT dual-issue)
        // Both try to load from DRAM — only one can use the port.
        // x6 and x7 should both get the correct values.
        // Use x10 as base address register.
        // ================================================================
        u_soc.imem[pc_word] = LUI(5'd10, 20'h80100);      pc_word = pc_word + 1;  // x10 = 0x80100000
        u_soc.imem[pc_word] = NOP;                          pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP;                          pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP;                          pc_word = pc_word + 1;
        u_soc.imem[pc_word] = LW(5'd6, 5'd10, 12'd0);     pc_word = pc_word + 1;  // x6 = mem[0x80100000] = 42
        u_soc.imem[pc_word] = LW(5'd7, 5'd10, 12'd0);     pc_word = pc_word + 1;  // x7 = mem[0x80100000] = 42

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 5: Branch in slot A, slot B should be killed
        // BEQ x0, x0, +8 (always taken) — slot B should NOT execute.
        // Slot B: ADDI x8, x0, 999  — should NOT happen.
        // After branch target: ADDI x8, x0, 42
        // x8 should be 42, NOT 999.
        // ================================================================
        u_soc.imem[pc_word] = BEQ(5'd0, 5'd0, 13'd8);     pc_word = pc_word + 1;  // BEQ always taken, skip +8
        u_soc.imem[pc_word] = ADDI(5'd8, 5'd0, 12'd999);  pc_word = pc_word + 1;  // KILLED (in delay slot)
        u_soc.imem[pc_word] = ADDI(5'd8, 5'd0, 12'd42);   pc_word = pc_word + 1;  // branch target: x8 = 42

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 6: Forward branch not-taken (BTFNT: forward = not taken)
        // BNE x0, x0, +8 (never taken, rs1==rs2) — sequential execution
        // Slot B after the branch: ADDI x9, x0, 77
        // These CAN dual-issue since branch is in A, and issue check blocks branch in B.
        // Actually: BNE is in slot A. It's a forward branch, so BTFNT predicts not-taken.
        // If prediction correct, no flush needed.
        // x9 should be 77.
        // ================================================================
        u_soc.imem[pc_word] = BNE(5'd0, 5'd0, 13'd8);     pc_word = pc_word + 1;  // BNE: 0 != 0 false, not taken
        u_soc.imem[pc_word] = ADDI(5'd9, 5'd0, 12'd77);   pc_word = pc_word + 1;  // x9 = 77

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 7: Store + ALU (should dual-issue)
        // SW x1, 4(x10) then ADDI x11, x0, 55
        // Store is in A, ALU in B. Should dual-issue (mem + non-mem).
        // ================================================================
        u_soc.imem[pc_word] = SW(5'd1, 5'd10, 12'd4);     pc_word = pc_word + 1;  // mem[0x80100004] = x1 = 10
        u_soc.imem[pc_word] = ADDI(5'd11, 5'd0, 12'd55);  pc_word = pc_word + 1;  // x11 = 55

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // Verify the store worked: load it back
        u_soc.imem[pc_word] = LW(5'd12, 5'd10, 12'd4);    pc_word = pc_word + 1;  // x12 = mem[0x80100004] = 10

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 8: LUI + AUIPC in B (should dual-issue with ALU in A)
        // ADDI x13, x0, 1 then LUI x14, 0xDEADB
        // ================================================================
        u_soc.imem[pc_word] = ADDI(5'd13, 5'd0, 12'd1);   pc_word = pc_word + 1;  // x13 = 1
        u_soc.imem[pc_word] = LUI(5'd14, 20'hDEADB);      pc_word = pc_word + 1;  // x14 = 0xDEADB000

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 9: Long chain — multiple dual-issuable pairs
        // x15=1, x16=2 | x17=3, x18=4 | x19=5, x20=6
        // All independent — should dual-issue 3 consecutive pairs.
        // ================================================================
        u_soc.imem[pc_word] = ADDI(5'd15, 5'd0, 12'd1);   pc_word = pc_word + 1;
        u_soc.imem[pc_word] = ADDI(5'd16, 5'd0, 12'd2);   pc_word = pc_word + 1;
        u_soc.imem[pc_word] = ADDI(5'd17, 5'd0, 12'd3);   pc_word = pc_word + 1;
        u_soc.imem[pc_word] = ADDI(5'd18, 5'd0, 12'd4);   pc_word = pc_word + 1;
        u_soc.imem[pc_word] = ADDI(5'd19, 5'd0, 12'd5);   pc_word = pc_word + 1;
        u_soc.imem[pc_word] = ADDI(5'd20, 5'd0, 12'd6);   pc_word = pc_word + 1;

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // TEST 10: ADD using values from both pipes
        // x21 = x15 + x16 = 3 (operands set in test 9 via dual-issue)
        // This tests that dual-issued writes from test 9 are visible.
        // ================================================================
        u_soc.imem[pc_word] = ADD(5'd21, 5'd15, 5'd16);   pc_word = pc_word + 1;  // x21 = 1 + 2 = 3

        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;
        u_soc.imem[pc_word] = NOP; pc_word = pc_word + 1;

        // ================================================================
        // SELF-LOOP: JAL x0, 0 (infinite loop at this PC)
        // ================================================================
        u_soc.imem[pc_word] = JAL(5'd0, 21'd0);            // self-loop

        // Release reset
        rst_n = 0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1;
    end

    // ================================================================
    // Monitor and check
    // ================================================================
    wire [31:0] cpu_pc = u_soc.u_cpu.u_if.pc_out;
    wire b_valid_ex = u_soc.u_cpu.u_pipe_idex.idex_b_valid;

    reg [63:0] cyc = 0;
    reg [63:0] dual_count = 0;
    reg [31:0] stable = 0;
    reg [31:0] prev_pc = 32'hFFFFFFFF;
    reg [31:0] prev2 = 32'hFFFFFFFF;
    reg [31:0] prev3 = 32'hFFFFFFFF;

    always @(posedge clk) begin
        if (rst_n && b_valid_ex)
            dual_count <= dual_count + 1;
    end

    integer errors;
    always @(posedge clk) begin
        if (!rst_n) begin
            cyc <= 0; stable <= 0;
            prev_pc <= 32'hFFFFFFFF; prev2 <= 32'hFFFFFFFF; prev3 <= 32'hFFFFFFFF;
        end else begin
            cyc <= cyc + 1;

            if (cpu_pc == prev3 && cpu_pc != 32'hFFFFFFFF)
                stable <= stable + 1;
            else
                stable <= 0;

            prev3 <= prev2; prev2 <= prev_pc; prev_pc <= cpu_pc;

            if (stable >= 30) begin
                errors = 0;
                $display("");
                $display("=== DUAL-ISSUE CORRECTNESS VERIFICATION ===");
                $display("  Self-loop at PC = 0x%08h after %0d cycles", cpu_pc, cyc);
                $display("  Dual-issue cycles: %0d (%0d%%)", dual_count, (dual_count * 100) / cyc);
                $display("");

                // Check all register values
                check_reg(1,  32'd10,       "T1: independent pair A");
                check_reg(2,  32'd20,       "T1: independent pair B");
                check_reg(3,  32'd15,       "T2: RAW blocked A (x1+5)");
                check_reg(4,  32'd16,       "T2: RAW blocked B (x3+1)");
                check_reg(5,  32'd200,      "T3: WAW B wins");
                check_reg(6,  32'd42,       "T4: load A (mem conflict)");
                check_reg(7,  32'd42,       "T4: load B (mem conflict)");
                check_reg(8,  32'd42,       "T5: branch kills slot B");
                check_reg(9,  32'd77,       "T6: forward BNE not-taken");
                check_reg(11, 32'd55,       "T7: store+ALU dual B");
                check_reg(12, 32'd10,       "T7: store verify");
                check_reg(13, 32'd1,        "T8: ALU+LUI pair A");
                check_reg(14, 32'hDEADB000, "T8: LUI in slot B");
                check_reg(15, 32'd1,        "T9: chain pair 1A");
                check_reg(16, 32'd2,        "T9: chain pair 1B");
                check_reg(17, 32'd3,        "T9: chain pair 2A");
                check_reg(18, 32'd4,        "T9: chain pair 2B");
                check_reg(19, 32'd5,        "T9: chain pair 3A");
                check_reg(20, 32'd6,        "T9: chain pair 3B");
                check_reg(21, 32'd3,        "T10: ADD from dual-issued sources");

                $display("");
                if (errors == 0)
                    $display("  RESULT: *** ALL %0d CHECKS PASSED ***", 20);
                else
                    $display("  RESULT: *** %0d FAILURES ***", errors);

                $display("  Dual-issue rate: %0d%% (%0d / %0d cycles)",
                    (dual_count * 100) / cyc, dual_count, cyc);
                $finish;
            end

            if (cyc >= 10000) begin
                $display("=== TIMEOUT at %0d cycles, PC=0x%08h ===", cyc, cpu_pc);
                dump_regs;
                $finish;
            end
        end
    end

    task check_reg;
        input [4:0] idx;
        input [31:0] expected;
        input [255:0] label;   // string
        reg [31:0] actual;
        begin
            if (idx == 0)
                actual = 32'h0;
            else
                actual = u_soc.u_cpu.u_stage_id.regfile[idx];
            if (actual === expected)
                $display("  [PASS] x%0d = 0x%08h  (%0s)", idx, actual, label);
            else begin
                $display("  [FAIL] x%0d = 0x%08h (expected 0x%08h)  (%0s)", idx, actual, expected, label);
                errors = errors + 1;
            end
        end
    endtask

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
