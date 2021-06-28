#!/bin/bash
cd $(dirname $0)
/opt/devkitpro/devkitPPC/bin/powerpc-eabi-gcc -Os -nostdlib -c raw.cpp -o raw.o
/opt/devkitpro/devkitPPC/bin/powerpc-eabi-objdump -d raw.o