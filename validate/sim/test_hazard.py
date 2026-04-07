#!/usr/bin/env python3
"""
test_hazard.py – Directed pipeline hazard tests for the RISC-V 5-stage CPU.

Run from validate/sim/
    python test_hazard.py

Generates inst.data inline (no assembler needed), compiles once, then runs
each test through the existing ISA testbench (tb/tinyriscv_soc_tb.v).

Pass/fail convention (same as existing ISA tests):
    x26 (s10) = 1  → test complete
    x27 (s11) = 1  → PASS
    x27 (s11) = 0  → FAIL
"""

import os
import subprocess
import sys

# ─────────────────────────────────────────────────────────────────────────────
# Instruction encoding helpers (little-endian 32-bit RISC-V)
# ─────────────────────────────────────────────────────────────────────────────

def addi(rd, rs1, imm):
    """ADDI rd, rs1, imm  (I-type, opcode 0x13)"""
    imm12 = imm & 0xFFF
    return (imm12 << 20) | (rs1 << 15) | (0b000 << 12) | (rd << 7) | 0x13

def add(rd, rs1, rs2):
    """ADD rd, rs1, rs2  (R-type, opcode 0x33, funct7=0, funct3=0)"""
    return (0 << 25) | (rs2 << 20) | (rs1 << 15) | (0b000 << 12) | (rd << 7) | 0x33

def lw(rd, rs1, imm):
    """LW rd, imm(rs1)  (I-type, opcode 0x03, funct3=010)"""
    imm12 = imm & 0xFFF
    return (imm12 << 20) | (rs1 << 15) | (0b010 << 12) | (rd << 7) | 0x03

def sw(rs2, rs1, imm):
    """SW rs2, imm(rs1)  (S-type, opcode 0x23, funct3=010)"""
    imm12  = imm & 0xFFF
    imm_hi = (imm12 >> 5) & 0x7F
    imm_lo = imm12 & 0x1F
    return (imm_hi << 25) | (rs2 << 20) | (rs1 << 15) | (0b010 << 12) | (imm_lo << 7) | 0x23

def beq(rs1, rs2, offset):
    """BEQ rs1, rs2, offset  (B-type, opcode 0x63, funct3=000)"""
    imm13   = offset & 0x1FFF
    imm12   = (imm13 >> 12) & 1
    imm11   = (imm13 >> 11) & 1
    imm10_5 = (imm13 >> 5)  & 0x3F
    imm4_1  = (imm13 >> 1)  & 0xF
    return (imm12 << 31) | (imm10_5 << 25) | (rs2 << 20) | (rs1 << 15) \
         | (0b000 << 12) | (imm4_1 << 8) | (imm11 << 7) | 0x63

def bne(rs1, rs2, offset):
    """BNE rs1, rs2, offset  (B-type, opcode 0x63, funct3=001)"""
    imm13   = offset & 0x1FFF
    imm12   = (imm13 >> 12) & 1
    imm11   = (imm13 >> 11) & 1
    imm10_5 = (imm13 >> 5)  & 0x3F
    imm4_1  = (imm13 >> 1)  & 0xF
    return (imm12 << 31) | (imm10_5 << 25) | (rs2 << 20) | (rs1 << 15) \
         | (0b001 << 12) | (imm4_1 << 8) | (imm11 << 7) | 0x63

def jal(rd, offset):
    """JAL rd, offset  (J-type, opcode 0x6F)"""
    imm21    = offset & 0x1FFFFF
    imm20    = (imm21 >> 20) & 1
    imm10_1  = (imm21 >> 1)  & 0x3FF
    imm11    = (imm21 >> 11) & 1
    imm19_12 = (imm21 >> 12) & 0xFF
    return (imm20 << 31) | (imm10_1 << 21) | (imm11 << 20) \
         | (imm19_12 << 12) | (rd << 7) | 0x6F

def jalr(rd, rs1, imm):
    """JALR rd, rs1, imm  (I-type, opcode 0x67, funct3=000)"""
    imm12 = imm & 0xFFF
    return (imm12 << 20) | (rs1 << 15) | (0b000 << 12) | (rd << 7) | 0x67

def nop():
    """NOP = ADDI x0, x0, 0"""
    return 0x00000013

def fence_i():
    """FENCE.I  (opcode 0x0F, funct3=001)"""
    return 0x0000100F

X26, X27 = 26, 27   # completion / pass registers

# ─────────────────────────────────────────────────────────────────────────────
# Test programs
# ─────────────────────────────────────────────────────────────────────────────

