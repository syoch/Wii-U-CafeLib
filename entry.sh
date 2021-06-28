#!/bin/bash
cd $(dirname $0)
PATH=/opt/devkitpro/devkitPPC/bin/:$PATH

powerpc-eabi-gcc -Os -nostdlib -c raw.cpp -o raw.o
powerpc-eabi-objcopy --only-section=.text raw.o -O binary raw.bin
powerpc-eabi-objdump -d raw.o | c++filt
hexdump \
  -e '4/1 "%02x" " " 4/1 "%02x" "\n"' \
  raw.bin | xsel --clipboard --input