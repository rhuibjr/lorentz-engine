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

#define LORENTZ_ON  1
#define LORENTZ_OFF 0

#ifndef NDEBUG
#define NDEBUG               LORENTZ_OFF
#endif

#ifndef SYS_DARWIN
#define SYS_DARWIN           LORENTZ_OFF
#endif

#ifndef SYS_LINUX
#define SYS_LINUX            LORENTZ_OFF
#endif

#ifndef BEAR
#define BEAR                 LORENTZ_OFF
#endif

#define MESSAGE_MONITOR_LOG  LORENTZ_ON

/* clang-format on */
