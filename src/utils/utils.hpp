#pragma once

#include <cstdarg>
#include <cstdint>
#include <iostream>

#include "utils/messagemonitor.hpp"

#define internal static
#define local_persist static
#define global_variable static

#define UNUSED __attribute__((unused))
#define PACKED __attribute__((packed))

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;
