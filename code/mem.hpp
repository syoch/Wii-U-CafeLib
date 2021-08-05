// Copyright 2021 syoch. All rights reserved.

#pragma once

#include <cinttypes>
namespace code {

class Mem {
 private:
  uint32_t base;

 public:
  explicit Mem(uint32_t addr) { base = addr; }

  Mem operator[](size_t index) {
    return Mem(*reinterpret_cast<uint32_t*>(base) + index);
  }

  template <typename T>
  T& as() {
    return *reinterpret_cast<T*>(base);
  }
};

}  // namespace code
