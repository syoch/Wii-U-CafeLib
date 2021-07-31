#pragma once
#include <inttypes.h>

template <typename T>
struct shared_ptr {
 public:
  shared_ptr(T *p) {
    ptr = p;
    cnt = 0;
  }
  shared_ptr() {
    ptr = 0;
    cnt = 0;
  }
  T *ptr;
  uint32_t cnt;
};
struct vector {
  uint32_t field_0x0;
  uint32_t field_0x4;
  uint32_t field_0x8;
  uint32_t field_0xc;
};