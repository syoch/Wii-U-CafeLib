#include <inttypes.h>
#include <stdlib.h>

#pragma GCC optimize("unroll-loops")

void code();
uint32_t* GetTextEnd();
extern const void* rodata_start;
extern const void* rodata_end;

#pragma GCC push_options

__attribute__((section(".startup"))) int startup() {
  register uint32_t* src;
  register uint32_t* dest __asm__("r4");

  // get data start
  asm volatile(
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src], text_end - . - 8"
      :
      : [src] "r"(src));
  dest = (uint32_t*)(0x20000000) - 1;

  // copy to 2000_0000h
  asm volatile(
      "li 10, rodata_size\n"
      "mtctr 10\n"
      "Loop1:\n"
      "  lwzu 10, 4(%[src])\n"
      "  stwu 10, 4(%[dest])\n"
      "  bdnz Loop1"
      : [src] "+r"(src), [dest] "+r"(dest)
      :
      : "r10");
  // code();

  return 0;
}

#pragma GCC pop_options