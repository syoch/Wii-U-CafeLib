#include <inttypes.h>
#include <stddef.h>

extern "C" void code();
extern "C" uint32_t rodata_size;

extern "C" __attribute__((section(".startup"))) int startup() {
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
  dest = (uint32_t*)(0x20000000) - 1;
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
  code();

  return 0;
}