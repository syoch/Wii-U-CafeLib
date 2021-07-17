#include <inttypes.h>

#include <cstddef>

extern "C" uint32_t rodata_end;
inline void* operator new(size_t size) {
  register uint8_t* ret;
  register uint8_t* tmp;

  tmp = *(uint8_t**)(0x20000000);
  ret = tmp;
  tmp += 4;
  *(uint8_t**)(0x20000000) = tmp;

  return (void*)ret;
}
inline void* operator new[](size_t size) { return operator new(size); }
inline void operator delete(void* ptr, size_t size) {}