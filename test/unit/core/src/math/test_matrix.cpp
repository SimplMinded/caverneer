#include <catch.hpp>
#include <core/math/matrix.h>

#include <iostream>

#include <core/math/point.h>
#include <core/math/vector.h>

using namespace caverneer;

namespace caverneer {

std::ostream& operator <<(std::ostream& os, const Matrix& matrix)
{
    os << "Matrix{ \n";
    for (uint32_t c = 0; c < 4; c++)
    {
        for (uint32_t r = 0; r < 4; r++)
        {
            os << " " << matrix.at(r, c) << ",";
        }
        os << "\n";
    }

    return os << "}";
}

} // namespace caverneer

SCENARIO("You can get matrix elements by row and column")
{
    GIVEN("A matrix")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);
        
        WHEN("Each coordinate is queried")
        {
            THEN("The results should be the given values")
            {
                CHECK(m.at(1, 1) == m.e11);
                CHECK(m.at(1, 1) == 1);

                CHECK(m.at(1, 2) == m.e12);
                CHECK(m.at(1, 2) == 2);

                CHECK(m.at(1, 3) == m.e13);
                CHECK(m.at(1, 3) == 3);

                CHECK(m.at(1, 4) == m.e14);
                CHECK(m.at(1, 4) == 4);

                CHECK(m.at(2, 1) == m.e21);
                CHECK(m.at(2, 1) == 5);

                CHECK(m.at(2, 2) == m.e22);
                CHECK(m.at(2, 2) == 6);
    
                CHECK(m.at(2, 3) == m.e23);
                CHECK(m.at(2, 3) == 7);

                CHECK(m.at(2, 4) == m.e24);
                CHECK(m.at(2, 4) == 8);

                CHECK(m.at(3, 1) == m.e31);
                CHECK(m.at(3, 1) == 9);

                CHECK(m.at(3, 2) == m.e32);
                CHECK(m.at(3, 2) == 10);

                CHECK(m.at(3, 3) == m.e33);
                CHECK(m.at(3, 3) == 11);

                CHECK(m.at(3, 4) == m.e34);
                CHECK(m.at(3, 4) == 12);

                CHECK(m.at(4, 1) == m.e41);
                CHECK(m.at(4, 1) == 13);

                CHECK(m.at(4, 2) == m.e42);
                CHECK(m.at(4, 2) == 14);

                CHECK(m.at(4, 3) == m.e43);
                CHECK(m.at(4, 3) == 15);

                CHECK(m.at(4, 4) == m.e44);
                CHECK(m.at(4, 4) == 16);
            }
        }
    }
}

SCENARIO("A matrix can be created using makeMatrix")
{
    GIVEN("The numbers 1 to 16")
    {
        WHEN("The numbers are passed to makeMatrix")
        {
            const Matrix m = makeMatrix( 1,  2,  3,  4,
                                         5,  6,  7,  8,
                                         9, 10, 11, 12,
                                         13, 14, 15, 16);

            THEN("The created matrix has the numbers of 1 to 16 stored")
            {
                CHECK(m.elems[0] == 1);
                CHECK(m.elems[1] == 5);
                CHECK(m.elems[2] == 9);
                CHECK(m.elems[3] == 13);
                CHECK(m.elems[4] == 2);
                CHECK(m.elems[5] == 6);
                CHECK(m.elems[6] == 10);
                CHECK(m.elems[7] == 14);
                CHECK(m.elems[8] == 3);
                CHECK(m.elems[9] == 7);
                CHECK(m.elems[10] == 11);
                CHECK(m.elems[11] == 15);
                CHECK(m.elems[12] == 4);
                CHECK(m.elems[13] == 8);
                CHECK(m.elems[14] == 12);
                CHECK(m.elems[15] == 16);
            }
        }
    }

    GIVEN("Absolutely nothing")
    {
        WHEN("A matrix is created using makeMatrix")
        {
            const Matrix m = makeMatrix();

            THEN("The created matrix has all 0's")
            {
                CHECK(m.elems[0] == 0);
                CHECK(m.elems[1] == 0);
                CHECK(m.elems[2] == 0);
                CHECK(m.elems[3] == 0);
                CHECK(m.elems[4] == 0);
                CHECK(m.elems[5] == 0);
                CHECK(m.elems[6] == 0);
                CHECK(m.elems[7] == 0);
                CHECK(m.elems[8] == 0);
                CHECK(m.elems[9] == 0);
                CHECK(m.elems[10] == 0);
                CHECK(m.elems[11] == 0);
                CHECK(m.elems[12] == 0);
                CHECK(m.elems[13] == 0);
                CHECK(m.elems[14] == 0);
                CHECK(m.elems[15] == 0);
            }
        }
    }
}

