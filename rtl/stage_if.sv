`timescale 1ns/1ps
// 2-wide IF stage: program counter, dual instruction fetch, issue check,
// and branch prediction.
//
// Fetches two instructions per cycle (inst_a at PC, inst_b at PC+4).
// Uses issue_unit to determine if both can dual-issue.
// Applies prediction on slot A only (slot B never contains branch/jump
// because the issue check excludes them from Pipe B).
//
// IROM timing model (posedge BRAM):
//   irom_addr is a combinational next-fetch address driven to the BRAM.
//   At posedge N the BRAM captures this address and registers the read.
//   After clk-to-out the instruction is available; stage_if decodes it
//   and computes the next irom_addr combinationally before posedge N+1.
//   pc_out tracks which PC the current BRAM output corresponds to.
//
// PC advancement:
//   - Mispredict redirect from EX: next_fetch = redirect target
//   - Stall: next_fetch = pc_out (re-read same instruction)
//   - Slot A predicted taken: next_fetch = prediction target, slot B invalid
//   - Dual-issue: next_fetch = pc_out + 8
//   - Single-issue: next_fetch = pc_out + 4
//
// Prediction sources (applied to slot A only):
//   1. JAL: zero-cycle resolution (PC + J-imm)
//   2. BTFNT: Backward Taken, Forward Not Taken (static)
//   3. RAS: 8-entry return address stack for JALR returns
module stage_if (
    input  wire        clk,
    input  wire        cpu_rst,
    input  wire        stall,            // pipeline stall (load-use / multi-cycle EX)
    input  wire        branch_taken,     // mispredict redirect from EX
    input  wire [31:0] branch_target,
    // IROM interface — 2-wide
    output wire [31:0] irom_addr,        // combinational next-fetch address
    input  wire [31:0] irom_data_0,      // instruction at pc_out
    input  wire [31:0] irom_data_1,      // instruction at pc_out+4
    // Outputs to IF/ID register
    output reg  [31:0] pc_out,
    output wire [31:0] pc_a_plus4,
    output wire [31:0] pc_b,
    output wire [31:0] pc_b_plus4,
    output wire [31:0] inst_a,
    output wire [31:0] inst_b,
    output wire        b_valid,          // slot B can dual-issue
    output wire        predicted_a,
    output wire [31:0] predicted_target_a,
    output wire        predicted_b,      // always 0 (slot B has no branches)
    output wire [31:0] predicted_target_b
);
    localparam RESET_PC = 32'h8000_0000;

    // =================================================================
    // Instruction field extraction (from BRAM output, combinational)
    // =================================================================
    wire [6:0] a_opcode = irom_data_0[6:0];
    wire [4:0] a_rd     = irom_data_0[11:7];
    wire [4:0] a_rs1    = irom_data_0[19:15];

    // =================================================================
    // 1) JAL detection (slot A only)
    // =================================================================
    wire a_is_jal = (a_opcode == 7'b1101111);

    wire [31:0] jal_imm = {{12{irom_data_0[31]}}, irom_data_0[19:12],
                            irom_data_0[20], irom_data_0[30:21], 1'b0};
    wire [31:0] jal_target = pc_out + jal_imm;

    // =================================================================
    // 2) Conditional branch detection & BTFNT (slot A only)
    // =================================================================
    wire a_is_branch = (a_opcode == 7'b1100011);

    wire [31:0] b_imm = {{20{irom_data_0[31]}}, irom_data_0[7],
                          irom_data_0[30:25], irom_data_0[11:8], 1'b0};
    wire [31:0] branch_predict_target = pc_out + b_imm;

    wire a_backward = irom_data_0[31];
    wire branch_predict_taken = a_is_branch & a_backward;

    // =================================================================
    // 3) JALR detection & Return Address Stack (slot A only)
    // =================================================================
    wire a_is_jalr = (a_opcode == 7'b1100111);

    wire a_rd_is_link  = (a_rd  == 5'd1) | (a_rd  == 5'd5);
    wire a_rs1_is_link = (a_rs1 == 5'd1) | (a_rs1 == 5'd5);

    wire is_call   = (a_is_jal | a_is_jalr) & a_rd_is_link;
    wire is_return = a_is_jalr & a_rs1_is_link
                   & (~a_rd_is_link | (a_rd != a_rs1));

    // 8-entry circular RAS
    reg [31:0] ras [0:7];
    reg [2:0]  ras_ptr;

    wire [31:0] ras_top = ras[ras_ptr - 3'd1];
    wire ras_predict = is_return;

    // =================================================================
    // Combined slot A prediction
    // =================================================================
    wire predict_a = a_is_jal | branch_predict_taken | ras_predict;

    wire [31:0] predict_target_a = a_is_jal            ? jal_target :
                                   branch_predict_taken ? branch_predict_target :
                                                          ras_top;

    // =================================================================
    // Issue check: can slot B dual-issue alongside slot A?
    // =================================================================
    wire can_dual_raw;

    issue_unit u_issue (
        .inst_a    (irom_data_0),
        .inst_b    (irom_data_1),
        .b_fetched (1'b1),           // always have 2nd instruction from IROM
        .can_dual  (can_dual_raw)
    );

    // Slot B is valid only if:
    //   - issue check passes
    //   - slot A is NOT predicted taken (slot B would be on wrong path)
    wire can_dual_final = can_dual_raw & ~predict_a;

    // =================================================================
    // Next fetch address (combinational, drives BRAM for the next posedge)
    // =================================================================
    wire [31:0] next_fetch = cpu_rst        ? RESET_PC :
                             branch_taken   ? branch_target :
                             stall          ? pc_out :
                             predict_a      ? predict_target_a :
                             can_dual_final ? (pc_out + 32'd8) :
                                             (pc_out + 32'd4);

    assign irom_addr = next_fetch;

    // =================================================================
    // PC update & RAS management
    // =================================================================
    always @(posedge clk) begin
        if (cpu_rst) begin
            pc_out  <= RESET_PC;
            ras_ptr <= 3'd0;
        end else begin
            if (branch_taken || !stall)
                pc_out <= next_fetch;

            if (!stall && !branch_taken) begin
                if (is_call & is_return) begin
                    ras[ras_ptr - 3'd1] <= pc_out + 32'd4;
                end else if (is_call) begin
                    ras[ras_ptr] <= pc_out + 32'd4;
                    ras_ptr      <= ras_ptr + 3'd1;
                end else if (is_return) begin
                    ras_ptr <= ras_ptr - 3'd1;
                end
            end
        end
    end

    // =================================================================
    // Outputs
    // =================================================================
    assign pc_a_plus4 = pc_out + 32'd4;
    assign pc_b       = pc_out + 32'd4;
    assign pc_b_plus4 = pc_out + 32'd8;
    assign inst_a     = irom_data_0;
    assign inst_b     = irom_data_1;

    // b_valid: slot B instruction is valid for dual-issue this cycle
    assign b_valid = can_dual_final & ~stall & ~branch_taken;

    // Slot A prediction output (only when advancing, not stalled/redirected)
    assign predicted_a        = predict_a & ~stall & ~branch_taken;
    assign predicted_target_a = predict_target_a;

    // Slot B never has branches/jumps (excluded by issue check)
    assign predicted_b        = 1'b0;
    assign predicted_target_b = 32'b0;

endmodule
