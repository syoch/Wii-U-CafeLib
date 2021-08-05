// Copyright 2021 syoch. All rights reserved.

#ifndef RAW_CODE_COMMON_HPP_
#define RAW_CODE_COMMON_HPP_

extern "C" {
uint32_t rodata_start;
uint32_t rodata_size;
uint32_t rodata_end;

uint8_t* allocator_pointer;
};

#endif  // RAW_CODE_COMMON_HPP_
