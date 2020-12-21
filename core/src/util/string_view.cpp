#include "core/util/string_view.h"

#include <cstring>

#include "core/debug/assert.h"

namespace caverneer {

StringView::StringView(const char* ptr, size_t length)
    : ptr(ptr), length(length)
{
    ASSERT(ptr != nullptr);
    ASSERT(length != 0);
}

StringView::StringView(const char* ptr)
    : ptr(ptr), length(strlen(ptr))
{
    ASSERT(ptr != nullptr);
}

StringView::StringView()
    : ptr(nullptr), length(0)
{

}

char StringView::operator [](size_t index) const
{
    ASSERT(index < length);
    ASSERT(ptr != nullptr);

    return ptr[index];
}

bool operator ==(const StringView& lhs, const StringView& rhs)
{
    if (lhs.length != rhs.length) return false;

    for (size_t i = 0; i < lhs.length; i++)
    {
        if (lhs[i] != rhs[i]) return false;
    }

    return true;
}

bool operator !=(const StringView& lhs, const StringView& rhs)
{
    return !(lhs == rhs);
}

bool operator ==(const StringView& lhs, const char* rhs)
{
    return lhs == StringView(rhs);
}

bool operator !=(const StringView& lhs, const char* rhs)
{
    return !(lhs == rhs);
}

bool operator ==(const char* lhs, const StringView& rhs)
{
    return rhs == lhs;
}

bool operator !=(const char* lhs, const StringView& rhs)
{
    return rhs != lhs;
}

size_t indexOf(const StringView& stringView, char character)
{
    ASSERT(stringView.ptr != nullptr);

    for (size_t i = 0; i < stringView.length; i++)
    {
        if (stringView[i] == character) return i;
    }

    return stringView.length;
}

size_t lastIndexOf(const StringView& stringView, char character)
{
    ASSERT(stringView.ptr != nullptr);

    for (size_t i = stringView.length - 1; i < stringView.length; i--)
    {
        if (stringView[i] == character) return i;
    }

    return stringView.length;
}

StringView substring(const StringView& stringView,
                     size_t beginIndex,
                     size_t endIndex)
{
    ASSERT(stringView.ptr != nullptr);
    ASSERT(beginIndex < endIndex && endIndex <= stringView.length);

    return StringView(stringView.ptr + beginIndex, endIndex - beginIndex);
}

} // namespace caverneer
