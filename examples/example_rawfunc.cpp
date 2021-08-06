// Copyright 2021 syoch. All rights reserved.
#include "code/code.hpp"

inline void code_main() {
  // 使いまわしたいときは一時オブジェクトを作成します。
  code::rawFunc<int, 0x02000000, int> func;
  int ret = func(0);

  // このように一時オブジェクトを作成しなくても実行できます。
  ret = code::rawFunc<int, 0x02010000, int>{}(0);
}
