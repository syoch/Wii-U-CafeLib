#!/bin/bash
cd $(dirname $0)
PATH=$PATH:/opt/devkitpro/devkitPPC/bin/

powerpc-eabi-gcc -Os -nostdlib -c raw.cpp -o raw.o
powerpc-eabi-objdump -d raw.o
powerpc-eabi-objcopy raw.o raw.bin -O binary