SCENARIO("A matrix can be transposed")
{
    GIVEN("A matrix")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);

        WHEN("The matrix is transposed")
        {
            const Matrix t = transpose(m);

            THEN("The original matrix is unchanged")
            {
                CHECK(m.e11 == 1);
                CHECK(m.e12 == 2);
                CHECK(m.e13 == 3);
                CHECK(m.e14 == 4);
                CHECK(m.e21 == 5);
                CHECK(m.e22 == 6);
                CHECK(m.e23 == 7);
                CHECK(m.e24 == 8);
                CHECK(m.e31 == 9);
                CHECK(m.e32 == 10);
                CHECK(m.e33 == 11);
                CHECK(m.e34 == 12);
                CHECK(m.e41 == 13);
                CHECK(m.e42 == 14);
                CHECK(m.e43 == 15);
                CHECK(m.e44 == 16);
            }

            THEN("The resulting matrix is the transpose of the original matrix")
            {
                CHECK(t.e11 == 1);
                CHECK(t.e12 == 5);
                CHECK(t.e13 == 9);
                CHECK(t.e14 == 13);
                CHECK(t.e21 == 2);
                CHECK(t.e22 == 6);
                CHECK(t.e23 == 10);
                CHECK(t.e24 == 14);
                CHECK(t.e31 == 3);
                CHECK(t.e32 == 7);
                CHECK(t.e33 == 11);
                CHECK(t.e34 == 15);
                CHECK(t.e41 == 4);
                CHECK(t.e42 == 8);
                CHECK(t.e43 == 12);
                CHECK(t.e44 == 16);
            }
        }
    }
}

SCENARIO("Matrices can be compared with each other")
{
    GIVEN("2 matrices that are different")
    {
        const Matrix m1 = makeMatrix( 1,  2,  3,  4,
                                      5,  6,  7,  8,
                                      9, 10, 11, 12,
                                     13, 14, 15, 16);
        const Matrix m2 = makeMatrix( 2,  4,  6,  8,
                                     10, 12, 14, 16,
                                     18, 20, 22, 24,
                                     26, 28, 30, 32);

        WHEN("The matrices are compared for equality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(m1 == m2);
            }
        }

        WHEN("The matrices are compared for inequality")
        {
            THEN("The result is true")
            {
                CHECK(m1 != m2);
            }
        }
    }

    GIVEN("2 matrices that are the same")
    {
        const Matrix m1 = makeMatrix( 1,  2,  3,  4,
                                      5,  6,  7,  8,
                                      9, 10, 11, 12,
                                     13, 14, 15, 16);
        const Matrix m2 = makeMatrix( 1,  2,  3,  4,
                                      5,  6,  7,  8,
                                      9, 10, 11, 12,
                                     13, 14, 15, 16);

        WHEN("the matrices are compared for equality")
        {
            THEN("The result is true")
            {
                CHECK(m1 == m2);
            }
        }

        WHEN("the matrices are compared for inequality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(m1 != m2);
            }
        }
    }

    GIVEN("A matrix")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);

        WHEN("The matrix is compared for equality with itself")
        {
            THEN("the result is true")
            {
                CHECK(m == m);
            }
        }

        WHEN("The matrix is compared for inequality with itself")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(m != m);
            }
        }
    }
}

