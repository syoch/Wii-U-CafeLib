#pragma once
using uint32_t = unsigned int;

template <typename ret, uint32_t addr, typename... Args>
class rawFunc {
 public:
  inline ret operator()(Args... args) {
    return ((ret(*)(Args...))(addr))(args...);
  }
};