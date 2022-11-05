#pragma once

/* clang-format off */
/* Copyright (C) 2022 René Huiberts - All Rights Reserved
   This is a user file which you can use to fully configured the project
   and its modules. If you do not define an option, a default value will
   be used. Keep in mind that some options are given through the compiler. */ 

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
