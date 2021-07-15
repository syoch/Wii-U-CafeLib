#include <inttypes.h>

template <typename ret, uint32_t addr, typename... Args>
class rawFunc {
 public:
  inline ret operator()(Args... args) {
    return ((ret(*)(Args...))(addr))(args...);
  }
};