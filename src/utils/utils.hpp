#pragma once

#include <array>
#include <cstdarg>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "utils/messagemonitor.hpp"

#define internal        static
#define local_persist   static
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

#define LORENTZ_COLOUR(value) value / 255.0f
#define LORENTZ_CLEAR_COLOUR                                                   \
    LORENTZ_COLOUR(242), LORENTZ_COLOUR(242), LORENTZ_COLOUR(242), 1.0f
