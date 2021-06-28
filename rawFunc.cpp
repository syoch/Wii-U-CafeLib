#include <stdint.h>
template <typename ret, uint32_t addr>
class rawFunc
{
public:
  template <typename... Args>
  ret operator()(Args... args)
  {
    return ((ret(*)(Args...))(addr))(args...);
  }
};