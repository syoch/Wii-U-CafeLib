// Copyright 2021 syoch. All rights reserved.

/**
 * @file mem.h
 * @brief メモリライブラリ
 * @author syoch
 * @details メモリにより容易にアクセスするためのライブラリです。
 */

#pragma once

#include <cinttypes>
namespace code {

/**
 * @brief メモリラッパー
 * @details メモリにより容易にアクセスするためのラッパーです。
 * @note 構造体と一緒に使うともっといい感じにアクセスできたりします。
 * @example example_mem.cpp
 */
class Mem {
 private:
  //! アドレス
  uint32_t base;

 public:
  /**
   * @brief アドレスを指定して初期化するコンストラクタです。
   */
  explicit Mem(uint32_t addr) { base = addr; }
  /**
   * @brief メモリを１段階掘り下げる関数
   * @param[in] offset オフセットです。
   * @return Mem 掘り下げられたメモリへの参照です。
   */
  Mem operator[](size_t offset) {
    return Mem(*reinterpret_cast<uint8_t*>(base) + offset);
  }
  /**
   * @brief メモリの値を取得する関数です
   * @return T& 値を取得したメモリへの参照です。
   */
  template <typename T>
  T& as() {
    return *reinterpret_cast<T*>(base);
  }
};

}  // namespace code
