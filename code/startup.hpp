// Copyright 2021 syoch. All rights reserved.

#pragma once

#include <inttypes.h>

#include <cstddef>

#include "common.hpp"
#include "memcpy.hpp"

void code_main();

namespace code {
//! dont call this function!!!
inline void copy_data() {
  register uint32_t* src;

  // get src
  asm volatile(
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src],  text_end - . + 4"
      : [src] "=r"(src)
      :
      : "lr");

  // copy src to dest
  memcpy(src, static_cast<uint32_t*>(&rodata_start),
         reinterpret_cast<size_t>(&rodata_size));
}
}  // namespace code

extern "C" __attribute__((section(".startup"))) int startup() {
#ifndef NO_DATA_COPY
  code::copy_data();
#endif

  asm volatile("_startup_main:");
  code_main();
  asm volatile("_startup_main_end:");
  return 0;
}
