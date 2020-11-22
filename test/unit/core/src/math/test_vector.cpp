#include <catch.hpp>
#include <core/math/vector.h>

#include <iostream>

using namespace caverneer;

namespace caverneer {

std::ostream& operator <<(std::ostream& os, const Vector& vector)
{
    return os << "Vector{ " << vector.x << ", " << vector.y << " }";
}

} // namespace caverneer

SCENARIO("You can create vectors using makeVector")
{
    GIVEN("2 float numbers")
    {
        const float x = 2;
        const float y = 5;

        WHEN("A vector is constructed using the numbers")
        {
            const Vector v = makeVector(x, y);

            THEN("The vector's x and y values are set correctly")
            {
                CHECK(v.x == x);
                CHECK(v.y == y);
            }
        }
    }

    GIVEN("Absolutely nothing")
    {
        WHEN("A vector is constructed")
        {
            const Vector v = makeVector();

            THEN("The vector's x and y values are 0")
            {
                CHECK(v.x == 0);
                CHECK(v.y == 0);
            }
        }
    }
}

SCENARIO("You can compare 2 vectors with each other")
{
    GIVEN("2 vectors that are different")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(7, 3);

        WHEN("The 2 vectors are compared for equality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(v1 == v2);
            }
        }

        WHEN("The 2 vectors are compared for inequality")
        {
            THEN("The result is true")
            {
                CHECK(v1 != v2);
            }
        }
    }

    GIVEN("2 vectors that are the same")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(2, 5);

        WHEN("The 2 vectors are compared for equality")
        {
            THEN("The result is true")
            {
                CHECK(v1 == v2);
            }
        }

        WHEN("The 2 vectors are compared for inequality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(v1 != v2);
            }
        }
    }

    GIVEN("A single vector")
    {
        const Vector v = makeVector(2, 5);

        WHEN("We compare the vector for equality with itself")
        {
            THEN("The result is true")
            {
                CHECK(v == v);
            }
        }

        WHEN("We compare the vector for inequality with itself")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(v != v);
            }
        }
    }
}

SCENARIO("Vectors have a length")
{
    GIVEN("A vector")
    {
        const Vector v = makeVector(2, 5);

        WHEN("The squared length is requested")
        {
            const float sl = lengthSquared(v);

            THEN("The result is the sqaured euclidean length of the vector")
            {
                CHECK(sl == 29);
            }
        }

        WHEN("The length of the vector is requested")
        {
            const float l = length(v);

            THEN("The result is the euclidean length of the vector")
            {
                CHECK(l == 5.385164807f);
            }
        }
    }
}

SCENARIO("Vectors can be normalized")
{
    GIVEN("A vector")
    {
        const Vector v = makeVector(2, 5);

        WHEN("The vector is normalize")
        {
            const Vector n = normalize(v);

            THEN("The original vector is unchanged")
            {
                CHECK(v.x == 2);
                CHECK(v.y == 5);
            }

            THEN("The normalize vector has a length of 1")
            {
                CHECK(length(n) == 1);
            }

            THEN("The normalize vector components are the components of the "
                 "original vector divided by the length of the original vector")
            {
                CHECK(n.x == 0.371390676f);
                CHECK(n.y == 0.928476691f);
            }
        }
    }
}

SCENARIO("Vectors have a dot product")
{
    GIVEN("2 parallel vectors pointing in the same direction")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(6, 15);

        WHEN("The dot product is taken between the 2 normalized vectors")
        {
            const float result = dot(normalize(v1), normalize(v2));

            THEN("The result is 1")
            {
                CHECK(result == 1);
            }
        }
    }

    GIVEN("2 parallel vectors pointing in opposite directions")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(-2, -5);

        WHEN("The dot product is taken between the 2 normalized vectors")
        {
            const float result = dot(normalize(v1), normalize(v2));

            THEN("The result is -1")
            {
                CHECK(result == -1);
            }
        }
    }

    GIVEN("2 orthogonal vectors")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(5, -2);

        WHEN("The dot product is taken between the 2 normalized vectors")
        {
            const float result = dot(normalize(v1), normalize(v2));

            THEN("The result is 0")
            {
                CHECK(result == 0);
            }
        }
    }

    GIVEN("2 vectors forming an angle less than 90 degrees")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(5, 0);

        WHEN("The dot product is taken between the 2 normalized vectors")
        {
            const float result = dot(normalize(v1), normalize(v2));

            THEN("The result is greater than 0")
            {
                CHECK(result > 0);
            }
        }
    }

    GIVEN("2 vectors formaing an angle greater than 90 degrees")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(3, -3);

        WHEN("The dot product is taken between the 2 normalized vectors")
        {
            const float result = dot(normalize(v1), normalize(v2));

            THEN("The result is less than 0")
            {
                CHECK(result < 0);
            }
        }
    }
}

