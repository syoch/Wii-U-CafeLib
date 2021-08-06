// Copyright 2021 syoch. All rights reserved.

/**
 * @file memcpy.hpp
 * @brief memcpyを定義したファイルです
 * @author syoch
 * @details memcpyをアセンブラが最短になるように実装したファイルです。
 */

#pragma once

#include <cstddef>
namespace code {
/**
 * @brief memcpyです
 * @param[in] src 入力元のポインタ
 * @param[out] dest 出力先のポインタ
 * @param[in] size 処理するサイズ
 * @return void
 * @details メモリをT型のサイズでコピーします。
 * @example example_memcpy.cpp
 */
template <typename T>
inline void memcpy(T* src, T* dest, const size_t count) {
  src--;
  dest--;
  for (register size_t i = count; i != 0; --i) {
    *(++dest) = *(++src);
  }
}
}  // namespace code
