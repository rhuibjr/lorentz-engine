#pragma once

#include "graphics/window.hpp"

/* Copyright (C) 2022 René Huiberts - All Rights Reserved
   You may NOT modify, copy, republish, upload, post, transmit, or distribute,
   in any manner, the material in this project including text, graphics, code
   and/or software. You must retain all copyright and other proprietary    
   notices contained in the original material on any copy you make of the     
   material. */
namespace lorentz
{
    using graphics::Window;

    /*
     * @brief:  The platform class is the upper manager of the program, this 
     *          is the first object the program initialize and is a global
     *          variable for the entire program. 
     */
    struct Platform
    {
        Window* window; 
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
};
