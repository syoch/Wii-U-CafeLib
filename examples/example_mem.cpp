// Copyright 2021 syoch. All rights reserved.
#include "code/code.hpp"

inline void code_main() {
  code::Mem(0x20000000)[4][4].as<uint32_t>() =
      code::Mem(0x20000000)[4][8].as<uint32_t>();
}