#include <inttypes.h>

#include <cstddef>

void code();

extern "C" {
uint32_t rodata_size;
uint32_t rodata_start;

__attribute__((section(".startup"))) int startup() {
  register uint32_t* src;
  register uint32_t* dest __asm__("r4");
  register size_t size;

  // get data start
  asm volatile(
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src], text_end - ."
      : [src] "=r"(src)
      :
      : "lr");
  dest = (uint32_t*)(&rodata_start) - 1;
  size = (size_t)(&rodata_size);

  // copy to 2000_0000h
  asm volatile(
      "mtctr %[size]\n"
      "Loop1:\n"
      "  lwzu 10, 4(%[src])\n"
      "  stwu 10, 4(%[dest])\n"
      "  bdnz Loop1"
      : [src] "+r"(src), [dest] "+r"(dest)
      : [size] "r"(size)
      : "r10", "ctr");
  asm volatile("code:");
  code();

  return 0;
}
}