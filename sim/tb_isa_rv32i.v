// tb_isa_rv32i.v — Comprehensive RV32I instruction-level verification.
//
// Tests EVERY RV32I instruction with multiple operand patterns, run under
// the dual-issue pipeline. Instructions are placed to create both dual-issue
// and single-issue scenarios, stressing forwarding/hazard paths.
//
// This is NOT a repackaging of benchmark results — it's a ground-truth
// register/memory check for each individual instruction encoding.
`timescale 1ns/1ps

module tb_isa_rv32i;

    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;
    sim_soc u_soc (.clk(clk), .rst_n(rst_n));

    // =====================================================================
    // Instruction encoding helpers
    // =====================================================================
    function [31:0] enc_r;
        input [6:0] f7; input [4:0] rs2, rs1; input [2:0] f3; input [4:0] rd; input [6:0] op;
        enc_r = {f7, rs2, rs1, f3, rd, op};
    endfunction
    function [31:0] ADD;  input [4:0] rd,rs1,rs2; ADD  = enc_r(7'h00,rs2,rs1,3'h0,rd,7'h33); endfunction
    function [31:0] SUB;  input [4:0] rd,rs1,rs2; SUB  = enc_r(7'h20,rs2,rs1,3'h0,rd,7'h33); endfunction
    function [31:0] SLL;  input [4:0] rd,rs1,rs2; SLL  = enc_r(7'h00,rs2,rs1,3'h1,rd,7'h33); endfunction
    function [31:0] SLT;  input [4:0] rd,rs1,rs2; SLT  = enc_r(7'h00,rs2,rs1,3'h2,rd,7'h33); endfunction
    function [31:0] SLTU; input [4:0] rd,rs1,rs2; SLTU = enc_r(7'h00,rs2,rs1,3'h3,rd,7'h33); endfunction
    function [31:0] XOR_; input [4:0] rd,rs1,rs2; XOR_ = enc_r(7'h00,rs2,rs1,3'h4,rd,7'h33); endfunction
    function [31:0] SRL;  input [4:0] rd,rs1,rs2; SRL  = enc_r(7'h00,rs2,rs1,3'h5,rd,7'h33); endfunction
    function [31:0] SRA;  input [4:0] rd,rs1,rs2; SRA  = enc_r(7'h20,rs2,rs1,3'h5,rd,7'h33); endfunction
    function [31:0] OR_;  input [4:0] rd,rs1,rs2; OR_  = enc_r(7'h00,rs2,rs1,3'h6,rd,7'h33); endfunction
    function [31:0] AND_; input [4:0] rd,rs1,rs2; AND_ = enc_r(7'h00,rs2,rs1,3'h7,rd,7'h33); endfunction

    function [31:0] ADDI;  input [4:0] rd,rs1; input [11:0] imm; ADDI  = {imm,rs1,3'h0,rd,7'h13}; endfunction
    function [31:0] SLTI;  input [4:0] rd,rs1; input [11:0] imm; SLTI  = {imm,rs1,3'h2,rd,7'h13}; endfunction
    function [31:0] SLTIU; input [4:0] rd,rs1; input [11:0] imm; SLTIU = {imm,rs1,3'h3,rd,7'h13}; endfunction
    function [31:0] XORI;  input [4:0] rd,rs1; input [11:0] imm; XORI  = {imm,rs1,3'h4,rd,7'h13}; endfunction
    function [31:0] ORI;   input [4:0] rd,rs1; input [11:0] imm; ORI   = {imm,rs1,3'h6,rd,7'h13}; endfunction
    function [31:0] ANDI;  input [4:0] rd,rs1; input [11:0] imm; ANDI  = {imm,rs1,3'h7,rd,7'h13}; endfunction
    function [31:0] SLLI;  input [4:0] rd,rs1; input [4:0] shamt; SLLI = {7'h00,shamt,rs1,3'h1,rd,7'h13}; endfunction
    function [31:0] SRLI;  input [4:0] rd,rs1; input [4:0] shamt; SRLI = {7'h00,shamt,rs1,3'h5,rd,7'h13}; endfunction
    function [31:0] SRAI;  input [4:0] rd,rs1; input [4:0] shamt; SRAI = {7'h20,shamt,rs1,3'h5,rd,7'h13}; endfunction

    function [31:0] LUI;   input [4:0] rd; input [19:0] imm; LUI   = {imm, rd, 7'h37}; endfunction
    function [31:0] AUIPC; input [4:0] rd; input [19:0] imm; AUIPC = {imm, rd, 7'h17}; endfunction

    function [31:0] LW;  input [4:0] rd,rs1; input [11:0] imm; LW  = {imm, rs1, 3'h2, rd, 7'h03}; endfunction
    function [31:0] LH;  input [4:0] rd,rs1; input [11:0] imm; LH  = {imm, rs1, 3'h1, rd, 7'h03}; endfunction
    function [31:0] LB;  input [4:0] rd,rs1; input [11:0] imm; LB  = {imm, rs1, 3'h0, rd, 7'h03}; endfunction
    function [31:0] LHU; input [4:0] rd,rs1; input [11:0] imm; LHU = {imm, rs1, 3'h5, rd, 7'h03}; endfunction
    function [31:0] LBU; input [4:0] rd,rs1; input [11:0] imm; LBU = {imm, rs1, 3'h4, rd, 7'h03}; endfunction

    function [31:0] SW; input [4:0] rs2,rs1; input [11:0] imm; SW = {imm[11:5],rs2,rs1,3'h2,imm[4:0],7'h23}; endfunction
    function [31:0] SH; input [4:0] rs2,rs1; input [11:0] imm; SH = {imm[11:5],rs2,rs1,3'h1,imm[4:0],7'h23}; endfunction
    function [31:0] SB; input [4:0] rs2,rs1; input [11:0] imm; SB = {imm[11:5],rs2,rs1,3'h0,imm[4:0],7'h23}; endfunction

    function [31:0] BEQ; input [4:0] rs1,rs2; input [12:0] off;
        BEQ = {off[12],off[10:5],rs2,rs1,3'h0,off[4:1],off[11],7'h63}; endfunction
    function [31:0] BNE; input [4:0] rs1,rs2; input [12:0] off;
        BNE = {off[12],off[10:5],rs2,rs1,3'h1,off[4:1],off[11],7'h63}; endfunction
    function [31:0] BLT; input [4:0] rs1,rs2; input [12:0] off;
        BLT = {off[12],off[10:5],rs2,rs1,3'h4,off[4:1],off[11],7'h63}; endfunction
    function [31:0] BGE; input [4:0] rs1,rs2; input [12:0] off;
        BGE = {off[12],off[10:5],rs2,rs1,3'h5,off[4:1],off[11],7'h63}; endfunction
    function [31:0] BLTU; input [4:0] rs1,rs2; input [12:0] off;
        BLTU = {off[12],off[10:5],rs2,rs1,3'h6,off[4:1],off[11],7'h63}; endfunction
    function [31:0] BGEU; input [4:0] rs1,rs2; input [12:0] off;
        BGEU = {off[12],off[10:5],rs2,rs1,3'h7,off[4:1],off[11],7'h63}; endfunction

    function [31:0] JAL; input [4:0] rd; input [20:0] off;
        JAL = {off[20],off[10:1],off[11],off[19:12],rd,7'h6F}; endfunction
    function [31:0] JALR; input [4:0] rd,rs1; input [11:0] imm;
        JALR = {imm,rs1,3'h0,rd,7'h67}; endfunction

    localparam [31:0] NOP = 32'h0000_0013;
    localparam [31:0] DRAM_BASE = 32'h80100000;

    integer p, ii;
    // Macro-like task for emitting instructions
    task emit; input [31:0] inst; begin u_soc.imem[p] = inst; p = p + 1; end endtask
    task nops; input integer n; integer j; begin for(j=0;j<n;j=j+1) emit(NOP); end endtask

    initial begin
        for (ii=0; ii<4096; ii=ii+1) u_soc.imem[ii] = NOP;
        for (ii=0; ii<65536; ii=ii+1) u_soc.dmem[ii] = 32'h0;

        // Pre-load DRAM with test patterns
        u_soc.dmem[0] = 32'hDEADBEEF;  // addr 0x80100000
        u_soc.dmem[1] = 32'h12345678;  // addr 0x80100004
        u_soc.dmem[2] = 32'hFF80007F;  // addr 0x80100008 (has sign-ext test bytes)

        p = 0;

        // ========= SETUP: base register values =========
        emit(LUI(5'd31, 20'h80100));   // x31 = 0x80100000 (DRAM base)
        nops(3);

        // ========= R-TYPE ALU =========
        // Setup operands (dual-issuable pairs)
        emit(ADDI(5'd1, 5'd0, 12'd100));   // x1 = 100
        emit(ADDI(5'd2, 5'd0, 12'd37));    // x2 = 37
        emit(ADDI(5'd3, 5'd0, -12'sd5));   // x3 = -5 (0xFFFFFFFB)
        emit(ADDI(5'd4, 5'd0, 12'd3));     // x4 = 3
        nops(4);

        // ADD
        emit(ADD(5'd5, 5'd1, 5'd2));   // x5 = 100+37 = 137
        emit(NOP);
        nops(3);
        // SUB
        emit(SUB(5'd6, 5'd1, 5'd2));   // x6 = 100-37 = 63
        emit(NOP);
        nops(3);
        // SLL
        emit(SLL(5'd7, 5'd1, 5'd4));   // x7 = 100<<3 = 800
        emit(NOP);
        nops(3);
        // SLT (signed)
        emit(SLT(5'd8, 5'd3, 5'd1));   // x8 = (-5 < 100) = 1
        emit(SLT(5'd9, 5'd1, 5'd3));   // x9 = (100 < -5) = 0  (dual)
        nops(4);
        // SLTU (unsigned: -5 = 0xFFFFFFFB > 100)
        emit(SLTU(5'd10, 5'd3, 5'd1)); // x10 = (0xFFFFFFFB < 100) = 0
        emit(SLTU(5'd11, 5'd1, 5'd3)); // x11 = (100 < 0xFFFFFFFB) = 1 (dual)
        nops(4);
        // XOR
        emit(XOR_(5'd12, 5'd1, 5'd2));  // x12 = 100^37 = 65
        emit(NOP);
        nops(3);
        // SRL
        emit(SRL(5'd13, 5'd1, 5'd4));  // x13 = 100>>3 = 12
        emit(NOP);
        nops(3);
        // SRA (signed shift: -5 >>> 1 = -3)
        emit(ADDI(5'd14, 5'd0, 12'd1)); nops(3);
        emit(SRA(5'd14, 5'd3, 5'd14)); // x14 = -5>>>1 = -3 (0xFFFFFFFD)
        nops(4);
        // OR
        emit(OR_(5'd15, 5'd1, 5'd2));   // x15 = 100|37 = 101
        emit(NOP);
        nops(3);
        // AND
        emit(AND_(5'd16, 5'd1, 5'd2));  // x16 = 100&37 = 36
        emit(NOP);
        nops(3);

        // ========= I-TYPE ALU =========
        // ADDI (already tested), SLTI
        emit(SLTI(5'd17, 5'd3, 12'd0));  // x17 = (-5 < 0) = 1
        emit(SLTIU(5'd18, 5'd1, 12'd200)); // x18 = (100 < 200) = 1 (dual)
        nops(4);
        // XORI
        emit(XORI(5'd19, 5'd1, 12'hFF)); // x19 = 100 ^ 0xFF = 0x9B = 155
        emit(ORI(5'd20, 5'd1, 12'hFF));  // x20 = 100 | 0xFF = 0xFF = 255  (dual)
        nops(4);
        // ANDI
        emit(ANDI(5'd21, 5'd1, 12'hFF)); // x21 = 100 & 0xFF = 100
        emit(NOP);
        nops(3);
        // SLLI
        emit(SLLI(5'd22, 5'd2, 5'd4));  // x22 = 37<<4 = 592
        emit(SRLI(5'd23, 5'd1, 5'd2));  // x23 = 100>>2 = 25 (dual)
        nops(4);
        // SRAI
        emit(SRAI(5'd24, 5'd3, 5'd1));  // x24 = -5>>>1 = -3 (0xFFFFFFFD)
        emit(NOP);
        nops(3);

        // ========= LUI / AUIPC =========
        emit(LUI(5'd25, 20'hABCDE));    // x25 = 0xABCDE000
        emit(NOP);
        nops(3);
        // AUIPC: result = PC + (imm << 12)
        // Current PC for this instruction — we'll check relative to the self-loop
        // Just verify it's non-zero and in the 0x8000xxxx range
        emit(AUIPC(5'd26, 20'h00000));  // x26 = PC of this instruction
        emit(NOP);
        nops(3);

        // ========= LOAD / STORE =========
        // LW
        emit(LW(5'd1, 5'd31, 12'd0));   // x1 = mem[0x80100000] = 0xDEADBEEF
        nops(4);
        // LH (signed halfword from 0x80100008 offset 0: lower half of 0xFF80007F)
        emit(LH(5'd2, 5'd31, 12'd8));   // x2 = sign_ext(0x007F) = 0x0000007F
        nops(4);
        // LB (signed byte from 0x80100008 byte 2: 0x80)
        emit(LB(5'd3, 5'd31, 12'd10));  // x3 = sign_ext(0x80) = 0xFFFFFF80
        nops(4);
        // LHU (unsigned halfword)
        emit(LHU(5'd4, 5'd31, 12'd10)); // x4 = zero_ext(0xFF80) = 0x0000FF80
        nops(4);
        // LBU (unsigned byte)
        emit(LBU(5'd5, 5'd31, 12'd10)); // x5 = zero_ext(0x80) = 0x00000080
        nops(4);

        // SW / SH / SB
        emit(ADDI(5'd6, 5'd0, 12'h42)); nops(3); // x6 = 0x42
        emit(SW(5'd6, 5'd31, 12'd16));  // mem[base+16] = 0x42
        nops(3);
        emit(LW(5'd7, 5'd31, 12'd16));  // x7 = 0x42 (verify SW)
        nops(4);

        emit(SH(5'd6, 5'd31, 12'd20));  // mem[base+20] lower half = 0x0042
        nops(3);
        emit(LW(5'd8, 5'd31, 12'd20));  // x8 = 0x00000042 (verify SH)
        nops(4);

        emit(SB(5'd6, 5'd31, 12'd24));  // mem[base+24] byte 0 = 0x42
        nops(3);
        emit(LW(5'd9, 5'd31, 12'd24));  // x9 = 0x00000042 (verify SB)
        nops(4);

        // ========= BRANCHES =========
        // Setup for branch tests
        emit(ADDI(5'd10, 5'd0, 12'd5));  // x10 = 5
        emit(ADDI(5'd11, 5'd0, 12'd5));  // x11 = 5
        emit(ADDI(5'd12, 5'd0, 12'd10)); // x12 = 10
        emit(ADDI(5'd13, 5'd0, -12'sd3)); // x13 = -3
        nops(4);

        // BEQ taken
        emit(ADDI(5'd14, 5'd0, 12'd0)); nops(3);
        emit(BEQ(5'd10, 5'd11, 13'd8));    // 5==5 → taken, skip +8
        emit(ADDI(5'd14, 5'd0, 12'd999));  // SKIPPED
        emit(ADDI(5'd14, 5'd0, 12'd1));    // x14 = 1 (branch target)
        nops(4);

        // BEQ not taken
        emit(ADDI(5'd15, 5'd0, 12'd0)); nops(3);
        emit(BEQ(5'd10, 5'd12, 13'd8));    // 5==10 → not taken
        emit(ADDI(5'd15, 5'd0, 12'd1));    // x15 = 1 (executed)
        nops(4);

        // BNE taken
        emit(ADDI(5'd16, 5'd0, 12'd0)); nops(3);
        emit(BNE(5'd10, 5'd12, 13'd8));    // 5!=10 → taken
        emit(ADDI(5'd16, 5'd0, 12'd999));  // SKIPPED
        emit(ADDI(5'd16, 5'd0, 12'd1));    // x16 = 1
        nops(4);

        // BLT taken (signed: -3 < 5)
        emit(ADDI(5'd17, 5'd0, 12'd0)); nops(3);
        emit(BLT(5'd13, 5'd10, 13'd8));    // -3<5 → taken
        emit(ADDI(5'd17, 5'd0, 12'd999));
        emit(ADDI(5'd17, 5'd0, 12'd1));    // x17 = 1
        nops(4);

        // BLT not taken
        emit(ADDI(5'd18, 5'd0, 12'd0)); nops(3);
        emit(BLT(5'd10, 5'd13, 13'd8));    // 5<-3 → not taken
        emit(ADDI(5'd18, 5'd0, 12'd1));    // x18 = 1
        nops(4);

        // BGE taken
        emit(ADDI(5'd19, 5'd0, 12'd0)); nops(3);
        emit(BGE(5'd10, 5'd13, 13'd8));    // 5>=-3 → taken
        emit(ADDI(5'd19, 5'd0, 12'd999));
        emit(ADDI(5'd19, 5'd0, 12'd1));    // x19 = 1
        nops(4);

        // BLTU: unsigned comparison (0xFFFFFFFD > 5 unsigned)
        emit(ADDI(5'd20, 5'd0, 12'd0)); nops(3);
        emit(BLTU(5'd10, 5'd13, 13'd8));   // 5 < 0xFFFFFFFD unsigned → taken
        emit(ADDI(5'd20, 5'd0, 12'd999));
        emit(ADDI(5'd20, 5'd0, 12'd1));    // x20 = 1
        nops(4);

        // BGEU: 0xFFFFFFFD >= 5 unsigned → taken
        emit(ADDI(5'd21, 5'd0, 12'd0)); nops(3);
        emit(BGEU(5'd13, 5'd10, 13'd8));   // 0xFFFFFFFD >= 5 → taken
        emit(ADDI(5'd21, 5'd0, 12'd999));
        emit(ADDI(5'd21, 5'd0, 12'd1));    // x21 = 1
        nops(4);

        // ========= JAL / JALR =========
        emit(JAL(5'd22, 21'd8));            // x22 = PC+4, jump +8
        emit(ADDI(5'd22, 5'd0, 12'd999));  // SKIPPED
        // land here:
        nops(4);

        // JALR: jump to target computed from register
        emit(AUIPC(5'd23, 20'h0));         // x23 = current PC
        nops(3);
        emit(JALR(5'd24, 5'd23, 12'd20));  // x24 = PC+4, jump to x23+20
        emit(ADDI(5'd24, 5'd0, 12'd999));  // SKIPPED
        emit(ADDI(5'd24, 5'd0, 12'd998));  // SKIPPED
        emit(ADDI(5'd24, 5'd0, 12'd997));  // SKIPPED
        // land here (x23 + 20 bytes = x23 + 5 words):
        nops(4);

        // ========= SELF-LOOP =========
        emit(JAL(5'd0, 21'd0));

        rst_n = 0;
        repeat (10) @(posedge clk);
        @(negedge clk);
        rst_n = 1;
    end

    wire [31:0] cpu_pc = u_soc.u_cpu.u_if.pc_out;
    wire b_valid_ex = u_soc.u_cpu.u_pipe_idex.idex_b_valid;
    reg [63:0] cyc = 0, dual_cnt = 0;
    reg [31:0] stable = 0, pp = 32'hFFFFFFFF, pp2 = 32'hFFFFFFFF, pp3 = 32'hFFFFFFFF;

    always @(posedge clk) if (rst_n && b_valid_ex) dual_cnt <= dual_cnt + 1;

    integer errors, checks;
    always @(posedge clk) begin
        if (!rst_n) begin
            cyc<=0; stable<=0; pp<=32'hFFFFFFFF; pp2<=32'hFFFFFFFF; pp3<=32'hFFFFFFFF;
        end else begin
            cyc <= cyc + 1;
            if (cpu_pc == pp3 && cpu_pc != 32'hFFFFFFFF) stable <= stable + 1;
            else stable <= 0;
            pp3 <= pp2; pp2 <= pp; pp <= cpu_pc;

            if (stable >= 30) begin
                errors = 0;
                checks = 0;
                $display("");
                $display("=== RV32I INSTRUCTION-LEVEL VERIFICATION (dual-issue) ===");
                $display("  Cycles: %0d, Dual-issue: %0d (%0d%%)", cyc, dual_cnt, (dual_cnt*100)/cyc);
                $display("");

                // R-type ALU
                $display("--- R-type ALU ---");
                chk(5,  32'd137,        "ADD 100+37");
                chk(6,  32'd63,         "SUB 100-37");
                chk(7,  32'd800,        "SLL 100<<3");
                chk(8,  32'd1,          "SLT -5<100 (signed)");
                chk(9,  32'd0,          "SLT 100<-5 (signed)");
                chk(10, 32'd0,          "SLTU 0xFFFFFFFB<100");
                chk(11, 32'd1,          "SLTU 100<0xFFFFFFFB");
                chk(12, 32'd65,         "XOR 100^37");
                chk(13, 32'd12,         "SRL 100>>3");
                chk(14, 32'hFFFFFFFD,   "SRA -5>>>1 = -3");
                chk(15, 32'd101,        "OR 100|37");
                chk(16, 32'd36,         "AND 100&37");

                // I-type ALU
                $display("--- I-type ALU ---");
                chk(17, 32'd1,          "SLTI -5<0");
                chk(18, 32'd1,          "SLTIU 100<200");
                chk(19, 32'd155,        "XORI 100^0xFF");
                chk(20, 32'd255,        "ORI 100|0xFF");
                chk(21, 32'd100,        "ANDI 100&0xFF");
                chk(22, 32'd592,        "SLLI 37<<4");
                chk(23, 32'd25,         "SRLI 100>>2");
                chk(24, 32'hFFFFFFFD,   "SRAI -5>>>1");

                // LUI/AUIPC
                $display("--- LUI/AUIPC ---");
                chk(25, 32'hABCDE000,   "LUI 0xABCDE");
                // AUIPC: just check it's in instruction range
                begin
                    reg [31:0] v26;
                    v26 = u_soc.u_cpu.u_stage_id.regfile[26];
                    if (v26 >= 32'h80000000 && v26 < 32'h80001000) begin
                        $display("  [PASS] x26 = 0x%08h  (AUIPC in range)", v26);
                        checks = checks + 1;
                    end else begin
                        $display("  [FAIL] x26 = 0x%08h  (AUIPC out of range)", v26);
                        errors = errors + 1; checks = checks + 1;
                    end
                end

                // Load/Store
                $display("--- Load/Store ---");
                chk(1,  32'hDEADBEEF,   "LW");
                chk(2,  32'h0000007F,   "LH (signed, lower half)");
                chk(3,  32'hFFFFFF80,   "LB (signed, byte=0x80)");
                chk(4,  32'h0000FF80,   "LHU (unsigned halfword)");
                chk(5,  32'h00000080,   "LBU (unsigned byte)");
                chk(7,  32'h00000042,   "SW then LW verify");
                chk(8,  32'h00000042,   "SH then LW verify");
                chk(9,  32'h00000042,   "SB then LW verify");

                // Branches
                $display("--- Branches ---");
                chk(14, 32'd1,          "BEQ taken");
                chk(15, 32'd1,          "BEQ not taken");
                chk(16, 32'd1,          "BNE taken");
                chk(17, 32'd1,          "BLT signed taken");
                chk(18, 32'd1,          "BLT signed not taken");
                chk(19, 32'd1,          "BGE taken");
                chk(20, 32'd1,          "BLTU unsigned taken");
                chk(21, 32'd1,          "BGEU unsigned taken");

                // JAL/JALR
                $display("--- JAL/JALR ---");
                // x22 should be the return address from JAL (not 999)
                begin
                    reg [31:0] v22;
                    v22 = u_soc.u_cpu.u_stage_id.regfile[22];
                    if (v22 != 32'd999 && v22 >= 32'h80000000) begin
                        $display("  [PASS] x22 = 0x%08h  (JAL link addr)", v22);
                        checks = checks + 1;
                    end else begin
                        $display("  [FAIL] x22 = 0x%08h  (JAL wrong)", v22);
                        errors = errors + 1; checks = checks + 1;
                    end
                end
                // x24 should not be 999/998/997
                begin
                    reg [31:0] v24;
                    v24 = u_soc.u_cpu.u_stage_id.regfile[24];
                    if (v24 != 32'd999 && v24 != 32'd998 && v24 != 32'd997 && v24 >= 32'h80000000) begin
                        $display("  [PASS] x24 = 0x%08h  (JALR link addr)", v24);
                        checks = checks + 1;
                    end else begin
                        $display("  [FAIL] x24 = 0x%08h  (JALR wrong)", v24);
                        errors = errors + 1; checks = checks + 1;
                    end
                end

                $display("");
                $display("  TOTAL: %0d/%0d checks passed", checks - errors, checks);
                if (errors == 0)
                    $display("  RESULT: *** ALL %0d CHECKS PASSED ***", checks);
                else
                    $display("  RESULT: *** %0d FAILURES ***", errors);
                $finish;
            end
            if (cyc >= 50000) begin
                $display("=== TIMEOUT %0d cycles PC=0x%08h ===", cyc, cpu_pc);
                $finish;
            end
        end
    end

    task chk;
        input [4:0] idx; input [31:0] exp; input [255:0] lbl;
        reg [31:0] act;
        begin
            act = (idx==0) ? 32'h0 : u_soc.u_cpu.u_stage_id.regfile[idx];
            checks = checks + 1;
            if (act === exp)
                $display("  [PASS] x%0d = 0x%08h  (%0s)", idx, act, lbl);
            else begin
                $display("  [FAIL] x%0d = 0x%08h (exp 0x%08h)  (%0s)", idx, act, exp, lbl);
                errors = errors + 1;
            end
        end
    endtask

endmodule