SCENARIO("Vectors can be negated")
{
    GIVEN("A single vector")
    {
        const Vector v = makeVector(2, 5);

        WHEN("The vector is negated")
        {
            const Vector n = -v;

            THEN("The original vector is unchanged")
            {
                CHECK(v.x == 2);
                CHECK(v.y == 5);
            }

            THEN("The components of the vector have a different sign")
            {
                CHECK(n.x == -2);
                CHECK(n.y == -5);
            }
        }
    }
}

SCENARIO("Vectors and vectors can be added together")
{
    GIVEN("2 vectors")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(7, 3);

        WHEN("The vectors are added")
        {
            const Vector sum = v1 + v2;

            THEN("The original vectors are unchanged")
            {
                CHECK(v1.x == 2);
                CHECK(v1.y == 5);

                CHECK(v2.x == 7);
                CHECK(v2.y == 3);
            }

            THEN("The resulting vector is the component-wise sum of the added "
                 "vectors")
            {
                CHECK(sum.x == 9);
                CHECK(sum.y == 8);
            }
        }
    }
}

SCENARIO("Vectors can be subtracted from each other")
{
    GIVEN("2 vectors")
    {
        const Vector v1 = makeVector(2, 5);
        const Vector v2 = makeVector(7, 3);

        WHEN("The vectors are subtracted from each other")
        {
            const Vector diff = v1 - v2;

            THEN("The original vectors are unchanged")
            {
                CHECK(v1.x == 2);
                CHECK(v1.y == 5);

                CHECK(v2.x == 7);
                CHECK(v2.y == 3);
            }

            THEN("The resulting vector is the component-wise difference of "
                 "the subtracted vectors")
            {
                CHECK(diff.x == -5);
                CHECK(diff.y == 2);
            }
        }
    }
}

SCENARIO("Vectors can be multiplied by a scalar")
{
    GIVEN("A vector and a scalar")
    {
        const Vector v = makeVector(2, 5);
        const float s = 9;

        WHEN("The vector is multiplied by the scalar")
        {
            const Vector prod = v * s;

            THEN("The original vector is unchanged")
            {
                CHECK(v.x == 2);
                CHECK(v.y == 5);
            }

            THEN("The components of the result are the components of the "
                 "original vector multiplied by the scalar")
            {
                CHECK(prod.x == 18);
                CHECK(prod.y == 45);
            }
        }

        WHEN("The scalar is multiplied by the vector")
        {
            const Vector prod = s * v;

            THEN("The original vector is unchanged")
            {
                CHECK(v.x == 2);
                CHECK(v.y == 5);
            }

            THEN("The components of the result are the components of the "
                 "original vector multiplied by the scalar")
            {
                CHECK(prod.x == 18);
                CHECK(prod.y == 45);
            }
        }
    }
}

SCENARIO("Vectors can be divided by a scalar")
{
    GIVEN("A vector and a scalar")
    {
        const Vector v = makeVector(2, 5);
        const float s = 2;

        WHEN("The vector is divided by the scalar")
        {
            const Vector prod = v / s;

            THEN("The original vector is unchanged")
            {
                CHECK(v.x == 2);
                CHECK(v.y == 5);
            }

            THEN("The components of the result are the components of the "
                 "original vector divided by the scalar")
            {
                CHECK(prod.x == 1);
                CHECK(prod.y == 2.5f);
            }
        }
    }
}
