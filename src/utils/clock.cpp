#include "utils/clock.hpp"

namespace lorentz
{
    Clock::Clock()
    {
        this->start = steady_clock::now();
    }

#define CLK_SWITCH_METRIC 1000000

    u64 Clock::getTime()
    {
        auto time =
            duration_cast<milliseconds>(steady_clock::now() - start).count();

        if (time < CLK_SWITCH_METRIC)
            return (u64)time;

        time = duration_cast<seconds>(steady_clock::now() - start).count();

        return (u64)time;
    }

}; // namespace lorentz
