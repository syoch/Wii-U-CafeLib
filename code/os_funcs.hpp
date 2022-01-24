// Copyright 2021 syoch. All rights reserved.

/**
 * @file code.h
 * @brief OS関数の定義
 * @author syoch
 * @details coreinit.rplにある関数の一部を定義したファイルです。
 */

#pragma once

#include "rawFunc.hpp"

namespace code {
namespace OSFuncs {
FreeRawFunc<void, 0x0102A3B4> OSDynLoad_Acquire;
FreeRawFunc<void, 0x0102B828> OSDynLoad_FindExport;

}  // namespace OSFuncs
}  // namespace code
