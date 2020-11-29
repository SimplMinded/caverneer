#pragma once

#include <cstdint>

namespace caverneer {

struct Point;
struct Vector;

union Matrix
{
    float elems[16];
    struct
    {
        float e11, e21, e31, e41;
        float e12, e22, e32, e42;
        float e13, e23, e33, e43;
        float e14, e24, e34, e44;
    };

    float& at(uint32_t row, uint32_t column);
    float at(uint32_t row, uint32_t column) const;
};

const Matrix MATRIX_IDENTITY = Matrix{{ 1, 0, 0, 0,
                                        0, 1, 0, 0,
                                        0, 0, 1, 0,
                                        0, 0, 0, 1 }};

Matrix makeMatrix(float e11, float e12, float e13, float e14,
                  float e21, float e22, float e23, float e24,
                  float e31, float e32, float e33, float e34,
                  float e41, float e42, float e43, float e44);
Matrix makeMatrix();

Matrix transpose(const Matrix& matrix);

bool operator ==(const Matrix& lhs, const Matrix& rhs);
bool operator !=(const Matrix& lhs, const Matrix& rhs);

Matrix operator -(const Matrix& matrix);

Matrix operator +(const Matrix& lhs, const Matrix& rhs);

Matrix operator -(const Matrix& lhs, const Matrix& rhs);

Matrix operator *(const Matrix& lhs, const Matrix& rhs);
Matrix operator *(const Matrix& lhs, float rhs);
Matrix operator *(float lhs, const Matrix& rhs);

Point operator *(const Matrix& lhs, const Point& rhs);
Vector operator *(const Matrix& lhs, const Vector& rhs);

Matrix operator /(const Matrix& lhs, float rhs);

} // namespace caverneer
