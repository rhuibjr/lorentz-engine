#include "utils/clock.hpp"
#include "utils/utils.hpp"

#include "lorentz.hpp"

namespace lorentz
{
    const char *table_type_message[] = {"ERROR", "WARNING", "INFO"};

    /* Add string to the tag */
    const char *table_tag_message[] = {
        [TAG_NONE] = "",
        [TAG_ASSERT] = "Assertion failed",
        [TAG_PLATFORM] = "Platform",
        [TAG_WINDOW] = "Window",
        [TAG_SHADERS] = "Shader",
        [TAG_TEXTURE] = "Texture"};

#define MESSAGE_MONITOR_MESSAGE_SIZE 1024

    void MessageMonitor::log(
        table_type type, table_tag tag, const char *__restrict format, ...)
    {
#if MESSAGE_MONITOR_LOG
        va_list args_list;
        char message[MESSAGE_MONITOR_MESSAGE_SIZE];

        /* Allows the use of 'unlimited' paramters */
        va_start(args_list, format);
        vsnprintf(message, MESSAGE_MONITOR_MESSAGE_SIZE, format, args_list);
        va_end(args_list);

        printf(
            "[%llu][DEBUG][%s] (%s) %s\n", platform.clock->getTime(),
            table_type_message[type], table_tag_message[tag], message);
#endif
    }

}; // namespace lorentz