SCENARIO("Matrices can be negated")
{
    GIVEN("A matrix")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);

        WHEN("The matrix is negated")
        {
            const Matrix n = -m;

            THEN("The original matrix is unchanged")
            {
                CHECK(m.e11 == 1);
                CHECK(m.e12 == 2);
                CHECK(m.e13 == 3);
                CHECK(m.e14 == 4);
                CHECK(m.e21 == 5);
                CHECK(m.e22 == 6);
                CHECK(m.e23 == 7);
                CHECK(m.e24 == 8);
                CHECK(m.e31 == 9);
                CHECK(m.e32 == 10);
                CHECK(m.e33 == 11);
                CHECK(m.e34 == 12);
                CHECK(m.e41 == 13);
                CHECK(m.e42 == 14);
                CHECK(m.e43 == 15);
                CHECK(m.e44 == 16);
            }

            THEN("The result is the negated matrix")
            {
                CHECK(n.e11 == -1);
                CHECK(n.e12 == -2);
                CHECK(n.e13 == -3);
                CHECK(n.e14 == -4);
                CHECK(n.e21 == -5);
                CHECK(n.e22 == -6);
                CHECK(n.e23 == -7);
                CHECK(n.e24 == -8);
                CHECK(n.e31 == -9);
                CHECK(n.e32 == -10);
                CHECK(n.e33 == -11);
                CHECK(n.e34 == -12);
                CHECK(n.e41 == -13);
                CHECK(n.e42 == -14);
                CHECK(n.e43 == -15);
                CHECK(n.e44 == -16);
            }
        }
    }
}

SCENARIO("Matrices can be added together")
{
    GIVEN("2 matrices")
    {
        const Matrix m1 = makeMatrix( 1,  2,  3,  4,
                                      5,  6,  7,  8,
                                      9, 10, 11, 12,
                                     13, 14, 15, 16);
        const Matrix m2 = makeMatrix( 2,  4,  6,  8,
                                     10, 12, 14, 16,
                                     18, 20, 22, 24,
                                     26, 28, 30, 32);

        WHEN("The 2 matrices are added together")
        {
            const Matrix sum = m1 + m2;

            THEN("The original matrices are unchanged")
            {
                CHECK(m1.e11 == 1);
                CHECK(m1.e12 == 2);
                CHECK(m1.e13 == 3);
                CHECK(m1.e14 == 4);
                CHECK(m1.e21 == 5);
                CHECK(m1.e22 == 6);
                CHECK(m1.e23 == 7);
                CHECK(m1.e24 == 8);
                CHECK(m1.e31 == 9);
                CHECK(m1.e32 == 10);
                CHECK(m1.e33 == 11);
                CHECK(m1.e34 == 12);
                CHECK(m1.e41 == 13);
                CHECK(m1.e42 == 14);
                CHECK(m1.e43 == 15);
                CHECK(m1.e44 == 16);
                
                CHECK(m2.e11 == 2);
                CHECK(m2.e12 == 4);
                CHECK(m2.e13 == 6);
                CHECK(m2.e14 == 8);
                CHECK(m2.e21 == 10);
                CHECK(m2.e22 == 12);
                CHECK(m2.e23 == 14);
                CHECK(m2.e24 == 16);
                CHECK(m2.e31 == 18);
                CHECK(m2.e32 == 20);
                CHECK(m2.e33 == 22);
                CHECK(m2.e34 == 24);
                CHECK(m2.e41 == 26);
                CHECK(m2.e42 == 28);
                CHECK(m2.e43 == 30);
                CHECK(m2.e44 == 32);
            }

            THEN("The result is the sum of the 2 matrices")
            {
                CHECK(sum.e11 == 3);
                CHECK(sum.e12 == 6);
                CHECK(sum.e13 == 9);
                CHECK(sum.e14 == 12);
                CHECK(sum.e21 == 15);
                CHECK(sum.e22 == 18);
                CHECK(sum.e23 == 21);
                CHECK(sum.e24 == 24);
                CHECK(sum.e31 == 27);
                CHECK(sum.e32 == 30);
                CHECK(sum.e33 == 33);
                CHECK(sum.e34 == 36);
                CHECK(sum.e41 == 39);
                CHECK(sum.e42 == 42);
                CHECK(sum.e43 == 45);
                CHECK(sum.e44 == 48);
            }
        }
    }
}

