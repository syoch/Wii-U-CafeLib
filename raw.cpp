// Copyright 2021 syoch. All rights reserved.

#include "code/code.hpp"

inline void code_main() {
  *(volatile uint32_t*)0xf0 = (uint32_t)code::allocate(4);
  asm volatile("main0:");
  *(volatile uint32_t*)0xf0 = (uint32_t)code::allocate(4);
  asm volatile("main1:");
  *(volatile uint32_t*)0xf0 = (uint32_t)code::allocate(4);
}
