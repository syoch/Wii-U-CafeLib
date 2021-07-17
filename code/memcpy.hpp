#include <inttypes.h>

#include <cstddef>

template <typename T>
inline void memcpy(T* src, T* dest, size_t count) {
  for (register size_t i = count; i != 0; --i) {
    *(++dest) = *(++src);
  }
}