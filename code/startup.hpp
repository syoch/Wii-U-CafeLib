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
  asm volatile(
      "__get_dest:"
      "lis %[dest], (rodata_start-4)@h\n"
      "ori %[dest], %[dest], (rodata_start-4)@l\n"
      : [dest] "=r"(dest));

  asm volatile("__set_allocator:");
  *(uint32_t**)(0x20000000) = &rodata_end;

  asm volatile(
      "__get_size:"
      "li %[size], rodata_size\n"
      : [size] "=r"(size));

  asm volatile(
      "__get_src:"
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src],  text_end - . + 4"
      : [src] "=r"(src)
      :
      : "lr");
  // copy src to dest
  asm volatile("copy:");
  memcpy(src, dest, size);
  asm volatile("code:");
  code();
  asm volatile("code_end:");
  return 0;
}
}