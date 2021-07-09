#!/bin/bash
cd $(dirname $0)
PATH=/opt/devkitpro/devkitPPC/bin/:$PATH

powerpc-eabi-gcc \
  -nostdlib \
  -Os -fno-unroll-loops \
  raw.cpp \
  -Wl,-T,link.ld \
  -o raw.o \
|| exit
powerpc-eabi-strip -N rodata_size raw.o 

powerpc-eabi-objcopy --only-section=.text raw.o -O binary text.bin
powerpc-eabi-objcopy --only-section=.data raw.o -O binary data.bin
powerpc-eabi-objdump \
  --section=.text \
  -d raw.o
hexdump \
  -e '4/1 "%02x" " " 4/1 "%02x" "\n"' \
  text.bin data.bin > dump
cat dump | xsel --clipboard --input
rm dump
rm text.bin data.bin
exit