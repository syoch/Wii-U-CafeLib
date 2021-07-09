#include "code.hpp"
#include "rawFunc.cpp"

void code() {
  *(float *)(0x20000100) = 1;
  return;
}