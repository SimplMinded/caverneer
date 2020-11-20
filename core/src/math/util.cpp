#include "core/math/util.h"

namespace caverneer {

template<typename T>
static T min_impl(T lhs, T rhs)
{
    return ((lhs <= rhs) * lhs) + ((lhs > rhs) * rhs);
}

int8_t min(int8_t lhs, int8_t rhs)
{
    return min_impl(lhs, rhs);
}

int16_t min(int16_t lhs, int16_t rhs)
{
    return min_impl(lhs, rhs);
}

int32_t min(int32_t lhs, int32_t rhs)
{
    return min_impl(lhs, rhs);
}

int64_t min(int64_t lhs, int64_t rhs)
{
    return min_impl(lhs, rhs);
}

uint8_t min(uint8_t lhs, uint8_t rhs)
{
    return min_impl(lhs, rhs);
}

uint16_t min(uint16_t lhs, uint16_t rhs)
{
    return min_impl(lhs, rhs);
}

uint32_t min(uint32_t lhs, uint32_t rhs)
{
    return min_impl(lhs, rhs);
}

uint64_t min(uint64_t lhs, uint64_t rhs)
{
    return min_impl(lhs, rhs);
}

float min(float lhs, float rhs)
{
    return min_impl(lhs, rhs);
}

double min(double lhs, double rhs)
{
    return min_impl(lhs, rhs);
}


template<typename T>
static T max_impl(T lhs, T rhs)
{
    return ((lhs > rhs) * lhs) + ((lhs <= rhs) * rhs);
}

int8_t max(int8_t lhs, int8_t rhs)
{
    return max_impl(lhs, rhs);
}

int16_t max(int16_t lhs, int16_t rhs)
{
    return max_impl(lhs, rhs);
}

int32_t max(int32_t lhs, int32_t rhs)
{
    return max_impl(lhs, rhs);
}

int64_t max(int64_t lhs, int64_t rhs)
{
    return max_impl(lhs, rhs);
}

uint8_t max(uint8_t lhs, uint8_t rhs)
{
    return max_impl(lhs, rhs);
}

uint16_t max(uint16_t lhs, uint16_t rhs)
{
    return max_impl(lhs, rhs);
}

uint32_t max(uint32_t lhs, uint32_t rhs)
{
    return max_impl(lhs, rhs);
}

uint64_t max(uint64_t lhs, uint64_t rhs)
{
    return max_impl(lhs, rhs);
}

float max(float lhs, float rhs)
{
    return max_impl(lhs, rhs);
}

double max(double lhs, double rhs)
{
    return max_impl(lhs, rhs);
}

} // namespace caverneer
