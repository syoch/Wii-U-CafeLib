OUTPUT_ARCH(powerpc)
ENTRY(code)

MEMORY
{
  rom(rxai) : ORIGIN = 0x00000000, LENGTH = 16k
}

SECTIONS{
  .text : 
  {
      *(.text)
      *(.rodata.cst4)
  } > rom,
}