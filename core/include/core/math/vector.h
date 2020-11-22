#pragma once

#include <cstddef>

namespace caverneer {

struct Vector
{
    float x;
    float y;

    float& operator [](size_t index);
    float operator [](size_t index) const;
};

const Vector VECTOR_ZERO = Vector{ 0, 0 };
const Vector VECTOR_X_AXIS = Vector{ 1, 0 };
const Vector VECTOR_Y_AXIS = Vector{ 0, 1 };

Vector makeVector(float x, float y);
Vector makeVector();

float lengthSquared(const Vector& vector);
float length(const Vector& vector);

Vector normalize(const Vector& vector);

float dot(const Vector& lhs, const Vector& rhs);

bool operator ==(const Vector& lhs, const Vector& rhs);
bool operator !=(const Vector& lhs, const Vector& rhs);

Vector operator -(const Vector& vector);

Vector operator +(const Vector& lhs, const Vector& rhs);

Vector operator -(const Vector& lhs, const Vector& rhs);

Vector operator *(const Vector& lhs, float rhs);
Vector operator *(float lhs, const Vector& rhs);

Vector operator /(const Vector& lhs, float rhs);

} // namespace caverneer
