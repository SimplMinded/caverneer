#include "core/math/point.h"

#include "core/debug/assert.h"
#include "core/math/vector.h"
#include "core/util/unreachable.h"

namespace caverneer {

float& Point::operator [](size_t index)
{
    switch (index)
    {
        case 0: return x;
        case 1: return y;
        default: UNREACHABLE("Unexpected index: %lu", index);
    }
}

float Point::operator [](size_t index) const
{
    switch (index)
    {
        case 0: return x;
        case 1: return y;
        default: UNREACHABLE("Unexpected index: %lu", index);
    }

}

Point makePoint(float x, float y)
{
    return Point{ x, y };
}

Point makePoint()
{
    return makePoint(0.0f, 0.0f);
}

bool operator ==(const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool operator !=(const Point& lhs, const Point& rhs)
{
    return !(lhs == rhs);
}

Point operator -(const Point& point)
{
    return Point{ -point.x, -point.y };
}

Point operator +(const Point& lhs, const Vector& rhs)
{
    return Point{ lhs.x + rhs.x, lhs.y + rhs.y };
}

Point operator +(const Vector& lhs, const Point& rhs)
{
    return rhs + lhs;
}

Vector operator -(const Point& lhs, const Point& rhs)
{
    return Vector{ lhs.x - rhs.x, lhs.y - rhs.y };
}

Point operator -(const Point& lhs, const Vector& rhs)
{
    return Point{ lhs.x - rhs.x, lhs.y - rhs.y };
}

Point operator *(const Point& lhs, float rhs)
{
    return Point{ lhs.x * rhs, lhs.y * rhs };
}

Point operator *(float lhs, const Point& rhs)
{
    return rhs * lhs;
}

Point operator /(const Point& lhs, float rhs)
{
    ASSERT(rhs != 0.0f);

    return Point{ lhs.x / rhs, lhs.y / rhs };
}

} // namespace caverneer
