#include <inttypes.h>

#include <cstddef>

void code();

extern "C" {
uint32_t rodata_size;
uint32_t rodata_start;

inline void words_copy(uint32_t* src, uint32_t* dest, size_t size) {
  asm volatile("copy:");
  for (register size_t i = size; i != 0; --i) {
    *(++dest) = *(++src);
  }
}
__attribute__((section(".startup"))) int startup() {
  register uint32_t* src;
  register uint32_t* dest __asm__("r4");
  register size_t size;

  // set some data pointers
  asm volatile(
      "__get_dest:"
      "lis %[dest], (rodata_start-4)@h\n"
      "ori %[dest], %[dest], (rodata_start-4)@l\n"

      "__get_size:"
      "li %[size], rodata_size\n"

      "__get_src:"
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src],  text_end - . + 4"

      : [dest] "=r"(dest), [size] "=r"(size), [src] "=r"(src)
      :
      : "lr");
  // copy src to dest
  words_copy(src, dest, size);
  asm volatile("code:");
  code();
  asm volatile("code_end:");
  return 0;
}
}