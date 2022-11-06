#pragma once

namespace lorentz
{
    /*
     * @brief: Sincerity of the situation, the higher the better.
     */
    enum table_type {
        ERROR = 0x00,
        WARNING,
        INFO,
    };

    /*
     * @brief: Location of the caller / Grouping of messages.
     */
    enum table_tag {
        TAG_NONE = 0x00,
        TAG_ASSERT,
        TAG_PLATFORM,
        TAG_WINDOW,
        TAG_SHADERS,
        TAG_TEXTURE
    };

    /*
     * @brief:  MessageMonitor is a manger which handles the output stream
     *          of the project. This is a pure static class, which is globally
     *          accesable.
     */
    struct MessageMonitor {
        /*
         * @brief:  Prints an format to the output stream (stdout). It includes
         * a time, type and a place with the format.
         * @params: - type[in]: Sincerity of the situation.
         *          - tag[in]: Location of the caller / Grouping of messages.
         *          - format[in]: Output message
         *          - arguments[in]: Arguments for the output format.
         * @return: (void)
         */
        static void
        log(table_type type, table_tag tag, const char *__restrict format, ...);
    };

    /* @brief: Global logging */
    constexpr auto log = &MessageMonitor::log;

}; // namespace lorentz
