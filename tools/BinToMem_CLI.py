#!/usr/bin/env python3
"""
BinToMem_CLI.py - Convert a raw binary file to a Verilog $readmemh-compatible
hex memory file (one little-endian 32-bit word per line).

Usage:
    python BinToMem_CLI.py <input.bin> <output.mem>
"""

import sys
import struct


def main():
    if len(sys.argv) < 3:
        print("Usage: BinToMem_CLI.py <input.bin> <output.mem>")
        sys.exit(1)

    bin_file = sys.argv[1]
    mem_file = sys.argv[2]

    with open(bin_file, 'rb') as f:
        data = f.read()

    # Pad to 4-byte boundary
    while len(data) % 4 != 0:
        data += b'\x00'

    with open(mem_file, 'w') as f:
        for i in range(0, len(data), 4):
            word = struct.unpack_from('<I', data, i)[0]   # little-endian 32-bit word
            f.write('{:08x}\n'.format(word))


if __name__ == '__main__':
    main()