SCENARIO("Matrices can be subtracted from each other")
{
    GIVEN("2 matrices")
    {
        const Matrix m1 = makeMatrix( 1,  2,  3,  4,
                                      5,  6,  7,  8,
                                      9, 10, 11, 12,
                                     13, 14, 15, 16);
        const Matrix m2 = makeMatrix( 2,  4,  6,  8,
                                     10, 12, 14, 16,
                                     18, 20, 22, 24,
                                     26, 28, 30, 32);

        WHEN("The 2 matrices are subtracted from each other")
        {
            const Matrix diff = m1 - m2;

            THEN("The original matrices are unchanged")
            {
                CHECK(m1.e11 == 1);
                CHECK(m1.e12 == 2);
                CHECK(m1.e13 == 3);
                CHECK(m1.e14 == 4);
                CHECK(m1.e21 == 5);
                CHECK(m1.e22 == 6);
                CHECK(m1.e23 == 7);
                CHECK(m1.e24 == 8);
                CHECK(m1.e31 == 9);
                CHECK(m1.e32 == 10);
                CHECK(m1.e33 == 11);
                CHECK(m1.e34 == 12);
                CHECK(m1.e41 == 13);
                CHECK(m1.e42 == 14);
                CHECK(m1.e43 == 15);
                CHECK(m1.e44 == 16);
                
                CHECK(m2.e11 == 2);
                CHECK(m2.e12 == 4);
                CHECK(m2.e13 == 6);
                CHECK(m2.e14 == 8);
                CHECK(m2.e21 == 10);
                CHECK(m2.e22 == 12);
                CHECK(m2.e23 == 14);
                CHECK(m2.e24 == 16);
                CHECK(m2.e31 == 18);
                CHECK(m2.e32 == 20);
                CHECK(m2.e33 == 22);
                CHECK(m2.e34 == 24);
                CHECK(m2.e41 == 26);
                CHECK(m2.e42 == 28);
                CHECK(m2.e43 == 30);
                CHECK(m2.e44 == 32);
            }

            THEN("The result is the difference of the 2 matrices")
            {
                CHECK(diff.e11 == -1);
                CHECK(diff.e12 == -2);
                CHECK(diff.e13 == -3);
                CHECK(diff.e14 == -4);
                CHECK(diff.e21 == -5);
                CHECK(diff.e22 == -6);
                CHECK(diff.e23 == -7);
                CHECK(diff.e24 == -8);
                CHECK(diff.e31 == -9);
                CHECK(diff.e32 == -10);
                CHECK(diff.e33 == -11);
                CHECK(diff.e34 == -12);
                CHECK(diff.e41 == -13);
                CHECK(diff.e42 == -14);
                CHECK(diff.e43 == -15);
                CHECK(diff.e44 == -16);
            }
        }
    }
}

SCENARIO("Matrices can be multiplied with each other")
{
    GIVEN("2 matrices")
    {
        const Matrix m1 = makeMatrix( 1,  2,  3,  4,
                                      5,  6,  7,  8,
                                      9, 10, 11, 12,
                                     13, 14, 15, 16);
        const Matrix m2 = makeMatrix( 2,  4,  6,  8,
                                     10, 12, 14, 16,
                                     18, 20, 22, 24,
                                     26, 28, 30, 32);

        WHEN("The matrices are multiplied with each other")
        {
            const Matrix prod = m1 * m2;

            THEN("The result is the product of the 2 matrices")
            {
                CHECK(prod.e11 == 180);
                CHECK(prod.e12 == 200);
                CHECK(prod.e13 == 220);
                CHECK(prod.e14 == 240);
                CHECK(prod.e21 == 404);
                CHECK(prod.e22 == 456);
                CHECK(prod.e23 == 508);
                CHECK(prod.e24 == 560);
                CHECK(prod.e31 == 628);
                CHECK(prod.e32 == 712);
                CHECK(prod.e33 == 796);
                CHECK(prod.e34 == 880);
                CHECK(prod.e41 == 852);
                CHECK(prod.e42 == 968);
                CHECK(prod.e43 == 1084);
                CHECK(prod.e44 == 1200);
            }
        }
    }
}

