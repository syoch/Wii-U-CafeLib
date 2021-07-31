#pragma once
#include <inttypes.h>

#include <cstddef>

extern "C" uint32_t rodata_end;
struct {
  uint8_t* allocator_ptr = nullptr;
  void* operator()(size_t size) {
    register uint8_t* ret = (uint8_t*)allocator_ptr;
    allocator_ptr += 4;
    return (void*)ret;
  }
} get_allocator_pointer;

inline void* operator new(size_t size) {
  return (void*)((int)&rodata_end + (int)get_allocator_pointer(size));
}
inline void* operator new[](size_t size) { return operator new(size); }
inline void operator delete(void* ptr, size_t size) {}