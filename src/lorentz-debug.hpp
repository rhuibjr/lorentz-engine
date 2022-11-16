#pragma once

/* clang-format off */
/* The Lorentz engine, is an open-ended graphics engine used for educational purposes.
   Copyright (C) 2022  rhuibertsjr 

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */

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
