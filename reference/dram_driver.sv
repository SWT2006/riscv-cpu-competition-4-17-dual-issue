`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module: dram_driver — BRAM-based data memory (replaces distributed RAM IP)
//
// Posedge-clocked read port using an early address from the EX stage.
// The EX-stage ALU result (the load/store address) is forwarded one cycle
// before the EX/MEM register latches it, so the BRAM can sample it at the
// same posedge that commits the pipeline stage transition.
//
// A store-load bypass detects when the write port and read port hit the same
// word address on the same posedge and forwards the written bytes, because
// 7-series true-dual-port BRAM returns the OLD value on cross-port collision.
//
// Resource usage: ~64× RAMB36E1 split across two 32K banks (no cascade)
//////////////////////////////////////////////////////////////////////////////////

module dram_driver(
    input  logic         clk,

    input  logic [17:0]  perip_addr,
    input  logic [31:0]  perip_wdata,
    input  logic [1:0]   perip_mask,
    input  logic         dram_wen,
    input  logic [15:0]  raddr,          // early read word-address from EX stage
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
    always_comb begin
        byte_we       = 4'b0000;
        wdata_aligned = 32'b0;
        if (dram_wen) begin
            case (perip_mask)
                2'b10: begin // SW
                    byte_we       = 4'b1111;
                    wdata_aligned = perip_wdata;
                end
                2'b01: begin // SH
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
                2'b00: begin // SB
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
    // Block RAM — split into two independent 32K×32-bit banks (128 KB each).
    //
    // Rationale: a single 64K-word array forces Vivado to cascade two chains
    // of RAMB36E1 blocks.  The cascade wiring requires ADDRARDADDR[15] to be
    // identical on both the write port (addr[15]) and the read port (raddr[15])
    // of each cascaded pair — a constraint that cannot be satisfied when the two
    // addresses are independent signals (DRC REQP-1962).
    //
    // Splitting on addr[15]/raddr[15] gives each bank a 15-bit address and
    // eliminates cascade entirely.  Vivado infers two separate BRAM groups.
    // =========================================================================
    (* ram_style = "block" *) logic [31:0] mem_lo [0:32767]; // addr[15]=0
    (* ram_style = "block" *) logic [31:0] mem_hi [0:32767]; // addr[15]=1

    initial begin
        $readmemh("D:/file/integrated circuit competition/coe/hex/dram0.hex", mem_lo);
    end

    // Write port — posedge, byte-granular, bank-selected on addr[15]
    always_ff @(posedge clk) begin
        for (int i = 0; i < 4; i++) begin
            if (byte_we[i]) begin
                if (addr[15])
                    mem_hi[addr[14:0]][i*8 +: 8] <= wdata_aligned[i*8 +: 8];
                else
                    mem_lo[addr[14:0]][i*8 +: 8] <= wdata_aligned[i*8 +: 8];
            end
        end
    end

    // Read port — posedge, uses early address from EX stage.
    // Both banks are read every cycle; the registered bank-select mux picks
    // the correct result one cycle after the address is sampled.
    logic [31:0] rdata_lo, rdata_hi;
    logic        rsel;
    always_ff @(posedge clk) begin
        rdata_lo <= mem_lo[raddr[14:0]];
        rdata_hi <= mem_hi[raddr[14:0]];
        rsel     <= raddr[15];
    end
    logic [31:0] rdata_raw;
    assign rdata_raw = rsel ? rdata_hi : rdata_lo;

    // Store-load bypass: when write and read hit the same word on the same
    // posedge, the BRAM read returns the old value.  Capture the write info
    // alongside the read and merge after clk-to-out.
    logic        bypass_hit;
    logic [3:0]  bypass_we;
    logic [31:0] bypass_data;
    always_ff @(posedge clk) begin
        bypass_hit  <= dram_wen & (addr == raddr);
        bypass_we   <= byte_we;
        bypass_data <= wdata_aligned;
    end

    logic [31:0] rdata_resolved;
    always_comb begin
        rdata_resolved = rdata_raw;
        if (bypass_hit) begin
            for (int i = 0; i < 4; i++) begin
                if (bypass_we[i])
                    rdata_resolved[i*8 +: 8] = bypass_data[i*8 +: 8];
            end
        end
    end

    // =========================================================================
    // Byte / halfword extraction (combinatorial, identical to original)
    // =========================================================================
    always_comb begin
        perip_rdata = 32'b0;
        case (perip_mask)
            2'b00:
                case (offset)
                    2'b00: perip_rdata = {24'b0, rdata_resolved[7:0]};
                    2'b01: perip_rdata = {24'b0, rdata_resolved[15:8]};
                    2'b10: perip_rdata = {24'b0, rdata_resolved[23:16]};
                    2'b11: perip_rdata = {24'b0, rdata_resolved[31:24]};
                endcase
            2'b01:
                case (offset[1])
                    1'b0: perip_rdata = {16'b0, rdata_resolved[15:0]};
                    1'b1: perip_rdata = {16'b0, rdata_resolved[31:16]};
                endcase
            2'b10: perip_rdata = rdata_resolved;
            default: perip_rdata = 32'b0;
        endcase
    end

endmodule
