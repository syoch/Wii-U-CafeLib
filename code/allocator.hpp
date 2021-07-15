#include <inttypes.h>

#include <cstddef>

extern "C" uint32_t rodata_end;
inline void* operator new(size_t size) {
  static char* ptr = (char*)&rodata_end;
  auto ret = ptr;
  ptr += size;
  return ret;
}
inline void* operator new[](size_t size) { return operator new(size); }
inline void operator delete(void* ptr, size_t size) {}