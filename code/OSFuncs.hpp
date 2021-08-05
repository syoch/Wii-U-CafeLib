// Copyright 2021 syoch. All rights reserved.

#pragma once

#include "rawFunc.hpp"

namespace code {
namespace OSFuncs {
constexpr rawFunc<void, 0x0102A3B4, char*, unsigned int*> OSDynLoad_Acquire;
constexpr rawFunc<void, 0x0102B828, unsigned int, int, char*, void*>
    OSDynLoad_FindExport;

}  // namespace OSFuncs
}  // namespace code
