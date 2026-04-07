#!/usr/bin/env python3
"""
sim_new_nowave.py  –  Run a single ISA test binary without waveform output.

Usage (from validate/sim/):
    python sim_new_nowave.py <test.bin> <inst.data>

Example:
    python sim_new_nowave.py ../tests/isa/generated/rv32ui-p-add.bin inst.data
"""

import sys
import subprocess
import os


def main():
    if len(sys.argv) < 3:
        print("Usage: sim_new_nowave.py <test.bin> <inst.data>")
        sys.exit(1)

    bin_file = sys.argv[1]
    mem_file = sys.argv[2]

    # Step 1: Convert .bin → inst.data (32-bit word hex, one per line)
    tools_dir = os.path.join(os.path.dirname(__file__), '..', '..', 'tools')
    bintomem  = os.path.join(tools_dir, 'BinToMem_CLI.py')
    cmd = 'python {} {} {}'.format(bintomem, bin_file, mem_file)
    f = os.popen(cmd)
    f.close()

    # Step 2: Compile RTL  (project root is two levels up from validate/sim/)
    cmd = 'python compile_rtl.py ../..'
    f = os.popen(cmd)
    output = f.read()
    f.close()
    if output:
        print(output, end='')

    # Step 3: Run simulation
    vvp_cmd = ['vvp', 'out.vvp']
    process = subprocess.Popen(vvp_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    try:
        stdout, stderr = process.communicate(timeout=30)
    except subprocess.TimeoutExpired:
        process.kill()
        print('!!!Fail, vvp exec timeout!!!')
        return

    output = stdout.decode('utf-8', errors='replace') + stderr.decode('utf-8', errors='replace')
    print(output, end='')


if __name__ == '__main__':
    sys.exit(main())