SCENARIO("Matrices can be multiplied by a scalar")
{
    GIVEN("A matrix and a scalar")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);
        const float s = 7;

        WHEN("The matrix is multiplied by the scalar")
        {
            const Matrix prod = m * s;

            THEN("Each component in the matrix is multiplied by the scalar")
            {
                CHECK(prod.e11 == 7);
                CHECK(prod.e12 == 14);
                CHECK(prod.e13 == 21);
                CHECK(prod.e14 == 28);
                CHECK(prod.e21 == 35);
                CHECK(prod.e22 == 42);
                CHECK(prod.e23 == 49);
                CHECK(prod.e24 == 56);
                CHECK(prod.e31 == 63);
                CHECK(prod.e32 == 70);
                CHECK(prod.e33 == 77);
                CHECK(prod.e34 == 84);
                CHECK(prod.e41 == 91);
                CHECK(prod.e42 == 98);
                CHECK(prod.e43 == 105);
                CHECK(prod.e44 == 112);
            }
        }

        WHEN("The scalar is multiplied by the matrix")
        {
            const Matrix prod = s * m;

            THEN("Each component in the matrix is multiplied by the scalar")
            {
                CHECK(prod.e11 == 7);
                CHECK(prod.e12 == 14);
                CHECK(prod.e13 == 21);
                CHECK(prod.e14 == 28);
                CHECK(prod.e21 == 35);
                CHECK(prod.e22 == 42);
                CHECK(prod.e23 == 49);
                CHECK(prod.e24 == 56);
                CHECK(prod.e31 == 63);
                CHECK(prod.e32 == 70);
                CHECK(prod.e33 == 77);
                CHECK(prod.e34 == 84);
                CHECK(prod.e41 == 91);
                CHECK(prod.e42 == 98);
                CHECK(prod.e43 == 105);
                CHECK(prod.e44 == 112);
            }
        }
    }
}

SCENARIO("Matrices can be mulitplied by points")
{
    GIVEN("A matrix and a point")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);
        const Point p = makePoint(2, 5);

        WHEN("The matrix and point are multiplied by each other")
        {
            const Point prod = m * p;

            THEN("The result is the product of the matrix and point")
            {
                CHECK(prod.x == 16);
                CHECK(prod.y == 48);
            }
        }
    }
}

SCENARIO("Matrices can be multiplied by vectors")
{
    GIVEN("A matrix and a vector")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);
        const Vector v = makeVector(2, 5);

        WHEN("The matrix and vector are multiplied by each other")
        {
            const Vector prod = m * v;

            THEN("The result is the product of the matrix and vector")
            {
                CHECK(prod.x == 12);
                CHECK(prod.y == 40);
            }
        }
    }
}

SCENARIO("Matrices can be divided by a scalar")
{
    GIVEN("A matrix and a scalar")
    {
        const Matrix m = makeMatrix( 1,  2,  3,  4,
                                     5,  6,  7,  8,
                                     9, 10, 11, 12,
                                    13, 14, 15, 16);
        const float s = 2;

        WHEN("The matrix is divided by the scalar")
        {
            const Matrix div = m / s;

            THEN("The result is each component divided by the scalar")
            {
                CHECK(div.e11 == 0.5f);
                CHECK(div.e12 == 1.0f);
                CHECK(div.e13 == 1.5f);
                CHECK(div.e14 == 2.0f);
                CHECK(div.e21 == 2.5f);
                CHECK(div.e22 == 3.0f);
                CHECK(div.e23 == 3.5f);
                CHECK(div.e24 == 4.0f);
                CHECK(div.e31 == 4.5f);
                CHECK(div.e32 == 5.0f);
                CHECK(div.e33 == 5.5f);
                CHECK(div.e34 == 6.0f);
                CHECK(div.e41 == 6.5f);
                CHECK(div.e42 == 7.0f);
                CHECK(div.e43 == 7.5f);
                CHECK(div.e44 == 8.0f);
            }
        }
    }
}
