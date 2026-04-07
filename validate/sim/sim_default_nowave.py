#!/usr/bin/env python3
"""
sim_default_nowave.py  –  Compile & run without waveform (no binary conversion).
Uses whatever inst.data already exists in the CWD.

Usage (from validate/sim/):
    python sim_default_nowave.py
"""

import subprocess
import sys
import os


def main():
    # Step 1: Compile RTL
    cmd = 'python compile_rtl.py ../..'
    f = os.popen(cmd)
    output = f.read()
    f.close()
    if output:
        print(output, end='')

    # Step 2: Run simulation
    vvp_cmd = ['vvp', 'out.vvp']
    process = subprocess.Popen(vvp_cmd)
    try:
        process.wait(timeout=30)
    except subprocess.TimeoutExpired:
        process.kill()
        print('!!!Fail, vvp exec timeout!!!')


if __name__ == '__main__':
    sys.exit(main())
