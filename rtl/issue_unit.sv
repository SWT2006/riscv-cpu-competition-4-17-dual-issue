`timescale 1ns/1ps
// Issue unit: pure combinational dual-issue compatibility check.
//
// Determines if two consecutively-fetched instructions (slot A at PC,
// slot B at PC+4) can issue simultaneously in a 2-wide superscalar pipeline.
//
// Pipe A (slot A): Full ALU, branch, mul/div, CSR, ECALL/MRET, load/store.
// Pipe B (slot B): Simple ALU, load/store only.
//
// Dual-issue is blocked when:
//   1. Slot B was not fetched (b_fetched == 0)
//   2. Slot A is serializing (CSR, ECALL/MRET, FENCE)
//   3. Slot B requires Pipe-A-only resources (branch, jump, CSR, mul/div, FENCE)
//   4. Both slots are memory operations (single DRAM port)
//   5. RAW dependency: slot B reads a register that slot A writes
//
// WAW (both write same register) is NOT blocked because:
//   - The forwarding network prioritises slot B over A (later in program order)
//   - The register file write logic gives slot B priority over A
module issue_unit (
    input  wire [31:0] inst_a,       // instruction in slot A (always valid)
    input  wire [31:0] inst_b,       // instruction in slot B
    input  wire        b_fetched,    // slot B available from IF
    output wire        can_dual      // 1 = both slots can issue together
);

    // -----------------------------------------------------------------
    // Instruction field extraction
    // -----------------------------------------------------------------
    wire [6:0] a_op  = inst_a[6:0];
    wire [2:0] a_f3  = inst_a[14:12];
    wire [4:0] a_rd  = inst_a[11:7];
    wire [6:0] a_f7  = inst_a[31:25];

    wire [6:0] b_op  = inst_b[6:0];
    wire [6:0] b_f7  = inst_b[31:25];
    wire [4:0] b_rs1 = inst_b[19:15];
    wire [4:0] b_rs2 = inst_b[24:20];

    // -----------------------------------------------------------------
    // Slot A serialising check
    // -----------------------------------------------------------------
    wire a_is_system    = (a_op == 7'b1110011);
    wire a_is_ecall_etc = a_is_system & (a_f3 == 3'b000);   // ECALL / EBREAK / MRET
    wire a_is_csr       = a_is_system & (a_f3 != 3'b000);
    wire a_is_fence     = (a_op == 7'b0001111);
    wire a_serialising  = a_is_ecall_etc | a_is_csr | a_is_fence;

    // -----------------------------------------------------------------
    // Slot B Pipe-B compatibility
    // Pipe B cannot handle: branch, JAL, JALR, SYSTEM, FENCE, M-extension
    // -----------------------------------------------------------------
    wire b_is_branch  = (b_op == 7'b1100011);
    wire b_is_jal     = (b_op == 7'b1101111);
    wire b_is_jalr    = (b_op == 7'b1100111);
    wire b_is_system  = (b_op == 7'b1110011);
    wire b_is_fence   = (b_op == 7'b0001111);
    wire b_is_muldiv  = (b_op == 7'b0110011) & (b_f7 == 7'b0000001);

    wire b_pipe_a_only = b_is_branch | b_is_jal | b_is_jalr
                       | b_is_system | b_is_fence | b_is_muldiv;

    // -----------------------------------------------------------------
    // Memory conflict: at most one load/store per cycle (single DRAM port)
    // -----------------------------------------------------------------
    wire a_is_load  = (a_op == 7'b0000011);
    wire a_is_store = (a_op == 7'b0100011);
    wire b_is_load  = (b_op == 7'b0000011);
    wire b_is_store = (b_op == 7'b0100011);
    wire mem_conflict = (a_is_load | a_is_store) & (b_is_load | b_is_store);

    // -----------------------------------------------------------------
    // RAW dependency: A writes rd, B reads it as rs1 or rs2
    // -----------------------------------------------------------------
    // Does slot A write a register?
    wire a_writes = (a_op == 7'b0110011)   // R-type
                  | (a_op == 7'b0010011)   // I-type ALU
                  | (a_op == 7'b0000011)   // LOAD
                  | (a_op == 7'b1101111)   // JAL
                  | (a_op == 7'b1100111)   // JALR
                  | (a_op == 7'b0110111)   // LUI
                  | (a_op == 7'b0010111)   // AUIPC
                  | (a_is_csr);            // CSR (rd = old CSR value)

    // Which source registers does slot B actually use?
    // LUI (0110111) and AUIPC (0010111) use neither rs1 nor rs2.
    wire b_uses_rs1 = (b_op != 7'b0110111) & (b_op != 7'b0010111);
    // Only R-type and STORE use rs2.
    wire b_uses_rs2 = (b_op == 7'b0110011) | (b_op == 7'b0100011);

    wire raw_hazard = a_writes & (a_rd != 5'b0)
                    & ( (b_uses_rs1 & (a_rd == b_rs1))
                      | (b_uses_rs2 & (a_rd == b_rs2)) );

    // -----------------------------------------------------------------
    // Fast ALU: A's result available combinationally in EX, enabling
    // intra-group A→B forwarding for producer-consumer pairs.
    // -----------------------------------------------------------------
    wire a_is_fast_alu = ((a_op == 7'b0110011) & (a_f7 != 7'b0000001)) // R-type non-M
                       | (a_op == 7'b0010011)   // I-type ALU
                       | (a_op == 7'b0110111)   // LUI
                       | (a_op == 7'b0010111);  // AUIPC

    // RAW that cannot be resolved by intra-group forwarding
    wire raw_hazard_hard = raw_hazard & ~a_is_fast_alu;

    // -----------------------------------------------------------------
    // Final decision
    // -----------------------------------------------------------------
    assign can_dual = b_fetched
                    & ~a_serialising
                    & ~b_pipe_a_only
                    & ~mem_conflict
                    & ~raw_hazard_hard;

endmodule
