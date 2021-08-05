// Copyright 2021 syoch. All rights reserved.

#pragma once

#include <cstddef>
namespace code {
template <typename T>
inline void memcpy(T* src, T* dest, const size_t count) {
  src--;
  dest--;
  for (register size_t i = count; i != 0; --i) {
    *(++dest) = *(++src);
  }
}
}  // namespace code
