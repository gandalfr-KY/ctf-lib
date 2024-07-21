#pragma once

#include <cstdint>

namespace gandalfr_ctf {

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

constexpr i8 i8MAX = INT8_MAX;
constexpr i16 i16MAX = INT16_MAX;
constexpr i32 i32MAX = INT32_MAX;
constexpr i64 i64MAX = INT64_MAX;

constexpr i8 i8MIN = INT8_MIN;
constexpr i16 i16MIN = INT16_MIN;
constexpr i32 i32MIN = INT32_MIN;
constexpr i64 i64MIN = INT64_MIN;

constexpr u8 u8MAX = UINT8_MAX;
constexpr u16 u16MAX = UINT16_MAX;
constexpr u32 u32MAX = UINT32_MAX;
constexpr u64 u64MAX = UINT64_MAX;

const i32 INF = 1001001001;
const i64 INFLL = 1001001001001001001;

} // namespace gandalfr_ctf
