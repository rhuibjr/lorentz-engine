#pragma once

/* clang-format off */
/* Copyright (C) 2022 René Huiberts - All Rights Reserved
   Debug utility used throughout the lorentz engine. */

#if NDEBUG
#define ASSERT(expression)
#else
#define ASSERT(expression)                                                          \
    do {                                                                            \
        if (!(expression)) {                                                        \
            log(ERROR, TAG_ASSERT, "/ " #expression " / \n ");                      \
            __builtin_trap();                                                       \
        }                                                                           \
    } while (0)
#endif

/* CODE WORKAROUND
   A macro that is used to indicate that a piece of code is temporary.*/
#if !NDEBUG
#define CODE_WORKAROUND(info)                                                        \
    _Pragma ("GCC warning \"This is a workaround and needs to be changed.\"")
#else
#define CODE_WORKAROUND(info)                                                        \
    _Pragma ("GCC error   \"This is non production-ready code, and should be changed.\"")
#endif

/* CODE TODO 
   A macro that is used to indicate that a functionality has yet to be implemented.*/
#define CODE_TODO(info)                                                              \
    _Pragma ("GCC warning \"TODO Implement new functionality.\"")

/* clang-format on */
