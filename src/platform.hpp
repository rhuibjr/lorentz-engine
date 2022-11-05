#pragma once

#include "lorentz-opts.hpp"

#define LORENTZ_COLOUR(value) value / 255.0f
#define LORENTZ_CLEAR_COLOUR                                                   \
    LORENTZ_COLOUR(242), LORENTZ_COLOUR(242), LORENTZ_COLOUR(242), 1.0f

// TODO Change location to an platform header
#if NDEBUG
#define ASSERT(expression)
#else
#define ASSERT(expression)                                                     \
    do {                                                                       \
        if (!(expression)) {                                                   \
            log(ERROR, TAG_ASSERT, "/ " #expression " / \n ");                 \
            __builtin_trap();                                                  \
        }                                                                      \
    } while (0)
#endif
