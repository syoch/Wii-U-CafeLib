OUTPUT_ARCH(powerpc)
ENTRY(startup)

MEMORY
{
  rom(rxai) : ORIGIN = 0x00000000, LENGTH = 16k
  ram(rwai) : ORIGIN = 0x20000000, LENGTH = 16k
}

SECTIONS{
  
  .data :
  {
    rodata_start = .;
    *(.rodata.*)
    rodata_end = .;
  } > ram,
  .text : 
  {
    *(.startup) 
    *(.code) 
    *(.init) 
    *(.text)
    text_end = .;
    rodata_size = (rodata_end - rodata_start)/4;
  } > rom,
}