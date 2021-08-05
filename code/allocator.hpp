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
