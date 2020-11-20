#pragma once

#include <cstdint>

namespace caverneer {

namespace detail {

[[noreturn]]
void assert(const char* expr, const char* file, uint64_t line);

} // namespace detail

#define ASSERT(expr) if (!(expr)) detail::assert(#expr, __FILE__, __LINE__)

} // namespace caverneer
