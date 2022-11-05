#pragma once

#include "utils/utils.hpp"
#include <chrono>

namespace lorentz {

// TODO(rene) Optimize
struct Clock {
    using steady_clock = std::chrono::steady_clock;
    using milliseconds = std::chrono::milliseconds;
    using seconds = std::chrono::seconds;

    steady_clock::time_point start;

    Clock() { this->start = steady_clock::now(); }

#define CLK_SWITCH_METRIC 1000000

    auto get_time()
    {
        steady_clock::time_point end = steady_clock::now();

        auto time = duration_cast<milliseconds>(end - start).count();
        if (time < CLK_SWITCH_METRIC)
            return time;

        return duration_cast<seconds>(end - start).count();
    }
};

}; // namespace lorentz
