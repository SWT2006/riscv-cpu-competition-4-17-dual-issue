iverilog -g2012 -DIROM_HEX=\"src0_irom.hex\" -DDRAM_HEX=\"src0_dram.hex\" -DTEST_NAME=\"src0\" tb_coe.v sim_soc.v ../rtl/*.sv -o baseline_test.vvp
