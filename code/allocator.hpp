// Copyright 2021 syoch. All rights reserved.

#pragma once

#include <inttypes.h>

#include <cstddef>

extern "C" uint32_t rodata_end;

namespace code {

struct Allocator {
  uint8_t* addr;

  explicit constexpr Allocator(uint8_t* addr) : addr(addr) {}

  inline constexpr uint8_t* malloc(int n) {
    auto ret = addr;
    addr += n;
    return ret;
  }
};

Allocator allocator(reinterpret_cast<uint8_t*>(&rodata_end));
inline constexpr uint8_t* malloc(int n) { return allocator.malloc(n); }
}  // namespace code

inline void* operator new(size_t size) { return code::allocator.malloc(size); }
inline void* operator new[](size_t size) { return operator new(size); }
inline void operator delete(void* ptr, size_t size) {}
