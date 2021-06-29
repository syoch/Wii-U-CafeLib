#include <stdint.h>

template <typename ret, uint32_t addr, typename... Args>
class rawFunc
{
public:
  ret operator()(Args... args)
  {
    return ((ret(*)(Args...))(addr))(args...);
  }
};

template <typename ret, uint32_t addr>
class rawFunc<ret, addr>
{
public:
  template <typename... Args>
  ret operator()(Args... args)
  {
    return ((ret(*)(Args...))(addr))(args...);
  }
};