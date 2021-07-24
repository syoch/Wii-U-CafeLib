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

  // get src
  asm volatile(
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src],  text_end - . + 4"
      : [src] "=r"(src)
      :
      : "lr");

  // copy src to dest
  memcpy(src, (uint32_t*)&rodata_start, (size_t)&rodata_size);
}
__attribute__((section(".startup"))) int startup() {
  // copy data
  if constexpr (&rodata_start != &rodata_end) copy_data();

  asm volatile("_startup_main:");
  code();
  asm volatile("_startup_main_end:");
  return 0;
}
}