#pragma once

#include <iostream>
#include <cstdint>

#define internal static
#define local_persist static
#define global_variable static

#define UNUSED __attribute__((unused))

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

#define _LORENTZ_LOG_PREFIX  "[DEBUG] "
#define _LORENTZ_LOG_POSTFIX "\n"

#define LORENTZ_COLOUR(value) value / 255.0f
#define LORENTZ_CLEAR_COLOUR                    \
    LORENTZ_COLOUR(242), LORENTZ_COLOUR(242), LORENTZ_COLOUR(242), 1.0f

#define LORENTZ_LOG(msg)                        \
    std::cerr << _LORENTZ_LOG_PREFIX << msg << _LORENTZ_LOG_POSTFIX

#define LORENTZ_EXIT_ON_ERROR(msg)              \
    do { LORENTZ_LOG(msg);                      \
         exit(0); } while(0)