def test1_load_use_branch():
    """
    Test 1 – Load-use hazard into BEQ.

    LW  x1, 0(x2)     ← LOAD into x1
    BEQ x1, x3, pass  ← consumer of x1 (1-cycle stall + MEM/WB forwarding)

    Expected: x1 == x3 == 42, branch taken → PASS
    """
    p = []
    # 0x00-0x0C: setup
    p.append(addi(2, 0, 16))   # x2 = 16 (DMEM byte addr, word 4)
    p.append(addi(5, 0, 42))   # x5 = 42 (value to store)
    p.append(addi(3, 0, 42))   # x3 = 42 (branch compare target)
    p.append(sw(5, 2, 0))      # DMEM[16] = 42
    # 0x10: LOAD – hazard with BEQ below
    p.append(lw(1, 2, 0))      # x1 = DMEM[16]  ← LOAD
    # 0x14: BEQ x1, x3 → takes 1-cycle stall, then MEM/WB forward
    # offset to pass (0x20) = 0x20 - 0x14 = 12
    p.append(beq(1, 3, 12))    # if x1==42 branch to pass
    # 0x18: FAIL path
    p.append(addi(X27, 0, 0))  # x27 = 0 (FAIL)
    # 0x1C: jump to end
    p.append(jal(0, 8))        # → 0x24
    # 0x20: pass:
    p.append(addi(X27, 0, 1))  # x27 = 1 (PASS)
    # 0x24: end:
    p.append(addi(X26, 0, 1))  # x26 = 1 (done)
    p.append(jal(0, 0))        # infinite loop
    return p


def test2_load_use_jalr():
    """
    Test 2 – Load-use hazard into JALR.

    LW   x1, 0(x2)   ← LOAD into x1
    JALR x0, x1, 0   ← consumer (1-cycle stall + MEM/WB forwarding for rs1)

    Loaded value = 0x30 (word 12 = PASS label).
    Expected: JALR jumps to 0x30 → PASS
    """
    p = []
    # 0x00
    p.append(addi(2, 0, 16))   # x2 = 16 (DMEM byte addr)
    # 0x04: x5 = 0x30 = 48 (byte addr of word 12 = PASS label)
    p.append(addi(5, 0, 48))   # x5 = 48
    # 0x08
    p.append(sw(5, 2, 0))      # DMEM[16] = 48
    # 0x0C: LOAD – hazard with JALR
    p.append(lw(1, 2, 0))      # x1 = DMEM[16] = 48  ← LOAD
    # 0x10: JALR to x1+0 = 48 = 0x30
    p.append(jalr(0, 1, 0))    # should jump to word 12 (PASS)
    # 0x14: FAIL (should not execute if JALR correct)
    p.append(addi(X27, 0, 0))  # x27 = 0 (FAIL)
    p.append(jal(0, 0))        # trap
    # 0x1C–0x2C: padding to reach word 12 = 0x30
    for _ in range(5):
        p.append(nop())
    # 0x30: PASS (JALR target)   [word 12]
    p.append(addi(X27, 0, 1))  # x27 = 1 (PASS)
    # 0x34
    p.append(addi(X26, 0, 1))  # x26 = 1 (done)
    p.append(jal(0, 0))
    return p


def test3_fwd_branch_operands():
    """
    Test 3 – EX/MEM forwarding into branch operands.

    ADD x1, x2, x3    ← result=8 in EX/MEM when BNE reaches EX
    BNE x1, x4, fail  ← forward_a should see 8, not stale 0

    BNE must NOT branch (8 == 8). If forwarding fails, x1 would be 0 ≠ 8
    and BNE would branch to FAIL.
    """
    p = []
    # 0x00-0x08: setup x2=5, x3=3, x4=8 (expected result)
    p.append(addi(2, 0, 5))    # x2 = 5
    p.append(addi(3, 0, 3))    # x3 = 3
    p.append(addi(4, 0, 8))    # x4 = 8
    # 0x0C: ADD – creates EX/MEM forward dependency for BNE
    p.append(add(1, 2, 3))     # x1 = 5+3 = 8
    # 0x10: BNE x1, x4 – should NOT branch (8 == 8 → fall-through)
    # offset to fail (0x20) = 0x20 - 0x10 = 16
    p.append(bne(1, 4, 16))    # if x1 != 8 → FAIL
    # 0x14: PASS
    p.append(addi(X27, 0, 1))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))        # loop
    # 0x20: FAIL
    p.append(addi(X27, 0, 0))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    return p


