// Copyright 2021 syoch. All rights reserved.

/**
 * @file common.h
 * @brief シンボル宣言などを行うためのヘッダファイル。
 * @author syoch
 * @details リンカスクリプトで定義されたシンボルをすべて適切な型で宣言します。
 */

#ifndef RAW_CODE_COMMON_HPP_
#define RAW_CODE_COMMON_HPP_

extern "C" {
//! プログラムで使うデータ開始地点を指すアドレス変数
uint32_t rodata_start;

//! プログラムで使うデータのサイズのアドレス変数
uint32_t rodata_size;

//! プログラムで使うデータ終点を指すアドレス変数
uint32_t rodata_end;

//! アロケーター内で使う内部変数
uint8_t* allocator_pointer;
};

#endif  // RAW_CODE_COMMON_HPP_
