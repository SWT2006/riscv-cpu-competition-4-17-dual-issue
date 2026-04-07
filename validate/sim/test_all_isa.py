#!/usr/bin/env python3
"""
test_all_isa.py  –  Run all ISA regression tests found in tests/isa/generated/.

Usage (from validate/sim/):
    python test_all_isa.py
"""

import os
import subprocess
import sys


def list_binfiles(path):
    files = []
    for maindir, subdir, all_file in os.walk(path):
        for filename in all_file:
            apath = os.path.join(maindir, filename)
            if apath.endswith('.bin'):
                files.append(apath)
    return sorted(files)


def main():
    bin_dir  = os.path.join(os.path.dirname(__file__), '..', 'tests', 'isa', 'generated')
    bin_files = list_binfiles(bin_dir)

    if not bin_files:
        print('No .bin test files found in', bin_dir)
        sys.exit(1)

    passed   = 0
    failed   = 0
    any_fail = False

    for f in bin_files:
        cmd = ['python', 'sim_new_nowave.py', f, 'inst.data']
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        output = result.stdout + result.stderr

        if 'TEST_PASS' in output:
            print('{:<60s}  PASS'.format(os.path.basename(f)))
            passed += 1
        else:
            print('{:<60s}  !!!FAIL!!!'.format(os.path.basename(f)))
            if output.strip():
                for line in output.strip().splitlines():
                    print('    ' + line)
            failed += 1
            any_fail = True

    print()
    print('Results: %d PASS,  %d FAIL  (total %d)' % (passed, failed, passed + failed))

    if not any_fail:
        print('Congratulations, All PASS...')
    else:
        sys.exit(1)


if __name__ == '__main__':
    sys.exit(main())