def test4_store_data_forwarding():
    """
    Test 4 – Store rs2 data forwarding.

    ADD x1, x2, x3    ← result=8 in EX/MEM when SW reaches EX
    SW  x1, 0(x4)     ← rs2_data_fwd should be 8, not stale value

    A subsequent LW+BNE confirms that the correct value was stored.
    """
    p = []
    # 0x00-0x08: setup
    p.append(addi(2, 0, 5))    # x2 = 5
    p.append(addi(3, 0, 3))    # x3 = 3
    p.append(addi(4, 0, 64))   # x4 = 64 (DMEM byte addr, word 16)
    # 0x0C: ADD x1 = 5+3 = 8
    p.append(add(1, 2, 3))     # x1 = 8
    # 0x10: SW – rs2=x1 should be forwarded from EX/MEM
    p.append(sw(1, 4, 0))      # DMEM[64] = 8  (uses forwarded x1)
    # 0x14: LW to verify store
    p.append(lw(5, 4, 0))      # x5 = DMEM[64]
    p.append(addi(6, 0, 8))    # x6 = 8 (expected)
    # 0x1C: BNE – offset to fail (0x2C) = 0x2C - 0x1C = 16
    p.append(bne(5, 6, 16))    # if x5 != 8 → FAIL
    # 0x20: PASS
    p.append(addi(X27, 0, 1))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    # 0x2C: FAIL
    p.append(addi(X27, 0, 0))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    return p


def test5_three_deep_forwarding():
    """
    Test 5 – 3-deep ALU forwarding chain.

    ADD x1, x2, x3   → x1 = 8    (stage N EX)
    ADD x1, x1, x4   → x1 = 10   (EX/MEM fwd from above)
    ADD x5, x1, x6   → x5 = 17   (EX/MEM fwd from above)

    Verifies EX/MEM → EX priority over MEM/WB → EX.
    """
    p = []
    # 0x00-0x0C: init
    p.append(addi(2, 0, 3))    # x2 = 3
    p.append(addi(3, 0, 5))    # x3 = 5
    p.append(addi(4, 0, 2))    # x4 = 2
    p.append(addi(6, 0, 7))    # x6 = 7
    # 0x10: chain starts
    p.append(add(1, 2, 3))     # x1 = 3+5 = 8
    # 0x14: EX/MEM fwd (prev result in EX/MEM, this in EX)
    p.append(add(1, 1, 4))     # x1 = 8+2 = 10
    # 0x18: again EX/MEM fwd
    p.append(add(5, 1, 6))     # x5 = 10+7 = 17
    p.append(addi(7, 0, 17))   # x7 = 17
    # 0x20: BNE – offset to fail (0x30) = 0x30 - 0x20 = 16
    p.append(bne(5, 7, 16))    # if x5 != 17 → FAIL
    # 0x24: PASS
    p.append(addi(X27, 0, 1))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    # 0x30: FAIL
    p.append(addi(X27, 0, 0))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    return p


def test6_store_load_same_addr():
    """
    Test 6 – Store then load from same address.

    SW x1, 0(x2)   → writes 0xAB to DMEM[64]
    LW x3, 0(x2)   → reads back 0xAB from DMEM[64]

    SW is in MEM (writes at clock edge) before LW reaches MEM (reads combinationally).
    """
    p = []
    p.append(addi(2, 0, 64))   # x2 = 64 (DMEM byte addr, word 16)
    p.append(addi(1, 0, 0xAB)) # x1 = 0xAB = 171
    # 0x08: SW → DMEM[64] = 0xAB
    p.append(sw(1, 2, 0))
    # 0x0C: LW → x3 = DMEM[64]   (no stall: hazard unit only stalls for LOAD in EX)
    p.append(lw(3, 2, 0))
    p.append(addi(4, 0, 0xAB)) # x4 = 0xAB (expected)
    # 0x14: BNE – offset to fail (0x24) = 0x24 - 0x14 = 16
    p.append(bne(3, 4, 16))    # if x3 != 0xAB → FAIL
    # 0x18: PASS
    p.append(addi(X27, 0, 1))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    # 0x24: FAIL
    p.append(addi(X27, 0, 0))
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    return p


