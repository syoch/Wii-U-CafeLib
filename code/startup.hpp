#include <inttypes.h>

#include <cstddef>

#include "memcpy.hpp"

void code();

extern "C" {
uint32_t rodata_size;
uint32_t rodata_start;
uint32_t rodata_end;
void copy_data() {
  register uint32_t* src;
  register uint32_t* dest __asm__("r4");
  register size_t size;

  // set some data pointers
  size = (size_t)&rodata_size;              // get size
  dest = (uint32_t*)&rodata_start - 1;      // set dest
  *(uint32_t**)(0x20000000) = &rodata_end;  // set allocator

  // get src
  asm volatile(
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src],  text_end - ."
      : [src] "=r"(src)
      :
      : "lr");

  // copy src to dest
  memcpy(src, dest, size);
}
__attribute__((section(".startup"))) int startup() {
  // copy data
  if constexpr (&rodata_start != &rodata_end) copy_data();

  asm volatile("_startup_main:");
  code();
  asm volatile("_startup_main_end:");
}
}