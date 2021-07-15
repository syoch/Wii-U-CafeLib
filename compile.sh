#!/bin/bash
cd $(dirname $0)
PATH=/opt/devkitpro/devkitPPC/bin/:$PATH

# compile
powerpc-eabi-gcc \
  -nostdlib \
  -Os -fno-unroll-loops \
  -Wall -Wno-register \
  -ffunction-sections -Wl,--gc-sections \
  raw.cpp \
  -Wl,-T,link.ld \
  -o raw.o \
|| exit
powerpc-eabi-strip -N rodata_size raw.o 

# list up all section headers
powerpc-eabi-objdump -h raw.o

# debug
powerpc-eabi-objdump \
  --section=.text \
  -d raw.o

# make code.bin
powerpc-eabi-objcopy --only-section=.text raw.o -O binary text.bin
powerpc-eabi-objcopy --only-section=.data raw.o -O binary data.bin
cat text.bin data.bin > code.bin
rm text.bin data.bin

# make hex
hexdump \
  -e '4/1 "%02x" " " 4/1 "%02x" "\n"' \
  code.bin > dump
cat dump | xsel --clipboard --input
rm dump


# rm temp files
rm raw.o code.bin
exit