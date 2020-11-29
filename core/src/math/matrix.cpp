#include "core/math/matrix.h"

#include "core/debug/assert.h"
#include "core/math/point.h"
#include "core/math/vector.h"

namespace caverneer {

float& Matrix::at(uint32_t row, uint32_t column)
{
    ASSERT(row != 0);
    ASSERT(row <= 4);
    ASSERT(column != 0);
    ASSERT(column <= 4);

    return elems[(row - 1) + ((column - 1) * 4)];
}

float Matrix::at(uint32_t row, uint32_t column) const
{
    ASSERT(row != 0);
    ASSERT(row <= 4);
    ASSERT(column != 0);
    ASSERT(column <= 4);

    return elems[(row - 1) + ((column - 1) * 4)];
}

Matrix makeMatrix(float e11, float e12, float e13, float e14,
                  float e21, float e22, float e23, float e24,
                  float e31, float e32, float e33, float e34,
                  float e41, float e42, float e43, float e44)
{
    return Matrix{{ e11, e21, e31, e41,
                    e12, e22, e32, e42,
                    e13, e23, e33, e43,
                    e14, e24, e34, e44 }};
}

Matrix makeMatrix()
{
    return Matrix{{ 0, 0, 0, 0,
                    0, 0, 0, 0,
                    0, 0, 0, 0,
                    0, 0, 0, 0 }};
}

Matrix transpose(const Matrix& matrix)
{
    Matrix result;
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    {
        result.at(r, c) = matrix.at(c, r);
    }

    return result;
}

bool operator ==(const Matrix& lhs, const Matrix& rhs)
{
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    {
        if (lhs.at(r, c) != rhs.at(r, c))
        {
            return false;
        }
    }

    return true;
}

bool operator !=(const Matrix& lhs, const Matrix& rhs)
{
    return !(lhs == rhs);
}

Matrix operator -(const Matrix& matrix)
{
    Matrix result;
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    {
        result.at(r, c) = -matrix.at(r, c);
    }

    return result;
}

Matrix operator +(const Matrix& lhs, const Matrix& rhs)
{
    Matrix result;
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    {
        result.at(r, c) = lhs.at(r, c) + rhs.at(r, c);
    }

    return result;
}

Matrix operator -(const Matrix& lhs, const Matrix& rhs)
{
    Matrix result;
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    {
        result.at(r, c) = lhs.at(r, c) - rhs.at(r, c);
    }

    return result;
}

Matrix operator *(const Matrix& lhs, const Matrix& rhs)
{
    Matrix result = makeMatrix();
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    for (uint32_t i = 1; i <= 4; i++)
    {
        result.at(r, c) += lhs.at(r, i) * rhs.at(i, c);
    }

    return result;
}

Matrix operator *(const Matrix& lhs, float rhs)
{
    Matrix result;
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    {
        result.at(r, c) = lhs.at(r, c) * rhs;
    }

    return result;
}

Matrix operator *(float lhs, const Matrix& rhs)
{
    return rhs * lhs;
}

Point operator *(const Matrix& lhs, const Point& rhs)
{
    return makePoint(
        (lhs.e11 * rhs.x) + (lhs.e12 * rhs.y) + lhs.e14,
        (lhs.e21 * rhs.x) + (lhs.e22 * rhs.y) + lhs.e24);
}

Vector operator *(const Matrix& lhs, const Vector& rhs)
{
    return makeVector(
        (lhs.e11 * rhs.x) + (lhs.e12 * rhs.y),
        (lhs.e21 * rhs.x) + (lhs.e22 * rhs.y));
}

Matrix operator /(const Matrix& lhs, float rhs)
{
    Matrix result;
    for (uint32_t c = 1; c <= 4; c++)
    for (uint32_t r = 1; r <= 4; r++)
    {
        result.at(r, c) = lhs.at(r, c) / rhs;
    }

    return result;
}

} // namespace caverneer
