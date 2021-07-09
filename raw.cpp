#include "code.hpp"

inline void code() {
  *(float *)(0x20000100) += 1;
  return;
}