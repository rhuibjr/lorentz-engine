#include "utils/clock.hpp"
#include "utils/utils.hpp"

#include "lorentz.hpp"

namespace lorentz {

const char* table_type_message[] = { "ERROR", "WARNING", "INFO" };

const char* table_tag_message[] = {
    [TAG_NONE] = "",
    [TAG_ASSERT] = "Assertion failed",
    [TAG_PLATFORM] = "Platform",
    [TAG_WINDOW] = "Window"
};

#define MESSAGE_MONITOR_MESSAGE_SIZE 1024
#define MESSAGE_MONITOR_DEBUG 1

void MessageMonitor::log(
    table_type debug_flags, table_tag index, const char* __restrict format,
    ...)
{
#if MESSAGE_MONITOR_DEBUG
    va_list args_list;
    char message[MESSAGE_MONITOR_MESSAGE_SIZE];

    va_start(args_list, format);
    vsnprintf(message, MESSAGE_MONITOR_MESSAGE_SIZE, format, args_list);
    va_end(args_list);

    printf(
        "[%lu][DEBUG] (%s) %s\n", platform.clock->get_time(),
        table_type_message[debug_flags], table_tag_message[index], message);
#endif
}

}; // namespace lorentz
