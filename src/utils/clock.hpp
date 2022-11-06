#pragma once

#include "utils/utils.hpp"
#include <chrono>

namespace lorentz
{
    struct Clock {
        using steady_clock = std::chrono::steady_clock;
        using milliseconds = std::chrono::milliseconds;
        using seconds = std::chrono::seconds;

        Clock();

        /*
         * @brief: Start time, when clock is initialized.
         */
        steady_clock::time_point start;

        /*
         * @brief:  Timer measures time elapsed since Clock has been
         *          initialized.
         * @return: The time between the initialization of the Clock manager
         *          and the call of this function.
         */
        u64 getTime();
    };

}; // namespace lorentz
