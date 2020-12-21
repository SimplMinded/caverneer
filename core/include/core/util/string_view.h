#pragma once

#include <cstddef>

namespace caverneer {

struct StringView
{
    const char* ptr;
    size_t length;

    StringView(const char* ptr, size_t length);
    StringView(const char* ptr);
    StringView();

    char operator [](size_t index) const;
};

bool operator ==(const StringView& lhs, const StringView& rhs);
bool operator !=(const StringView& lhs, const StringView& rhs);

bool operator ==(const StringView& lhs, const char* rhs);
bool operator !=(const StringView& lhs, const char* rhs);

bool operator ==(const char* lhs, const StringView& rhs);
bool operator !=(const char* lhs, const StringView& rhs);

size_t indexOf(const StringView& stringView, char character);
size_t lastIndexOf(const StringView& stringView, char character);

StringView substring(const StringView& stringView,
                     size_t beginIndex,
                     size_t endIndex);

} // namespace caverneer
