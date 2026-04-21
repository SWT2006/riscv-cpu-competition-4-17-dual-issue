`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module: irom_driver — Block-RAM IROM with 2 read ports for dual-issue fetch.
//
// Replaces the single-port Xilinx IROM IP so that the 2-wide pipeline can
// fetch two instructions per cycle (slot A at PC, slot B at PC+4).
//
// Posedge-clocked read ports:
//   stage_if drives irom_addr as a combinational next-fetch address.
//   At posedge N the BRAM captures that address and registers the read data.
//   After clk-to-out (~2 ns) the instruction is available for decode /
//   prediction in stage_if, giving a full-period posedge-to-posedge path.
//
// Initialization: Vivado reads the $readmemh initial block to pre-load BRAM
// content at synthesis time.  Point IROM_HEX to the hex file converted from
// the competition COE file (one 32-bit hex word per line).
//////////////////////////////////////////////////////////////////////////////////

module irom_driver (
    input  logic        clk,
    input  logic [11:0] addr,       // word address (combinational from stage_if)
    output logic [31:0] rdata_0,    // instruction at addr   (slot A)
    output logic [31:0] rdata_1     // instruction at addr+1 (slot B)
);

    // =========================================================================
    // Block RAM — 4096 x 32-bit (16 KB)
    // =========================================================================
    (* ram_style = "block" *) logic [31:0] mem [0:4095];

    // Pre-load from hex file.  For Vivado synthesis, place the hex file in the
    // project source directory.  The parameter / define can be overridden per
    // build configuration.
    initial begin
        $readmemh("D:/file/integrated circuit competition/coe/hex/irom0.hex", mem);
    end

    // =========================================================================
    // Dual read ports — posedge clocked
    // =========================================================================
    // Vivado infers true dual-port BRAM: port A at addr, port B at addr+1.
    // Both use the read-only path (no write port needed for instruction ROM).
    always_ff @(posedge clk) begin
        rdata_0 <= mem[addr];
        rdata_1 <= mem[addr + 12'd1];
    end

endmodule
