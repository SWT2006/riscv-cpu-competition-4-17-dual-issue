#!/usr/bin/env python3
"""
compile_rtl.py  –  Compile the RISC-V 5-stage pipeline CPU RTL with iverilog.

Usage (called internally by the simulation driver scripts):
    python compile_rtl.py <project_root>

  <project_root>  Path to the riscv-cpu-competition root, relative to the
                  directory where iverilog will be invoked (i.e. the CWD of
                  the caller script).

  From validate/sim/                → project_root = '../..'
  From validate/sim/compliance_test → project_root = '../../..'
"""

import sys
import subprocess
import os


def main():
    if len(sys.argv) < 2:
        print("Usage: compile_rtl.py <project_root>")
        sys.exit(1)

    rtl_dir = sys.argv[1]

    # Choose testbench based on which directory the caller lives in
    cwd = os.getcwd().replace('\\', '/')
    if 'compliance_test' in cwd:
        tb_file = '/tb/compliance_test/tinyriscv_soc_tb.v'
    else:
        tb_file = '/tb/tinyriscv_soc_tb.v'

    iverilog_cmd = ['iverilog']
    iverilog_cmd += ['-o', 'out.vvp']
    iverilog_cmd += ['-g2012']          # Verilog-2012 / SystemVerilog lite
    iverilog_cmd += ['-Wall']

    # Testbench
    iverilog_cmd.append(rtl_dir + tb_file)

    # RTL source files
    rtl_files = [
        '/rtl/control_unit.v',
        '/rtl/cpu_top.v',
        '/rtl/csr_unit.v',
        '/rtl/data_memory.v',
        '/rtl/forwarding_unit.v',
        '/rtl/hazard_unit.v',
        '/rtl/imm_gen.v',
        '/rtl/instruction_memory.v',
        '/rtl/pipe_exmem.v',
        '/rtl/pipe_idex.v',
        '/rtl/pipe_ifid.v',
        '/rtl/pipe_memwb.v',
        '/rtl/riscv_soc.v',
        '/rtl/stage_ex.v',
        '/rtl/stage_id.v',
        '/rtl/stage_if.v',
        '/rtl/stage_mem.v',
        '/rtl/stage_wb.v',
    ]
    for f in rtl_files:
        iverilog_cmd.append(rtl_dir + f)

    print('Compiling: ' + ' '.join(iverilog_cmd))
    process = subprocess.Popen(iverilog_cmd)
    process.wait(timeout=60)
    if process.returncode != 0:
        print('!!! iverilog compilation FAILED (return code %d) !!!' % process.returncode)
        sys.exit(process.returncode)


if __name__ == '__main__':
    sys.exit(main())
