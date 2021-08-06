// Copyright 2021 syoch. All rights reserved.
#include "code/code.hpp"

inline void code_main() {
  int* ptr = reinterpret_cast<int*>(code::allocate(sizeof(int)));
  *ptr = 0;
}