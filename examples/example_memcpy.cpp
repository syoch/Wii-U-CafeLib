// Copyright 2021 syoch. All rights reserved.
#include "code/code.hpp"

inline void code_main() {
  code::memcpy((uint32_t*)0x20000000, (uint32_t*)0x20001000, 0x1000);
}