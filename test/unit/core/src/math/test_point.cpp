#include <catch.hpp>
#include <core/math/point.h>

#include <iostream>

#include <core/math/vector.h>

using namespace caverneer;

namespace caverneer {

std::ostream& operator <<(std::ostream& os, const Point& point)
{
    return os << "Point{ " << point.x << ", " << point.y << " }";
}

} // namespace caverneer

SCENARIO("You can create points using makePoint")
{
    GIVEN("2 float numbers")
    {
        const float x = 2;
        const float y = 5;

        WHEN("A point is constructed using the numbers")
        {
            const Point p = makePoint(x, y);

            THEN("The point's x and y values are set correctly")
            {
                CHECK(p.x == x);
                CHECK(p.y == y);
            }
        }
    }

    GIVEN("Absolutely nothing")
    {
        WHEN("A point is constructed")
        {
            const Point p = makePoint();

            THEN("The point's x and y values are 0")
            {
                CHECK(p.x == 0);
                CHECK(p.y == 0);
            }
        }
    }
}

SCENARIO("You can compare 2 points with each other")
{
    GIVEN("2 points that are different")
    {
        const Point p1 = makePoint(2, 5);
        const Point p2 = makePoint(7, 3);

        WHEN("The 2 points are compared for equality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(p1 == p2);
            }
        }

        WHEN("The 2 points are compared for inequality")
        {
            THEN("The result is true")
            {
                CHECK(p1 != p2);
            }
        }
    }

    GIVEN("2 points that are the same")
    {
        const Point p1 = makePoint(2, 5);
        const Point p2 = makePoint(2, 5);

        WHEN("The 2 points are compared for equality")
        {
            THEN("The result is true")
            {
                CHECK(p1 == p2);
            }
        }

        WHEN("The 2 points are compared for inequality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(p1 != p2);
            }
        }
    }

    GIVEN("A single point")
    {
        const Point p = makePoint(2, 5);

        WHEN("We compare the point for equality with itself")
        {
            THEN("The result is true")
            {
                CHECK(p == p);
            }
        }

        WHEN("We compare the point for inequality with itself")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(p != p);
            }
        }
    }
}

SCENARIO("Points can be negated")
{
    GIVEN("A single point")
    {
        const Point p = makePoint(2, 5);

        WHEN("The point is negated")
        {
            const Point n = -p;

            THEN("The original point is unchanged")
            {
                CHECK(p.x == 2);
                CHECK(p.y == 5);
            }

            THEN("The components of the point have a different sign")
            {
                CHECK(n.x == -2);
                CHECK(n.y == -5);
            }
        }
    }
}

SCENARIO("Points and vectors can be added together")
{
    GIVEN("A point and a vector")
    {
        const Point p = makePoint(2, 5);
        const Vector v = makeVector(7, 3);

        WHEN("The point and vector are added")
        {
            const Point sum = p + v;

            THEN("The original point and vector are unchanged")
            {
                CHECK(p.x == 2);
                CHECK(p.y == 5);

                CHECK(v.x == 7);
                CHECK(v.y == 3);
            }

            THEN("The resulting point is the component-wise sum of the added "
                 "point and vector")
            {
                CHECK(sum.x == 9);
                CHECK(sum.y == 8);
            }
        }

        WHEN("The vector and point are added")
        {
            const Point sum = v + p;

            THEN("The original point and vector are unchanged")
            {
                CHECK(p.x == 2);
                CHECK(p.y == 5);

                CHECK(v.x == 7);
                CHECK(v.y == 3);
            }

            THEN("The resulting point is the component-wise sum of the added "
                 "point and vector")
            {
                CHECK(sum.x == 9);
                CHECK(sum.y == 8);
            }
        }
    }
}

SCENARIO("Points can be subtracted from each other")
{
    GIVEN("2 points")
    {
        const Point p1 = makePoint(2, 5);
        const Point p2 = makePoint(7, 3);

        WHEN("The points are subtracted from each other")
        {
            const Vector diff = p1 - p2;

            THEN("The original points are unchanged")
            {
                CHECK(p1.x == 2);
                CHECK(p1.y == 5);

                CHECK(p2.x == 7);
                CHECK(p2.y == 3);
            }

            THEN("The resulting vector is the component-wise difference of "
                 "the subtracted points")
            {
                CHECK(diff.x == -5);
                CHECK(diff.y == 2);
            }
        }
    }
}

SCENARIO("Points can be subtracted from vectors")
{
    GIVEN("A point and a vector")
    {
        const Point p = makePoint(2, 5);
        const Vector v = makeVector(7, 3);

        WHEN("The point is subtracted from the vector")
        {
            const Point diff = p - v;

            THEN("The original point and vector are unchanged")
            {
                CHECK(p.x == 2);
                CHECK(p.y == 5);

                CHECK(v.x == 7);
                CHECK(v.y == 3);
            }

            THEN("The resulting point is the component-wise difference of the "
                 "subtracted pooint and vector")
            {
                CHECK(diff.x == -5);
                CHECK(diff.y == 2);
            }
        }
    }
}

SCENARIO("Points can be multiplied by a scalar")
{
    GIVEN("A point and a scalar")
    {
        const Point p = makePoint(2, 5);
        const float s = 9;

        WHEN("The point is multiplied by the scalar")
        {
            const Point prod = p * s;

            THEN("The original point is unchanged")
            {
                CHECK(p.x == 2);
                CHECK(p.y == 5);
            }

            THEN("The components of the result are the components of the "
                 "original point multiplied by the scalar")
            {
                CHECK(prod.x == 18);
                CHECK(prod.y == 45);
            }
        }

        WHEN("The scalar is multiplied by the point")
        {
            const Point prod = s * p;

            THEN("The original point is unchanged")
            {
                CHECK(p.x == 2);
                CHECK(p.y == 5);
            }

            THEN("The components of the result are the components of the "
                 "original point multiplied by the scalar")
            {
                CHECK(prod.x == 18);
                CHECK(prod.y == 45);
            }
        }
    }
}

SCENARIO("Points can be divided by a scalar")
{
    GIVEN("A point and a scalar")
    {
        const Point p = makePoint(2, 5);
        const float s = 2;

        WHEN("The point is divided by the scalar")
        {
            const Point prod = p / s;

            THEN("The original point is unchanged")
            {
                CHECK(p.x == 2);
                CHECK(p.y == 5);
            }

            THEN("The components of the result are the components of the "
                 "original point divided by the scalar")
            {
                CHECK(prod.x == 1);
                CHECK(prod.y == 2.5f);
            }
        }
    }
}
