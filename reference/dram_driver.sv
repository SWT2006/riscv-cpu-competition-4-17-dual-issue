`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module: dram_driver — BRAM-based data memory (replaces distributed RAM IP)
//
// Optimizations over original distributed-RAM (DRAM IP) implementation:
//   1. Block RAM instead of distributed RAM → eliminates fanout=4353 RAMS64E
//      routing bottleneck, freeing ~90% of the critical-path routing delay.
//   2. Byte-write enables → eliminates read-modify-write for SB/SH stores.
//   3. Negedge-clocked read port → maintains same-cycle read semantics without
//      any pipeline changes (address sampled mid-cycle, data ready before next
//      posedge).
//
// Resource usage: ~64× RAMB36E1 (14.4% of xc7k325t-ffg900-2)
//
// Timing model (50 MHz, 20 ns period):
//   posedge N  : EX/MEM pipeline register drives addr; write commits here
//   negedge N  : BRAM read port latches addr (10 ns into cycle)
//   +~2 ns     : BRAM clk-to-out, read data stable on rdata_reg
//   posedge N+1: MEM/WB pipeline register captures data (~8 ns margin)
//
// Interface is identical to the original — no changes in perip_bridge,
// student_top, or any CPU pipeline stage.
//////////////////////////////////////////////////////////////////////////////////

module dram_driver(
    input  logic         clk,

    input  logic [17:0]  perip_addr,
    input  logic [31:0]  perip_wdata,
    input  logic [1:0]   perip_mask,
    input  logic         dram_wen,
    output logic [31:0]  perip_rdata
);
    logic [15:0] addr;
    logic [1:0]  offset;
    logic [3:0]  byte_we;
    logic [31:0] wdata_aligned;

    assign addr   = perip_addr[17:2];
    assign offset = perip_addr[1:0];

    // =========================================================================
    // Byte-write enable & data alignment
    // =========================================================================
    // Generates per-byte write enables and places store data into the correct
    // byte lane.  This eliminates the read-modify-write dependency loop that
    // the original distributed-RAM design required for SB/SH instructions.
    always_comb begin
        byte_we       = 4'b0000;
        wdata_aligned = 32'b0;
        if (dram_wen) begin
            case (perip_mask)
                2'b10: begin // SW — write all 4 bytes
                    byte_we       = 4'b1111;
                    wdata_aligned = perip_wdata;
                end
                2'b01: begin // SH — write 2 bytes at halfword-aligned position
                    case (offset[1])
                        1'b0: begin
                            byte_we       = 4'b0011;
                            wdata_aligned = {16'b0, perip_wdata[15:0]};
                        end
                        1'b1: begin
                            byte_we       = 4'b1100;
                            wdata_aligned = {perip_wdata[15:0], 16'b0};
                        end
                    endcase
                end
                2'b00: begin // SB — write 1 byte at exact byte offset
                    case (offset)
                        2'b00: begin
                            byte_we       = 4'b0001;
                            wdata_aligned = {24'b0, perip_wdata[7:0]};
                        end
                        2'b01: begin
                            byte_we       = 4'b0010;
                            wdata_aligned = {16'b0, perip_wdata[7:0], 8'b0};
                        end
                        2'b10: begin
                            byte_we       = 4'b0100;
                            wdata_aligned = {8'b0, perip_wdata[7:0], 16'b0};
                        end
                        2'b11: begin
                            byte_we       = 4'b1000;
                            wdata_aligned = {perip_wdata[7:0], 24'b0};
                        end
                    endcase
                end
                default: begin
                    byte_we       = 4'b1111;
                    wdata_aligned = perip_wdata;
                end
            endcase
        end
    end

    // =========================================================================
    // Block RAM — 64K × 32-bit (256 KB)
    // =========================================================================
    (* ram_style = "block" *) logic [31:0] mem [0:65535];

    // Optional: pre-load DRAM content for synthesis.
    // Convert the Vivado COE file to plain hex (one 32-bit word per line)
    // and place it alongside the project sources.
    // initial $readmemh("dram_init.hex", mem);

    // Write port — posedge, byte-granular (same timing as original distRAM)
    always_ff @(posedge clk) begin
        for (int i = 0; i < 4; i++) begin
            if (byte_we[i])
                mem[addr][i*8 +: 8] <= wdata_aligned[i*8 +: 8];
        end
    end

    // Read port — negedge (mid-cycle latch preserves same-cycle read semantics)
    logic [31:0] rdata_reg;
    always_ff @(negedge clk) begin
        rdata_reg <= mem[addr];
    end

    // =========================================================================
    // Byte / halfword extraction (combinatorial, identical to original)
    // =========================================================================
    always_comb begin
        perip_rdata = 32'b0;
        case (perip_mask)
            2'b00: // LB / LBU — extract single byte (sign extension in stage_mem)
                case (offset)
                    2'b00: perip_rdata = {24'b0, rdata_reg[7:0]};
                    2'b01: perip_rdata = {24'b0, rdata_reg[15:8]};
                    2'b10: perip_rdata = {24'b0, rdata_reg[23:16]};
                    2'b11: perip_rdata = {24'b0, rdata_reg[31:24]};
                endcase
            2'b01: // LH / LHU — extract halfword
                case (offset[1])
                    1'b0: perip_rdata = {16'b0, rdata_reg[15:0]};
                    1'b1: perip_rdata = {16'b0, rdata_reg[31:16]};
                endcase
            2'b10: perip_rdata = rdata_reg; // LW — full word
            default: perip_rdata = 32'b0;
        endcase
    end

endmodule
