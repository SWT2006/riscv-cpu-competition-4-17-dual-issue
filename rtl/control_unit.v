module control_unit (
    input  wire [6:0] opcode,
    input  wire [2:0] funct3,
    input  wire [6:0] funct7,
    output reg  [4:0] alu_op,       // 5 bits to cover M-extension opcodes
    output reg        alu_src,      // 0: rs2, 1: immediate
    output reg        mem_read,
    output reg        mem_write,
    output reg        reg_write,
    output reg  [1:0] wb_sel,       // 00: ALU, 01: MEM, 10: PC+4
    output reg        branch,
    output reg        jal,
    output reg        jalr,
    output reg        lui,
    output reg        auipc,
    output reg        ecall,        // ECALL/EBREAK: trap to mtvec
    output reg        mret,         // MRET: return to mepc
    output reg        csr_op        // CSR read/write instruction
);

    // ALU operation encoding
    localparam ALU_ADD    = 5'd0;
    localparam ALU_SUB    = 5'd1;
    localparam ALU_SLL    = 5'd2;
    localparam ALU_SLT    = 5'd3;
    localparam ALU_SLTU   = 5'd4;
    localparam ALU_XOR    = 5'd5;
    localparam ALU_SRL    = 5'd6;
    localparam ALU_SRA    = 5'd7;
    localparam ALU_OR     = 5'd8;
    localparam ALU_AND    = 5'd9;
    localparam ALU_PASS_B = 5'd10;  // Pass operand B (for LUI)
    // M-extension (funct7 = 7'b0000001)
    localparam ALU_MUL    = 5'd11;  // MUL    lower 32 bits signed*signed
    localparam ALU_MULH   = 5'd12;  // MULH   upper 32 bits signed*signed
    localparam ALU_MULHSU = 5'd13;  // MULHSU upper 32 bits signed*unsigned
    localparam ALU_MULHU  = 5'd14;  // MULHU  upper 32 bits unsigned*unsigned
    localparam ALU_DIV    = 5'd15;  // DIV    signed division
    localparam ALU_DIVU   = 5'd16;  // DIVU   unsigned division
    localparam ALU_REM    = 5'd17;  // REM    signed remainder
    localparam ALU_REMU   = 5'd18;  // REMU   unsigned remainder

    always @(*) begin
        // Default values (NOP-safe)
        alu_op    = ALU_ADD;
        alu_src   = 1'b0;
        mem_read  = 1'b0;
        mem_write = 1'b0;
        reg_write = 1'b0;
        wb_sel    = 2'b00;
        branch    = 1'b0;
        jal       = 1'b0;
        jalr      = 1'b0;
        lui       = 1'b0;
        auipc     = 1'b0;
        ecall     = 1'b0;
        mret      = 1'b0;
        csr_op    = 1'b0;

        case (opcode)
            // ----- R-type: register-register ALU -----
            7'b0110011: begin
                reg_write = 1'b1;
                alu_src   = 1'b0;
                wb_sel    = 2'b00;
                if (funct7 == 7'b0000001) begin
                    // M extension
                    case (funct3)
                        3'b000: alu_op = ALU_MUL;
                        3'b001: alu_op = ALU_MULH;
                        3'b010: alu_op = ALU_MULHSU;
                        3'b011: alu_op = ALU_MULHU;
                        3'b100: alu_op = ALU_DIV;
                        3'b101: alu_op = ALU_DIVU;
                        3'b110: alu_op = ALU_REM;
                        3'b111: alu_op = ALU_REMU;
                        default: alu_op = ALU_ADD;
                    endcase
                end else begin
                    // Base integer
                    case (funct3)
                        3'b000: alu_op = (funct7[5]) ? ALU_SUB : ALU_ADD;  // ADD/SUB
                        3'b001: alu_op = ALU_SLL;
                        3'b010: alu_op = ALU_SLT;
                        3'b011: alu_op = ALU_SLTU;
                        3'b100: alu_op = ALU_XOR;
                        3'b101: alu_op = (funct7[5]) ? ALU_SRA : ALU_SRL;  // SRL/SRA
                        3'b110: alu_op = ALU_OR;
                        3'b111: alu_op = ALU_AND;
                        default: alu_op = ALU_ADD;
                    endcase
                end
            end

            // ----- I-type: ALU with immediate -----
            7'b0010011: begin
                reg_write = 1'b1;
                alu_src   = 1'b1;
                wb_sel    = 2'b00;
                case (funct3)
                    3'b000: alu_op = ALU_ADD;
                    3'b001: alu_op = ALU_SLL;
                    3'b010: alu_op = ALU_SLT;
                    3'b011: alu_op = ALU_SLTU;
                    3'b100: alu_op = ALU_XOR;
                    3'b101: alu_op = (funct7[5]) ? ALU_SRA : ALU_SRL;
                    3'b110: alu_op = ALU_OR;
                    3'b111: alu_op = ALU_AND;
                    default: alu_op = ALU_ADD;
                endcase
            end

            // ----- LOAD -----
            7'b0000011: begin
                reg_write = 1'b1;
                alu_src   = 1'b1;
                alu_op    = ALU_ADD;
                mem_read  = 1'b1;
                wb_sel    = 2'b01;  // From memory
            end

            // ----- STORE -----
            7'b0100011: begin
                alu_src   = 1'b1;
                alu_op    = ALU_ADD;
                mem_write = 1'b1;
            end

            // ----- BRANCH -----
            7'b1100011: begin
                branch    = 1'b1;
                alu_src   = 1'b0;
                alu_op    = ALU_SUB;
            end

            // ----- LUI -----
            7'b0110111: begin
                reg_write = 1'b1;
                lui       = 1'b1;
                alu_src   = 1'b1;
                alu_op    = ALU_PASS_B;
                wb_sel    = 2'b00;
            end

            // ----- AUIPC -----
            7'b0010111: begin
                reg_write = 1'b1;
                auipc     = 1'b1;
                alu_src   = 1'b1;
                alu_op    = ALU_ADD;
                wb_sel    = 2'b00;
            end

            // ----- JAL -----
            7'b1101111: begin
                reg_write = 1'b1;
                jal       = 1'b1;
                wb_sel    = 2'b10;  // PC+4
            end

            // ----- JALR -----
            7'b1100111: begin
                reg_write = 1'b1;
                jalr      = 1'b1;
                alu_src   = 1'b1;
                alu_op    = ALU_ADD;
                wb_sel    = 2'b10;  // PC+4
            end

            // ----- FENCE / FENCE.I: flush pipeline by branching to PC+4 -----
            // reg_write stays 0 (no link register write).
            // jal=1 causes branch_taken=1 in EX; imm_gen returns 4 so
            // branch_target = PC+4, flushing the 2 wrongly-fetched instructions.
            7'b0001111: begin
                jal = 1'b1;
            end

            // ----- SYSTEM: ECALL, MRET, CSR instructions -----
            7'b1110011: begin
                if (funct3 == 3'b000) begin
                    // funct7==0x18 (0b0011000) → MRET; anything else → ECALL/EBREAK
                    if (funct7 == 7'b0011000)
                        mret  = 1'b1;
                    else
                        ecall = 1'b1;
                end else begin
                    // CSRRW/CSRRS/CSRRC/CSRRWI/CSRRSI/CSRRCI
                    // rd gets old CSR value; alu_result carries it via wb_sel=00
                    csr_op    = 1'b1;
                    reg_write = 1'b1;
                    wb_sel    = 2'b00;
                end
            end

            default: begin
                // NOP
            end
        endcase
    end

endmodule
