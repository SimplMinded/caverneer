#pragma once

#include <cstdint>

namespace caverneer {

namespace detail {

[[noreturn]]
void unreachable(const char* file, uint64_t line, const char* msg, ...);

} // namespace detail

#define UNREACHABLE(...) detail::unreachable(__FILE__, __LINE__, __VA_ARGS__)

} // namespace caverneer
