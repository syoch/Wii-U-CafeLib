OUTPUT_ARCH(powerpc)
ENTRY(startup)

MEMORY
{
  rom(rxai) : ORIGIN = 0x02000000, LENGTH = 16m
  ram(rwai) : ORIGIN = 0x10018000, LENGTH = 16m
/* you can use 0x10400000 instead of ram's origin address */
}

SECTIONS{

  .data :
  {
    allocator_pointer = .; . += 4;
    . += 0x4;
    . += 0x4;
    . += 0x4;


    rodata_start = .;
    *(.sdata._ZZnwjE3ptr)
    *(.sdata)
    *(.sdata.*)
    *(.rodata)
    *(.rodata.*)
    *(.bss)
    *(.bss.*)
    *(.sbss)
    *(.sbss.*)
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