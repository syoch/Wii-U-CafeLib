#!/bin/bash
cd $(dirname $0)
PATH=/opt/devkitpro/devkitPPC/bin/:$PATH

powerpc-eabi-gcc -nostdlib -O3 raw.cpp -Wl,-T,link.ld -o raw.o || exit
powerpc-eabi-objcopy --only-section=.text raw.o -O binary raw.bin
powerpc-eabi-objdump -h raw.o | c++filt
hexdump \
  -e '4/1 "%02x" " " 4/1 "%02x" "\n"' \
  raw.bin | xsel --clipboard --input