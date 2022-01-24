// Copyright 2021 syoch. All rights reserved.

/**
 * @file startup.hpp
 * @brief このライブラリの中枢関数が実装されたファイルです
 * @author syoch
 * @details コード本体のエントリポイントがこのファイルです。
 * コード本体の処理はraw.cppのcode_main()で行います。
 */

#pragma once

#include <inttypes.h>

#include <cstddef>

#include "common.hpp"
#include "memcpy.hpp"

void code_main();

namespace code {
/**
 * @brief データをコピーする関数です
 * @return void
 * @details
 * pcと命令オフセットからデータポインタを計算してそこから適切なメモリへコピーします
 */
inline void copy_data() {
  //! データ本体が収容されているメモリへのポインタ
  register uint32_t* src;

  // get src
  asm volatile(
      "bl 4\n"
      "mflr %[src]\n"
      "addi %[src], %[src],  text_end - . + 4"
      : [src] "=r"(src)
      :
      : "lr");

  // copy src to dest
  memcpy(src, static_cast<uint32_t*>(&rodata_start),
         reinterpret_cast<size_t>(&rodata_size));
}
}  // namespace code

/**
 * @brief エントリポイントです
 * @return int 常に0です
 * @details 必要ならデータをコピーして、コード本体を実行します
 */
extern "C" __attribute__((section(".startup"))) int startup() {
#ifndef NO_DATA_COPY
  code::copy_data();
#endif

  asm volatile("_startup_main:");
  code_main();
  asm volatile("_startup_main_end:");
  return 0;
}
