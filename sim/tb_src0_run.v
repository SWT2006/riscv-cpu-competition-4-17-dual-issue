// Thin wrapper: sets the hex file defines for src0, then includes tb_coe.v.
`define IROM_HEX "src0_irom.hex"
`define DRAM_HEX "src0_dram.hex"
`define TEST_NAME "src0"
`define MAX_CYCLES 3000000

`include "tb_coe.v"
