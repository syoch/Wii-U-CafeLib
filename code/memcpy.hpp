#pragma once
using size_t = uint32_t;

template <typename T>
inline void memcpy(T* src, T* dest, const size_t count) {
  src--;
  dest--;
  for (register size_t i = count; i != 0; --i) {
    *(++dest) = *(++src);
  }
}