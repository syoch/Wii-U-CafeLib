#include "code.hpp"

inline void code() {
  *(new int) = 1;
  asm volatile("code_:");
  *(new float) = 1;
  // *(new uint32_t) = 1;
  return;
}