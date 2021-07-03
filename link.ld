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
    rodata_start = .;
    *(.rodata.cst4)
    *(.rodata.cst8)
    rodata_end = .;
  } > rom
}