#pragma once

#include "lorentz-opts.hpp"

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.

   THIS FILE 
*/
namespace lorentz
{
    struct Window;
    struct Clock;

    /*
     * @brief:  The platform class is the upper manager of the program, this
     *          is the first object the program initialize and is a global
     *          variable for the entire program.
     */
    struct Platform {
        Window *window;
        Clock *clock;
    };

    /*
     * @brief:  This is the first function main.cpp executes, this initializes
     *          the platform including window management.
     * @return: void
     */
    void initialize();

    /*
     * @brief:  This is the main loop of the lorentz engine, this will update
     *          the platform and window loop, these will update the rest of the
     *          program.
     * @return: void
     */
    void render();

    /*
     * @brief:  If the window is closed then this function will be called and
     *          will free all the remaining states of platform and the window
     *          manager. Watch out the order of the functions matter.
     * @return: void
     */
    void destroy();

    /* Make platform a global variable */
    extern Platform platform;

}; // namespace lorentz
