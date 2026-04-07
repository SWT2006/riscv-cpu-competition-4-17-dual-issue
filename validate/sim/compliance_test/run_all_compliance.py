#!/usr/bin/env python3
"""
run_all_compliance.py – Run all rv32i (and rv32Zifencei) compliance tests.

Run from validate/sim/compliance_test/
    python run_all_compliance.py [--suite rv32i|rv32im|rv32Zifencei|all]

Each test:
  1. Converts the pre-compiled .elf.bin to inst.data
  2. Compiles RTL once (shared)
  3. Runs VVP with the compliance testbench
  4. Compares signature.output against the golden reference
"""

import os
import sys
import subprocess
import shutil
import argparse
import re

BUILD_ROOT = os.path.join(os.path.dirname(__file__),
                          '..', '..', 'tests', 'riscv-compliance', 'build_generated')
REF_ROOT   = os.path.join(os.path.dirname(__file__),
                          '..', '..', 'tests', 'riscv-compliance', 'riscv-test-suite')
TOOLS_DIR  = os.path.join(os.path.dirname(__file__),
                          '..', '..', '..', 'tools')


def get_sig_params(bin_path):
    """Parse objdump to find begin_signature and end_signature byte addresses.
    Returns (sig_base_word, sig_words).  Falls back to (0x800, 36) if not found."""
    objdump = bin_path.replace('.elf.bin', '.elf.objdump')
    if not os.path.exists(objdump):
        return (0x800, 36)
    begin_sig = None
    end_sig   = None
    with open(objdump) as f:
        for line in f:
            m = re.match(r'^([0-9a-f]+)\s+<begin_signature>', line)
            if m:
                begin_sig = int(m.group(1), 16)
            m = re.match(r'^([0-9a-f]+)\s+<end_signature>', line)
            if m:
                end_sig = int(m.group(1), 16)
    if begin_sig is None or end_sig is None or end_sig <= begin_sig:
        return (0x800, 36)
    sig_base_word = begin_sig // 4
    sig_words     = (end_sig - begin_sig) // 4
    return (sig_base_word, sig_words)


def list_bins(suite):
    """Return sorted list of (bin_path, ref_path) pairs for a given suite."""
    build_dir = os.path.join(BUILD_ROOT, suite)
    ref_dir   = os.path.join(REF_ROOT, suite, 'references')
    if not os.path.isdir(build_dir):
        return []
    pairs = []
    for fname in sorted(os.listdir(build_dir)):
        if not fname.endswith('.elf.bin'):
            continue
        bin_path = os.path.join(build_dir, fname)
        stem     = fname.split('.')[0]          # e.g. "I-ADD-01"
        ref_path = os.path.join(ref_dir, stem + '.reference_output')
        pairs.append((bin_path, ref_path if os.path.exists(ref_path) else None))
    return pairs


def compile_once():
    cmd = [sys.executable, '../compile_rtl.py', '../../..']
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
    if result.returncode != 0:
        print('!!! RTL compilation failed !!!')
        print(result.stdout + result.stderr)
        sys.exit(1)
    print('RTL compiled OK.\n')


def run_single(bin_path, ref_path):
    """Convert, simulate, compare.  Returns (result_str, detail)."""
    # Step 1: bin → inst.data
    bintomem = os.path.join(TOOLS_DIR, 'BinToMem_CLI.py')
    subprocess.run([sys.executable, bintomem, bin_path, 'inst.data'],
                   check=True, capture_output=True, timeout=30)

    # Step 2: simulate with correct signature region from objdump
    if os.path.exists('signature.output'):
        os.remove('signature.output')

    sig_base_word, sig_words = get_sig_params(bin_path)
    vvp = subprocess.run(
        ['vvp', 'out.vvp',
         '+sig_base=%d' % sig_base_word,
         '+sig_words=%d' % sig_words],
        capture_output=True, text=True, timeout=60)

    if 'COMPLIANCE_TIMEOUT' in (vvp.stdout + vvp.stderr):
        return 'TIMEOUT', '(tohost write never seen)'

    if not os.path.exists('signature.output'):
        return 'FAIL', '(signature.output not generated)'

    # Step 3: compare
    if ref_path is None:
        return 'NOREF', '(no reference file found)'

    with open('signature.output') as f:
        got_lines = f.readlines()
    with open(ref_path) as f:
        ref_lines = f.readlines()

    if len(got_lines) != len(ref_lines):
        return 'FAIL', '(line count mismatch: got {:d}, want {:d})'.format(
            len(got_lines), len(ref_lines))

    for i, (got, want) in enumerate(zip(got_lines, ref_lines), 1):
        if got.strip() != want.strip():
            return 'FAIL', '(line {:d}: got {} want {})'.format(
                i, got.strip(), want.strip())

    return 'PASS', ''


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--suite', default='rv32i',
                        choices=['rv32i', 'rv32im', 'rv32Zifencei', 'rv32Zicsr', 'all'],
                        help='Which compliance suite to run (default: rv32i)')
    args = parser.parse_args()

    suites = ['rv32i', 'rv32im', 'rv32Zifencei'] if args.suite == 'all' else [args.suite]

    compile_once()

    totals = {'PASS': 0, 'FAIL': 0, 'TIMEOUT': 0, 'NOREF': 0}
    all_failures = []

    for suite in suites:
        pairs = list_bins(suite)
        if not pairs:
            print('[{}] No binaries found – skipping.'.format(suite))
            continue
        print('[{}] {:d} tests'.format(suite, len(pairs)))

        for bin_path, ref_path in pairs:
            name = os.path.basename(bin_path)
            result, detail = run_single(bin_path, ref_path)
            totals[result] = totals.get(result, 0) + 1
            marker = 'PASS' if result == 'PASS' else '!!! {:6s} !!!'.format(result)
            print('  {:<42s}  {}'.format(name, marker))
            if result not in ('PASS', 'NOREF'):
                all_failures.append((suite, name, result, detail))

    print()
    print('─' * 60)
    print('Compliance results: PASS={PASS}  FAIL={FAIL}  TIMEOUT={TIMEOUT}  NOREF={NOREF}'.format(**totals))

    if all_failures:
        print()
        print('Failures:')
        for suite, name, result, detail in all_failures:
            print('  [{:s}] {:s}  →  {:s}  {:s}'.format(suite, name, result, detail))
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