def test7_fence_i():
    """
    Test 7 – FENCE.I boundary cases.

    7a: one store before FENCE.I, then LW after
    7b: three stores before FENCE.I, then LW after
    7c: FENCE.I with no code modification

    FENCE.I is implemented as JAL to PC+4 (control_unit sets jal=1, imm_gen imm=4).
    Pipeline is flushed but stores already in MEM complete normally.

    Memory layout:
        DMEM[64] used for sub-test 7a
        DMEM[68] used for sub-test 7b
    """
    p = []
    # ── 7a: one store immediately before FENCE.I ──────────────────────────
    # Use byte address 0x100 (256) for data.  This maps to IMEM word 64,
    # which is well beyond the test's instruction range (last insn at 0x60)
    # and therefore never fetched, avoiding the IMEM alias write problem
    # (riscv_soc.v forwards stores < 0x8000 to instruction memory).
    # 0x00
    p.append(addi(2, 0, 256))  # x2 = 0x100 (DMEM byte addr, safe above instrs)
    p.append(addi(1, 0, 99))   # x1 = 99
    # 0x08: store to DMEM[0x100]
    p.append(sw(1, 2, 0))      # DMEM[0x100] = 99
    # 0x0C: FENCE.I – pipeline flush, PC → 0x10
    p.append(fence_i())
    # 0x10: LW x3 from DMEM[0x100] – should see 99
    p.append(lw(3, 2, 0))      # x3 = DMEM[0x100]
    p.append(addi(4, 0, 99))   # x4 = 99
    # 0x18: BNE → fail1 (0x58).  offset = 0x58 - 0x18 = 64
    p.append(bne(3, 4, 64))    # if x3 != 99 → fail1

    # ── 7b: three stores before FENCE.I ────────────────────────────────────
    # Use byte address 0x104 (260) to avoid clobbering 7a's data location.
    # 0x1C
    p.append(addi(2, 0, 260))  # x2 = 0x104
    p.append(addi(1, 0, 11))   # x1 = 11
    p.append(sw(1, 2, 0))      # DMEM[0x104] = 11
    p.append(addi(1, 0, 22))   # x1 = 22
    p.append(sw(1, 2, 0))      # DMEM[0x104] = 22
    p.append(addi(1, 0, 33))   # x1 = 33
    p.append(sw(1, 2, 0))      # DMEM[0x104] = 33 (last write)
    # 0x38: FENCE.I
    p.append(fence_i())
    # 0x3C: LW from DMEM[0x104] – should see 33
    p.append(lw(3, 2, 0))      # x3 = DMEM[0x104]
    p.append(addi(4, 0, 33))   # x4 = 33
    # 0x44: BNE → fail1 (0x58).  offset = 0x58 - 0x44 = 20
    p.append(bne(3, 4, 20))    # if x3 != 33 → fail1

    # ── 7c: FENCE.I with no prior modification ─────────────────────────────
    # 0x48
    p.append(fence_i())        # should just continue to next instruction
    # 0x4C: PASS
    p.append(addi(X27, 0, 1))  # x27 = 1 (PASS)
    # 0x50
    p.append(addi(X26, 0, 1))  # x26 = 1
    p.append(jal(0, 0))        # loop

    # 0x58: fail1:
    p.append(addi(X27, 0, 0))  # x27 = 0 (FAIL)
    p.append(addi(X26, 0, 1))
    p.append(jal(0, 0))
    return p


# ─────────────────────────────────────────────────────────────────────────────
# Test registry
# ─────────────────────────────────────────────────────────────────────────────

TESTS = [
    ("T1 load-use → BEQ          ", test1_load_use_branch),
    ("T2 load-use → JALR         ", test2_load_use_jalr),
    ("T3 EX/MEM fwd → BNE        ", test3_fwd_branch_operands),
    ("T4 store-data forwarding    ", test4_store_data_forwarding),
    ("T5 3-deep fwd chain         ", test5_three_deep_forwarding),
    ("T6 store then load same addr", test6_store_load_same_addr),
    ("T7 FENCE.I boundary         ", test7_fence_i),
]

# ─────────────────────────────────────────────────────────────────────────────
# Simulation helpers
# ─────────────────────────────────────────────────────────────────────────────

def write_inst_data(words, path="inst.data"):
    """Write program words as hex to inst.data."""
    with open(path, "w") as f:
        for w in words:
            f.write("{:08x}\n".format(w & 0xFFFFFFFF))


def compile_once():
    """Compile RTL using the existing compile_rtl.py helper (project root = ../..)."""
    cmd = [sys.executable, "compile_rtl.py", "../.."]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
    if result.returncode != 0:
        print("!!! RTL compilation failed !!!")
        print(result.stdout)
        print(result.stderr)
        sys.exit(1)
    print("RTL compiled successfully.\n")


def run_test(prog_words):
    """Write inst.data and run the VVP simulation; return (pass, output)."""
    write_inst_data(prog_words)
    vvp = subprocess.run(["vvp", "out.vvp"],
                         capture_output=True, text=True, timeout=60)
    output = vvp.stdout + vvp.stderr
    passed = "TEST_PASS" in output
    return passed, output


# ─────────────────────────────────────────────────────────────────────────────
# Main
# ─────────────────────────────────────────────────────────────────────────────

def main():
    compile_once()

    passed = 0
    failed = 0
    results = []

    for name, build_fn in TESTS:
        prog = build_fn()
        ok, output = run_test(prog)
        status = "PASS" if ok else "FAIL"
        print("{}: {}".format(name, status))
        if not ok:
            # Print last few output lines for debug
            for line in output.strip().splitlines():
                print("    | " + line)
            failed += 1
        else:
            passed += 1
        results.append((name, ok))

    print()
    print("─" * 50)
    print("Directed hazard tests: {:d} PASS  {:d} FAIL  (total {:d})".format(
        passed, failed, passed + failed))
    return 0 if failed == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
