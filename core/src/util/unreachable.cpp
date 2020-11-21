#include "core/util/unreachable.h"

#include <cstdarg>
#include <cstdlib>
#include <cstdio>

#include "core/debug/terminal.h"

namespace caverneer::detail {

constexpr size_t unreachableMsgMaxLength = 128;

[[noreturn]]
void unreachable(const char* file, uint64_t line, const char* msg, ...)
{
    std::va_list args;
    va_start(args, msg);

    char buffer[unreachableMsgMaxLength];
    vsnprintf(buffer, unreachableMsgMaxLength, msg, args);

    va_end(args);

    debugPrint("[UNREACHABLE] %s:%lu \"%s\"", file, line, buffer);
    abort();
}

} // namespace caverneer::detail
