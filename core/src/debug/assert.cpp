#include "core/debug/assert.h"

#include <cstdlib>

#include "core/debug/terminal.h"

namespace caverneer::detail {

[[noreturn]]
void assert(const char* expr, const char* file, uint64_t line)
{
    debugPrint("[ASSERT] %s:%lu \"%s\"", file, line, expr);
    abort();
}

} // namespace caverneer::detail
