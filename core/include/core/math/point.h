#pragma once

#include <cstddef>

namespace caverneer {

struct Vector;

struct Point
{
    float x;
    float y;

    float& operator [](size_t index);
    float operator [](size_t index) const;
};

const Point POINT_ZERO = Point{ 0, 0 };

Point makePoint(float x, float y);
Point makePoint();

bool operator ==(const Point& lhs, const Point& rhs);
bool operator !=(const Point& lhs, const Point& rhs);

Point operator -(const Point& point);

Point operator +(const Point& lhs, const Vector& rhs);
Point operator +(const Vector& lhs, const Point& rhs);

Vector operator -(const Point& lhs, const Point& rhs);
Point operator -(const Point& lhs, const Vector& rhs);

Point operator *(const Point& lhs, float rhs);
Point operator *(float lhs, const Point& rhs);

Point operator /(const Point& lhs, float rhs);

} // namespace caverneer
