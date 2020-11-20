#include "core/debug/terminal.h"

#include <cstdarg>
#include <cstdint>
#include <cstdio>

#include "core/math/util.h"

namespace caverneer {

constexpr int32_t debugPrintMaxLineLength = 256;

void debugPrint(const char* msg, ...)
{
    std::va_list args;
    va_start(args, msg);

    char buffer[debugPrintMaxLineLength];
    const int32_t writtenBytes =
        vsnprintf(buffer, size_t(debugPrintMaxLineLength) - 1, msg, args);

    va_end(args);

    const int32_t endIndex = min(writtenBytes, debugPrintMaxLineLength - 1);
    buffer[endIndex] = '\n';

    printf("%s", buffer);
}

} // namespace caverneer
