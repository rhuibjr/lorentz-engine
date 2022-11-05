#include "utils/clock.hpp"

namespace lorentz
{
    Clock::Clock() { this->start = steady_clock::now(); }

#define CLK_SWITCH_METRIC 1000000

    Clock::seconds Clock::getTime()
    {
        return (seconds)duration_cast<seconds>(steady_clock::now() - start).count();
    }

}; // namespace lorentz
