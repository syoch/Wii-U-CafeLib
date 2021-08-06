// Copyright 2021 syoch. All rights reserved.

/**
 * @file allocator.hpp
 * @brief アロケータが定義されてます。
 * @author syoch
 * @details
 *   簡単なアロケーターとoperator new, operator new[],
 *   operator deleteを定義します。
 */

#pragma once

#include <inttypes.h>

#include <cstddef>
#include <type_traits>
#include <vector>

#include "common.hpp"

namespace code {
/**
 * @brief メモリを確保する関数
 * @param[in] size アロケーターが確保するバイト単位でのサイズ
 * @return void* アロケーターが確保したメモリのアドレス
 * @details
 * アロケーターが確保したメモリのアドレス(allocator_pointer)を返します。
 * @example example_allocator.cpp
 */
inline void* allocate(std::size_t size) {
  auto ptr = allocator_pointer;
  allocator_pointer += size;
  return ptr;
}

}  // namespace code

/**
 * @brief アロケーターへのラップ関数
 * @param[in] size アロケーターが確保するバイト単位でのサイズ
 * @return void* アロケーターが確保したメモリのアドレス
 * @example example_operator_new.cpp
 */
inline void* operator new(size_t size) { return code::allocate(size); }

/**
 * @brief アロケーターへの配列版ラップ関数
 * @param[in] size アロケーターが確保するバイト単位でのサイズ
 * @return void* アロケーターが確保したメモリのアドレス
 * @example example_operator_new_array.cpp
 */
inline void* operator new[](size_t size) { return operator new(size); }

/**
 * @brief メモリ解放関数（未実装）
 * @param[in] ptr 開放するメモリへのポインタ
 * @return void
 */
inline void operator delete(void* ptr) {}
