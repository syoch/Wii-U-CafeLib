#!/bin/bash
cd $(dirname $0)
PATH=/opt/devkitpro/devkitPPC/bin/:$PATH

powerpc-eabi-gcc \
  -nostdlib \
  -O3 \
  raw.cpp init.s \
  -Wl,-T,link.ld \
  -o raw.o \
|| exit

powerpc-eabi-objcopy --only-section=.text raw.o -O binary text.bin
powerpc-eabi-objcopy --only-section=.data raw.o -O binary data.bin
powerpc-eabi-objdump \
  --section=.init \
  --section=.text \
  -d raw.o
hexdump \
  -e '4/1 "%02x" " " 4/1 "%02x" "\n"' \
  text.bin data.bin | tee dump
cat dump | xsel --clipboard --input
rm dump
rm text.bin data.bin
exit