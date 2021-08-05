// Copyright 2021 syoch. All rights reserved.

#define NO_DATA_COPY
#include "code/code.hpp"

inline void code_main() { code::Mem(0x20000000)[4][4].as<uint32_t>() = 1; }
