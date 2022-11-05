#pragma once

namespace lorentz {
enum table_type {
    ERROR = 0x00,
    WARNING,
    INFO,
};

enum table_tag {
    TAG_NONE = 0x00,
    TAG_ASSERT,
    TAG_PLATFORM,
    TAG_WINDOW,
};

struct MessageMonitor {
    static void setup();

    static void
    log(table_type debug_flag, table_tag index, const char* __restrict format,
        ...);
};

constexpr auto log = &MessageMonitor::log;
}; // namespace lorentz
