// Copyright 2021 syoch. All rights reserved.

/**
 * @file rawFunc.hpp
 * @brief 関数ポインタ系のヘッダファイル
 * @author syoch
 * @details 関数ポインタの代理を定義したファイルです
 */

#pragma once

#include <inttypes.h>

namespace code {
/**
 * @brief 関数ポインタラッパー
 * @details
 * 関数ポインタラッパーは、関数ポインタをラップすることでソースコードの可視性を高めます
 */
template <typename ret, uint32_t addr, typename... Args>
class rawFunc {
 public:
  /**
   * @brief ラップされてる関数ポインタを呼び出す関数です
   * @param[in] args 引数リストです（可変長）
   * @return ret 関数ポインタからの戻り値です
   */
  inline constexpr ret operator()(Args... args) {
    return ((ret(*)(Args...))(addr))(args...);
  }
};

}  // namespace code
