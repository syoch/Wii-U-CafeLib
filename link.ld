OUTPUT_ARCH(powerpc)
ENTRY(code)

MEMORY
{
  rom(rxai) : ORIGIN = 0x00000000, LENGTH = 16k
  ram(rwai) : ORIGIN = 0x20000000, LENGTH = 16k
}

SECTIONS{
  
  .data :
  {
    rodata_start = .;
    *(.rodata.cst4)
    *(.rodata.cst8)
    rodata_end = .;
  } > ram,
  .text : 
  {
    *(.startup) 
    *(.code) 
    *(.init) 
    *(.text)
    text_end = .;
    rodata_size = rodata_end - rodata_start;
  } > rom,
}