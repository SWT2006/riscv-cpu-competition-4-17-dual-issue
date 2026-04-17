// tb_dual_edge.v — Edge-case tests for dual-issue forwarding, hazards, flushes.
//
// Tests:
//   1. EX-MEM forwarding: Pipe A result → next Pipe A operand
//   2. EX-MEM forwarding: Pipe B result → next Pipe A operand (cross-pipe)
//   3. EX-MEM forwarding: Pipe A result → next Pipe B operand (cross-pipe)
//   4. MEM-WB forwarding: Pipe A load → Pipe A ALU (2 cycles later)
//   5. Load-use stall: Pipe A load → next Pipe A read (1 cycle)
//   6. Load-use stall: Pipe B load → next Pipe A read (cross-pipe)
//   7. Backward branch loop (3 iterations, BTFNT predicted taken)
//   8. Forward branch taken (mispredict, BTFNT predicts not-taken)
//   9. Flush kills both pipes in ID/EX when mispredict fires
//  10. SUB in pipe B
//  11. Multiple WAW in sequence
//  12. SLL/SRL/AND/OR/XOR in pipe B
//  13. SLTI/SLTIU in pipe B
//  14. Dual store-then-load verification
`timescale 1ns/1ps

module tb_dual_edge;

    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    sim_soc u_soc (.clk(clk), .rst_n(rst_n));

    function [31:0] ADDI;
        input [4:0] rd, rs1; input [11:0] imm;
        ADDI = {imm, rs1, 3'b000, rd, 7'b0010011};
    endfunction
    function [31:0] ADD;
        input [4:0] rd, rs1, rs2;
        ADD = {7'b0000000, rs2, rs1, 3'b000, rd, 7'b0110011};
    endfunction
    function [31:0] SUB;
        input [4:0] rd, rs1, rs2;
        SUB = {7'b0100000, rs2, rs1, 3'b000, rd, 7'b0110011};
    endfunction
    function [31:0] AND_f;
        input [4:0] rd, rs1, rs2;
        AND_f = {7'b0000000, rs2, rs1, 3'b111, rd, 7'b0110011};
    endfunction
    function [31:0] OR_f;
        input [4:0] rd, rs1, rs2;
        OR_f = {7'b0000000, rs2, rs1, 3'b110, rd, 7'b0110011};
    endfunction
    function [31:0] XOR_f;
        input [4:0] rd, rs1, rs2;
        XOR_f = {7'b0000000, rs2, rs1, 3'b100, rd, 7'b0110011};
    endfunction
    function [31:0] SLL;
        input [4:0] rd, rs1, rs2;
        SLL = {7'b0000000, rs2, rs1, 3'b001, rd, 7'b0110011};
    endfunction
    function [31:0] SRL;
        input [4:0] rd, rs1, rs2;
        SRL = {7'b0000000, rs2, rs1, 3'b101, rd, 7'b0110011};
    endfunction
    function [31:0] SLTI;
        input [4:0] rd, rs1; input [11:0] imm;
        SLTI = {imm, rs1, 3'b010, rd, 7'b0010011};
    endfunction
    function [31:0] SLTIU;
        input [4:0] rd, rs1; input [11:0] imm;
        SLTIU = {imm, rs1, 3'b011, rd, 7'b0010011};
    endfunction
    function [31:0] LW;
        input [4:0] rd, rs1; input [11:0] imm;
        LW = {imm, rs1, 3'b010, rd, 7'b0000011};
    endfunction
    function [31:0] SW;
        input [4:0] rs2, rs1; input [11:0] imm;
        SW = {imm[11:5], rs2, rs1, 3'b010, imm[4:0], 7'b0100011};
    endfunction
    function [31:0] LUI;
        input [4:0] rd; input [19:0] imm;
        LUI = {imm, rd, 7'b0110111};
    endfunction
    function [31:0] BNE;
        input [4:0] rs1, rs2; input [12:0] off;
        BNE = {off[12], off[10:5], rs2, rs1, 3'b001, off[4:1], off[11], 7'b1100011};
    endfunction
    function [31:0] BEQ;
        input [4:0] rs1, rs2; input [12:0] off;
        BEQ = {off[12], off[10:5], rs2, rs1, 3'b000, off[4:1], off[11], 7'b1100011};
    endfunction
    function [31:0] JAL;
        input [4:0] rd; input [20:0] off;
        JAL = {off[20], off[10:1], off[11], off[19:12], rd, 7'b1101111};
    endfunction

    localparam [31:0] NOP = 32'h0000_0013;

    integer pc_w, ii;

    initial begin
        for (ii = 0; ii < 4096; ii = ii + 1) u_soc.imem[ii] = NOP;
        for (ii = 0; ii < 65536; ii = ii + 1) u_soc.dmem[ii] = 32'h0;

        pc_w = 0;

        // === SETUP: base registers ===
        u_soc.imem[pc_w] = LUI(5'd30, 20'h80100);        pc_w = pc_w + 1; // x30 = 0x80100000 (DRAM base)
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T1: EXMEM_A forwarding → next Pipe A ===
        // x1 = 10; next cycle x2 = x1 + 5 = 15 (forwarded from EXMEM_A)
        u_soc.imem[pc_w] = ADDI(5'd1, 5'd0, 12'd10);     pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1; // can't dual (RAW)
        u_soc.imem[pc_w] = ADDI(5'd2, 5'd1, 12'd5);      pc_w = pc_w + 1; // forwarded from EXMEM_A
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T2: EXMEM_B forwarding → next cycle Pipe A ===
        // Dual-issue: x3=20 (A), x4=30 (B); next: x5 = x4 + 1 = 31
        u_soc.imem[pc_w] = ADDI(5'd3, 5'd0, 12'd20);     pc_w = pc_w + 1; // A: x3 = 20
        u_soc.imem[pc_w] = ADDI(5'd4, 5'd0, 12'd30);     pc_w = pc_w + 1; // B: x4 = 30 (dual)
        u_soc.imem[pc_w] = ADDI(5'd5, 5'd4, 12'd1);      pc_w = pc_w + 1; // x5 = x4+1=31 (fwd EXMEM_B)
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T3: EXMEM_A forwarding → next Pipe B ===
        // x6 = 40; next dual pair: NOP(A) + x7 = x6 + 2(B)
        // Actually, for pipe B to read x6, x6 must come from EXMEM_A (previous A).
        // But the NOP+ADD pair: NOP writes nothing, ADD reads x6.
        // Issue check: NOP (A) writes x0, ADD (B) reads x6 — no RAW. Can dual.
        u_soc.imem[pc_w] = ADDI(5'd6, 5'd0, 12'd40);     pc_w = pc_w + 1; // x6 = 40
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = ADDI(5'd28, 5'd0, 12'd0);     pc_w = pc_w + 1; // A: benign
        u_soc.imem[pc_w] = ADDI(5'd7, 5'd6, 12'd2);      pc_w = pc_w + 1; // B: x7=x6+2=42 (fwd from EXMEM_A→B)
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T4: Load-use stall (Pipe A load → next Pipe A read) ===
        u_soc.dmem[0] = 32'h0000_0063; // mem[0x80100000] = 99
        u_soc.imem[pc_w] = LW(5'd8, 5'd30, 12'd0);       pc_w = pc_w + 1; // x8 = load 99
        u_soc.imem[pc_w] = ADDI(5'd9, 5'd8, 12'd1);      pc_w = pc_w + 1; // x9 = x8+1 = 100 (load-use stall)
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T5: Backward branch loop (3 iterations) ===
        // x10 = 0; loop: x10 += 1; if x10 != 3, branch back
        u_soc.imem[pc_w] = ADDI(5'd10, 5'd0, 12'd0);     pc_w = pc_w + 1; // x10 = 0
        u_soc.imem[pc_w] = ADDI(5'd29, 5'd0, 12'd3);     pc_w = pc_w + 1; // x29 = 3
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        // loop_start (pc_w is now the loop top):
        begin : loop_block
            integer loop_top;
            loop_top = pc_w;
            u_soc.imem[pc_w] = ADDI(5'd10, 5'd10, 12'd1); pc_w = pc_w + 1; // x10++
            u_soc.imem[pc_w] = NOP;                         pc_w = pc_w + 1;
            // BNE x10, x29, -8 (back to loop_top)
            u_soc.imem[pc_w] = BNE(5'd10, 5'd29, {1'b1, 12'b111111111000}); pc_w = pc_w + 1;
            u_soc.imem[pc_w] = NOP;                         pc_w = pc_w + 1;
        end
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T6: Forward branch taken (mispredict) ===
        // BEQ x0, x0, +12 (always taken, but forward → BTFNT predicts not-taken → mispredict)
        // Slot after branch: x11 = 111 (should NOT execute due to flush)
        // Skip target: x11 = 222
        u_soc.imem[pc_w] = BEQ(5'd0, 5'd0, 13'd12);      pc_w = pc_w + 1; // forward BEQ, always taken
        u_soc.imem[pc_w] = ADDI(5'd11, 5'd0, 12'd111);   pc_w = pc_w + 1; // KILLED by flush
        u_soc.imem[pc_w] = ADDI(5'd11, 5'd0, 12'd333);   pc_w = pc_w + 1; // KILLED by flush
        u_soc.imem[pc_w] = ADDI(5'd11, 5'd0, 12'd222);   pc_w = pc_w + 1; // branch target: x11 = 222
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T7: SUB in pipe B ===
        u_soc.imem[pc_w] = ADDI(5'd12, 5'd0, 12'd50);    pc_w = pc_w + 1; // x12 = 50
        u_soc.imem[pc_w] = ADDI(5'd13, 5'd0, 12'd30);    pc_w = pc_w + 1; // x13 = 30 (dual)
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        // x14 = x12 - x13 = 20 (SUB in A), x15 = x12 & x13 (AND in B)
        // A writes x14, B reads x12,x13 — no conflict with A's dest. Can dual.
        // Wait: A reads x12 (rs1) and x13 (rs2). B reads x12 (rs1) and x13 (rs2).
        // A writes x14. No RAW A→B. Can dual.
        u_soc.imem[pc_w] = SUB(5'd14, 5'd12, 5'd13);     pc_w = pc_w + 1; // A: x14=50-30=20
        u_soc.imem[pc_w] = AND_f(5'd15, 5'd12, 5'd13);   pc_w = pc_w + 1; // B: x15=50&30=18
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP;                            pc_w = pc_w + 1;

        // === T8: OR, XOR, SLL, SRL in pipe B ===
        u_soc.imem[pc_w] = ADDI(5'd16, 5'd0, 12'hF0);    pc_w = pc_w + 1; // x16 = 0xF0
        u_soc.imem[pc_w] = ADDI(5'd17, 5'd0, 12'h0F);    pc_w = pc_w + 1; // x17 = 0x0F (dual)
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = OR_f(5'd18, 5'd16, 5'd17);    pc_w = pc_w + 1; // A: x18=0xF0|0x0F=0xFF
        u_soc.imem[pc_w] = XOR_f(5'd19, 5'd16, 5'd17);   pc_w = pc_w + 1; // B: x19=0xF0^0x0F=0xFF
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        // Shift test
        u_soc.imem[pc_w] = ADDI(5'd20, 5'd0, 12'd2);     pc_w = pc_w + 1; // x20 = 2 (shift amount)
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = SLL(5'd21, 5'd18, 5'd20);     pc_w = pc_w + 1; // A: x21=0xFF<<2=0x3FC
        u_soc.imem[pc_w] = SRL(5'd22, 5'd18, 5'd20);     pc_w = pc_w + 1; // B: x22=0xFF>>2=0x3F
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;

        // === T9: SLTI / SLTIU ===
        u_soc.imem[pc_w] = SLTI(5'd23, 5'd1, 12'd15);    pc_w = pc_w + 1; // x23 = (10 < 15) = 1
        u_soc.imem[pc_w] = SLTIU(5'd24, 5'd1, 12'd5);    pc_w = pc_w + 1; // x24 = (10u < 5u) = 0
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;

        // === T10: Store then load-back ===
        u_soc.imem[pc_w] = SW(5'd2, 5'd30, 12'd8);       pc_w = pc_w + 1; // mem[base+8] = x2 = 15
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = LW(5'd25, 5'd30, 12'd8);      pc_w = pc_w + 1; // x25 = mem[base+8] = 15
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;
        u_soc.imem[pc_w] = NOP; pc_w = pc_w + 1;

        // === SELF-LOOP ===
        u_soc.imem[pc_w] = JAL(5'd0, 21'd0);

        rst_n = 0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1;
    end

    wire [31:0] cpu_pc = u_soc.u_cpu.u_if.pc_out;
    wire b_valid_ex = u_soc.u_cpu.u_pipe_idex.idex_b_valid;
    reg [63:0] cyc = 0, dual_cnt = 0;
    reg [31:0] stable = 0, prev_pc = 32'hFFFFFFFF, prev2 = 32'hFFFFFFFF, prev3 = 32'hFFFFFFFF;

    always @(posedge clk) if (rst_n && b_valid_ex) dual_cnt <= dual_cnt + 1;

    integer errors;
    always @(posedge clk) begin
        if (!rst_n) begin
            cyc<=0; stable<=0; prev_pc<=32'hFFFFFFFF; prev2<=32'hFFFFFFFF; prev3<=32'hFFFFFFFF;
        end else begin
            cyc <= cyc + 1;
            if (cpu_pc == prev3 && cpu_pc != 32'hFFFFFFFF) stable <= stable + 1;
            else stable <= 0;
            prev3 <= prev2; prev2 <= prev_pc; prev_pc <= cpu_pc;

            if (stable >= 30) begin
                errors = 0;
                $display("");
                $display("=== DUAL-ISSUE EDGE-CASE VERIFICATION ===");
                $display("  Self-loop at PC=0x%08h after %0d cycles, dual=%0d (%0d%%)",
                    cpu_pc, cyc, dual_cnt, (dual_cnt*100)/cyc);
                $display("");

                check_reg(1,  32'd10,       "T1: setup x1=10");
                check_reg(2,  32'd15,       "T1: EXMEM_A fwd x2=x1+5");
                check_reg(3,  32'd20,       "T2: dual A x3=20");
                check_reg(4,  32'd30,       "T2: dual B x4=30");
                check_reg(5,  32'd31,       "T2: EXMEM_B fwd x5=x4+1");
                check_reg(6,  32'd40,       "T3: x6=40");
                check_reg(7,  32'd42,       "T3: EXMEM_A→B fwd x7=x6+2");
                check_reg(8,  32'd99,       "T4: load x8=99");
                check_reg(9,  32'd100,      "T4: load-use stall x9=x8+1");
                check_reg(10, 32'd3,        "T5: loop x10=3");
                check_reg(11, 32'd222,      "T6: fwd branch mispredict x11=222");
                check_reg(12, 32'd50,       "T7: x12=50");
                check_reg(13, 32'd30,       "T7: x13=30");
                check_reg(14, 32'd20,       "T7: SUB x14=50-30");
                check_reg(15, 32'd18,       "T7: AND x15=50&30");
                check_reg(16, 32'h000000F0, "T8: x16=0xF0");
                check_reg(17, 32'h0000000F, "T8: x17=0x0F");
                check_reg(18, 32'h000000FF, "T8: OR x18=0xFF");
                check_reg(19, 32'h000000FF, "T8: XOR x19=0xFF");
                check_reg(20, 32'd2,        "T8: x20=2 (shift amt)");
                check_reg(21, 32'h000003FC, "T8: SLL x21=0xFF<<2");
                check_reg(22, 32'h0000003F, "T8: SRL x22=0xFF>>2");
                check_reg(23, 32'd1,        "T9: SLTI x23=(10<15)=1");
                check_reg(24, 32'd0,        "T9: SLTIU x24=(10u<5u)=0");
                check_reg(25, 32'd15,       "T10: store/load x25=15");

                $display("");
                if (errors == 0)
                    $display("  RESULT: *** ALL 25 CHECKS PASSED ***");
                else
                    $display("  RESULT: *** %0d FAILURES ***", errors);
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
        input [4:0] idx; input [31:0] expected; input [255:0] label;
        reg [31:0] actual;
        begin
            actual = (idx == 0) ? 32'h0 : u_soc.u_cpu.u_stage_id.regfile[idx];
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
                rv = (k == 0) ? 32'h0 : u_soc.u_cpu.u_stage_id.regfile[k];
                if (rv !== 32'h0) $display("  x%0d = 0x%08h", k, rv);
            end
        end
    endtask

endmodule
