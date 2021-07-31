OUTPUT_ARCH(powerpc)
ENTRY(startup)

MEMORY
{
  rom(rxai) : ORIGIN = 0x00000000, LENGTH = 16m
  ram(rwai) : ORIGIN = 0x10400010, LENGTH = 16m
}

SECTIONS{
  
  .data :
  {
    rodata_start = .;
    *(.sdata._ZZnwjE3ptr)
    *(.sdata)
    *(.sdata.*)
    *(.rodata.*)
    *(.bss)
    *(.bss.*)
    rodata_end = .;
  } > ram,
  .text : 
  {
    *(.startup) 
    *(.text.*)
    text_end = .;
    rodata_size = (rodata_end - rodata_start)/4;
  } > rom,
}