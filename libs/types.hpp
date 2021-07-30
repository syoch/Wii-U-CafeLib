#pragma once
using uint8_t = unsigned char;
using uint32_t = unsigned int;
using size_t = uint32_t;

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