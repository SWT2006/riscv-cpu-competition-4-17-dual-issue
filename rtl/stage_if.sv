`timescale 1ns/1ps
// IF stage: program counter, instruction fetch, and branch prediction.
// PC resets to 0x8000_0000 to match the board address map.
//
// Prediction sources (all from combinational IROM output, same cycle):
//
//   1. Early JAL resolution
//      True JAL (opcode 1101111) target = PC + J-imm.  Zero-cycle penalty.
//      FENCE.I (opcode 0001111) is NOT matched — it flushes via EX path.
//
//   2. Static branch prediction (BTFNT — Backward Taken, Forward Not Taken)
//      B-type (opcode 1100011) with negative immediate (inst[31]=1, backward)
//      is predicted taken.  Target = PC + B-imm.  Zero-cycle penalty on hit.
//      Forward branches (inst[31]=0) are predicted not-taken (fall through).
//
//   3. Return Address Stack (RAS)
//      4-entry circular stack.  CALL pattern (JAL/JALR with rd=x1 or x5)
//      pushes PC+4.  RETURN pattern (JALR with rs1=x1 or x5, rd not link)
//      pops and predicts target.  Coroutine swap (rd and rs1 both link,
//      rd != rs1) pops for prediction then pushes PC+4.
//
// The `predicted` flag and `predicted_target` accompany the instruction
// through IF/ID → ID/EX so that EX can detect mispredictions:
//   - Direction mismatch:  actual_taken XOR predicted
//   - Target mismatch:     predicted & taken & JALR & (target != predicted_target)
// On mispredict, EX redirects PC and flushes the pipeline.
module stage_if (
    input  wire        clk,
    input  wire        cpu_rst,
    input  wire        stall,          // hold PC (load-use / multi-cycle EX)
    input  wire        branch_taken,   // redirect PC (mispredict recovery from EX)
    input  wire [31:0] branch_target,
    // IROM interface
    output wire [31:0] irom_word_addr,
    input  wire [31:0] irom_data,
    // Outputs to IF/ID pipeline register
    output reg  [31:0] pc_out,
    output wire [31:0] pc_plus4,
    output wire [31:0] instruction,
    output wire        predicted,         // IF-stage prediction active
    output wire [31:0] predicted_target   // predicted next-PC (for EX verification)
);
    localparam RESET_PC = 32'h8000_0000;

    // -----------------------------------------------------------------
    // Instruction field extraction (combinational, from IROM output)
    // -----------------------------------------------------------------
    wire [6:0] opcode = irom_data[6:0];
    wire [4:0] if_rd  = irom_data[11:7];
    wire [4:0] if_rs1 = irom_data[19:15];

    // -----------------------------------------------------------------
    // 1) JAL detection
    // -----------------------------------------------------------------
    wire if_is_jal = (opcode == 7'b1101111);

    wire [31:0] jal_imm = {{12{irom_data[31]}}, irom_data[19:12],
                            irom_data[20], irom_data[30:21], 1'b0};
    wire [31:0] jal_target = pc_out + jal_imm;

    // -----------------------------------------------------------------
    // 2) Conditional branch detection & BTFNT prediction
    // -----------------------------------------------------------------
    wire if_is_branch = (opcode == 7'b1100011);

    // B-type immediate (matches imm_gen.sv B-type case exactly)
    wire [31:0] b_imm = {{20{irom_data[31]}}, irom_data[7],
                          irom_data[30:25], irom_data[11:8], 1'b0};
    wire [31:0] branch_predict_target = pc_out + b_imm;

    // Backward = negative offset = sign bit set → predict taken
    wire if_backward = irom_data[31];
    wire branch_predict_taken = if_is_branch & if_backward;

    // -----------------------------------------------------------------
    // 3) JALR detection & Return Address Stack (RAS)
    // -----------------------------------------------------------------
    wire if_is_jalr = (opcode == 7'b1100111);

    // Link register detection (x1 = ra, x5 = t0/alternate link)
    wire if_rd_is_link  = (if_rd == 5'd1) | (if_rd == 5'd5);
    wire if_rs1_is_link = (if_rs1 == 5'd1) | (if_rs1 == 5'd5);

    // CALL:   JAL/JALR writing to link register → push PC+4
    wire is_call = (if_is_jal | if_is_jalr) & if_rd_is_link;
    // RETURN: JALR reading from link register, not writing to (different) link
    //         Includes coroutine swap: rd=link, rs1=link, rd != rs1
    wire is_return = if_is_jalr & if_rs1_is_link
                   & (~if_rd_is_link | (if_rd != if_rs1));

    // 4-entry circular RAS
    reg [31:0] ras [0:3];
    reg [1:0]  ras_ptr;            // next write position (past top)

    wire [31:0] ras_top = ras[ras_ptr - 2'd1];  // current top of stack
    wire ras_predict = is_return;  // always predict returns

    // -----------------------------------------------------------------
    // Combined IF-stage prediction
    //   Priority: JAL > backward-branch > RAS (mutually exclusive opcodes)
    // -----------------------------------------------------------------
    wire if_predict = if_is_jal | branch_predict_taken | ras_predict;

    wire [31:0] if_predict_target = if_is_jal           ? jal_target :
                                    branch_predict_taken ? branch_predict_target :
                                                           ras_top;

    // -----------------------------------------------------------------
    // PC update & RAS management
    //   Priority: reset > EX mispredict redirect > IF prediction > PC+4
    // -----------------------------------------------------------------
    always @(posedge clk) begin
        if (cpu_rst) begin
            pc_out  <= RESET_PC;
            ras_ptr <= 2'd0;
        end else if (branch_taken) begin
            // EX-stage mispredict recovery — redirect PC, don't touch RAS
            // (the flushed IF instruction's RAS effect is suppressed)
            pc_out <= branch_target;
        end else if (!stall) begin
            pc_out <= if_predict ? if_predict_target : (pc_out + 32'd4);

            // RAS management (call/return detection from current instruction)
            if (is_call & is_return) begin
                // Coroutine swap: pop for prediction, overwrite top with new return
                ras[ras_ptr - 2'd1] <= pc_out + 32'd4;
                // ras_ptr unchanged (push + pop cancel out)
            end else if (is_call) begin
                ras[ras_ptr] <= pc_out + 32'd4;
                ras_ptr      <= ras_ptr + 2'd1;
            end else if (is_return) begin
                ras_ptr <= ras_ptr - 2'd1;
            end
        end
    end

    // -----------------------------------------------------------------
    // Outputs
    // -----------------------------------------------------------------
    assign irom_word_addr   = pc_out;
    assign pc_plus4         = pc_out + 32'd4;
    assign instruction      = irom_data;

    // predicted: high when IF made a prediction and the instruction will
    // advance into IF/ID (not stalled, not overridden by EX redirect).
    assign predicted        = if_predict & ~stall & ~branch_taken;
    assign predicted_target = if_predict_target;

endmodule
