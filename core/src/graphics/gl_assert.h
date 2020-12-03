#pragma once

#include <cstdint>

namespace caverneer {

namespace detail {

void flushGlErrors();

void glAssert(const char* file, uint64_t line, const char* statement);

} // namespace detail

#define GL_ASSERT(statement) \
    detail::flushGlErrors(); \
    statement; \
    detail::glAssert(__FILE__, __LINE__, #statement)

} // namespace caverneer
