// Minimal CSR register file: mtvec, mepc, mcause, mstatus
// Supports enough for rv32i compliance test ECALL/MRET flow.
module csr_unit (
    input  wire        clk,
    input  wire        rst_n,
    // ID-stage combinatorial read
    input  wire [11:0] csr_raddr,
    output reg  [31:0] csr_rdata,
    // EX-stage CSR write (from CSR instructions, registered next cycle)
    input  wire        csr_wen,
    input  wire [11:0] csr_waddr,
    input  wire [31:0] csr_wdata,
    // EX-stage ECALL/EBREAK trap: update mepc/mcause with priority over csr_wen
    input  wire        trap_ecall,
    input  wire [31:0] trap_epc,
    input  wire [31:0] trap_mcause,   // 3=EBREAK, 11=ECALL
    input  wire [31:0] trap_mtval,    // faulting address
    // Direct registered outputs consumed by EX stage for branch targets
    output reg  [31:0] mtvec,
    output reg  [31:0] mepc
);
    reg [31:0] mcause;
    reg [31:0] mstatus;
    reg [31:0] mtval;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mtvec   <= 32'd4;   // cold reset: trap vector = 0x4
            mepc    <= 32'b0;
            mcause  <= 32'b0;
            mstatus <= 32'b0;
            mtval   <= 32'b0;
        end else begin
            // ECALL trap update takes priority for mepc and mcause
            if (trap_ecall) begin
                mepc   <= trap_epc;
                mcause <= trap_mcause;
                mtval  <= trap_mtval;
            end
            if (csr_wen) begin
                case (csr_waddr)
                    12'h300: mstatus <= csr_wdata;
                    12'h305: mtvec   <= csr_wdata;
                    12'h341: if (!trap_ecall) mepc   <= csr_wdata;
                    12'h342: if (!trap_ecall) mcause <= csr_wdata;
                    12'h343: if (!trap_ecall) mtval  <= csr_wdata;
                    default: ;
                endcase
            end
        end
    end

    always @(*) begin
        case (csr_raddr)
            12'h300: csr_rdata = mstatus;
            12'h305: csr_rdata = mtvec;
            12'h341: csr_rdata = mepc;
            12'h342: csr_rdata = mcause;
            12'h343: csr_rdata = mtval;
            default: csr_rdata = 32'b0;
        endcase
    end

endmodule
