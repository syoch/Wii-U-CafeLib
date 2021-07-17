#include <inttypes.h>

#include <cstddef>

inline void words_copy(uint32_t* src, uint32_t* dest, size_t size) {
  asm volatile("copy:");
  for (register size_t i = size; i != 0; --i) {
    *(++dest) = *(++src);
  }
}