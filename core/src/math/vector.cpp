#include "core/math/vector.h"

#include <cmath>

#include "core/debug/assert.h"
#include "core/util/unreachable.h"

namespace caverneer {

float& Vector::operator [](size_t index)
{
    switch (index)
    {
        case 0: return x;
        case 1: return y;
        default: UNREACHABLE("unexpected index: %lu", index);
    }
}

float Vector::operator [](size_t index) const
{
    switch (index)
    {
        case 0: return x;
        case 1: return y;
        default: UNREACHABLE("unexpected index: %lu", index);
    }
}

Vector makeVector(float x, float y)
{
    return Vector{ x, y };
}

Vector makeVector()
{
    return makeVector(0.0f, 0.0f);
}

float lengthSquared(const Vector& vector)
{
    return (vector.x * vector.x) + (vector.y * vector.y);
}

float length(const Vector& vector)
{
    return sqrtf(lengthSquared(vector));
}

Vector normalize(const Vector& vector)
{
    return vector / length(vector);
}

float dot(const Vector& lhs, const Vector& rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

bool operator ==(const Vector& lhs, const Vector& rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool operator !=(const Vector& lhs, const Vector& rhs)
{
    return !(lhs == rhs);
}

Vector operator -(const Vector& vector)
{
    return Vector{ -vector.x, -vector.y };
}

Vector operator +(const Vector& lhs, const Vector& rhs)
{
    return Vector{ lhs.x + rhs.x, lhs.y + rhs.y };
}

Vector operator -(const Vector& lhs, const Vector& rhs)
{
    return Vector{ lhs.x - rhs.x, lhs.y - rhs.y };
}

Vector operator *(const Vector& lhs, float rhs)
{
    return Vector{ lhs.x * rhs, lhs.y * rhs };
}

Vector operator *(float lhs, const Vector& rhs)
{
    return rhs * lhs;
}

Vector operator /(const Vector& lhs, float rhs)
{
    ASSERT(rhs != 0.0f);

    return Vector{ lhs.x / rhs, lhs.y / rhs };
}

} // namespace caverneer
