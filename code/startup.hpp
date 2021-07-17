#include <inttypes.h>

#include <cstddef>

#include "memcpy.hpp"

void code();

extern "C" {
uint32_t rodata_size;
uint32_t rodata_start;
uint32_t rodata_end;

__attribute__((section(".startup"))) int startup() {
  register uint32_t* src;
  register uint32_t* dest __asm__("r4");
  register size_t size;

  // set some data pointers
  // set dest
  asm volatile(
      "lis %[dest], (rodata_start-4)@h\n"
      "ori %[dest], %[dest], (rodata_start-4)@l\n"
      : [dest] "=r"(dest));
  // set allocator
  *(uint32_t**)(0x20000000) = &rodata_end;

  // get size
  asm volatile("li %[size], rodata_size\n" : [size] "=r"(size));

  // get src
  asm volatile(
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src],  text_end - . + 4"
      : [src] "=r"(src)
      :
      : "lr");
  // copy src to dest
  memcpy(src, dest, size);
  asm volatile("code:");
  code();
  asm volatile("code_end:");
  return 0;
}
}