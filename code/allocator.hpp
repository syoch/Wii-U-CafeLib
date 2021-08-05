// Copyright 2021 syoch. All rights reserved.

#pragma once

#include <inttypes.h>

#include <cstddef>
#include <type_traits>
#include <vector>

#include "common.hpp"

namespace code {
inline void* allocate(std::size_t size) {
  auto ptr = allocator_pointer;
  allocator_pointer += size;
  return ptr;
}

}  // namespace code

inline void* operator new(size_t size) { return code::allocate(size); }
inline void* operator new[](size_t size) { return operator new(size); }
inline void operator delete(void* ptr) {}
