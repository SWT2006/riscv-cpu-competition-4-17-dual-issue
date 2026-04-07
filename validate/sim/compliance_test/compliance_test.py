#!/usr/bin/env python3
"""
compliance_test.py  –  Run a single riscv-compliance test and compare its
signature output against the golden reference.

Usage (from validate/sim/compliance_test/):
    python compliance_test.py <test.elf.bin> <inst.data>

Example:
    python compliance_test.py ../../tests/riscv-compliance/build_generated/rv32i/I-ADD-01.elf.bin inst.data
"""

import sys
import os
import subprocess
import filecmp


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def list_ref_files(path):
    files = []
    for maindir, subdir, all_file in os.walk(path):
        for filename in all_file:
            apath = os.path.join(maindir, filename)
            if apath.endswith('.reference_output'):
                files.append(apath)
    return files


def get_reference_file(bin_file):
    file_path, file_name = os.path.split(bin_file)
    prefix = file_name.split('.')[0]

    base = os.path.join(os.path.dirname(__file__),
                        '..', '..', 'tests', 'riscv-compliance',
                        'riscv-test-suite')

    if 'rv32im' in bin_file:
        files = list_ref_files(os.path.join(base, 'rv32im', 'references'))
    elif 'rv32i' in bin_file:
        files = list_ref_files(os.path.join(base, 'rv32i', 'references'))
    elif 'rv32Zicsr' in bin_file:
        files = list_ref_files(os.path.join(base, 'rv32Zicsr', 'references'))
    elif 'rv32Zifencei' in bin_file:
        files = list_ref_files(os.path.join(base, 'rv32Zifencei', 'references'))
    else:
        return None

    for f in files:
        if prefix in f:
            return f
    return None


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) < 3:
        print("Usage: compliance_test.py <test.elf.bin> <inst.data>")
        sys.exit(1)

    bin_file = sys.argv[1]
    mem_file = sys.argv[2]

    # Step 1: Convert .bin → inst.data
    tools_dir = os.path.join(os.path.dirname(__file__),
                             '..', '..', '..', 'tools')
    bintomem = os.path.join(tools_dir, 'BinToMem_CLI.py')
    cmd = 'python {} {} {}'.format(bintomem, bin_file, mem_file)
    f = os.popen(cmd)
    f.close()

    # Step 2: Compile RTL  (project root is three levels up from here)
    cmd = 'python ../compile_rtl.py ../../..'
    f = os.popen(cmd)
    output = f.read()
    f.close()
    if output:
        print(output, end='')

    # Step 3: Run simulation
    logfile = open('run.log', 'w')
    vvp_cmd = ['vvp', 'out.vvp']
    process = subprocess.Popen(vvp_cmd, stdout=logfile, stderr=logfile)
    try:
        process.wait(timeout=30)
    except subprocess.TimeoutExpired:
        process.kill()
        print('!!! COMPLIANCE_TIMEOUT !!!')
        logfile.close()
        return
    logfile.close()

    # Step 4: Compare signature
    ref_file = get_reference_file(bin_file)
    if ref_file is None:
        print('No reference file found – check result manually.')
        return

    if not os.path.exists('signature.output'):
        print('!!! FAIL, signature.output not generated !!!')
        return

    if os.path.getsize('signature.output') != os.path.getsize(ref_file):
        print('!!! FAIL, size mismatch (got %d, want %d) !!!' %
              (os.path.getsize('signature.output'), os.path.getsize(ref_file)))
        return

    with open('signature.output') as f1, open(ref_file) as f2:
        for lineno, (got, want) in enumerate(zip(f1, f2), 1):
            if got != want:
                print('!!! FAIL, line %d: got %r  want %r !!!' % (lineno, got, want))
                return

    print('### PASS ###')


if __name__ == '__main__':
    sys.exit(main())
