// Copyright 2021 syoch. All rights reserved.

#pragma once

#include <cinttypes>
namespace code {
template <typename T>
class MemSetter {
 private:
  uint32_t base;

 public:
  explicit MemSetter(uint32_t base) : base(base) {}
  void operator=(T val) { *(T*)(base) = val; }
};

class Mem {
 private:
  uint32_t base;

 public:
  explicit Mem(uint32_t addr) { base = addr; }

  Mem operator[](size_t index) {
    return Mem(*reinterpret_cast<uint32_t*>(base) + index);
  }

  template <typename T>
  MemSetter<T> as() {
    return MemSetter<T>(base);
  }
};

}  // namespace code
