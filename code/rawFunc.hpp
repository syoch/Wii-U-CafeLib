// Copyright 2021 syoch. All rights reserved.

#pragma once

#include <inttypes.h>

namespace code {
template <typename ret, uint32_t addr, typename... Args>
class rawFunc {
 public:
  inline constexpr ret operator()(Args... args) {
    return ((ret(*)(Args...))(addr))(args...);
  }
};

}  // namespace code
