#pragma once

#include "lorentz-opts.hpp"

extern "C" {
#include "glad/glad.h"
}

#if SYS_DARWIN
#define GL_SILENCE_DEPRECATION
#endif

#include "GLFW/glfw3.h"
