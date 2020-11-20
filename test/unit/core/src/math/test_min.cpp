#include <catch.hpp>
#include <core/math/util.h>

#include <cstdint>

using namespace caverneer;

SCENARIO("The function 'min' returns the smallest given value")
{
    GIVEN("Int8 numbers")
    {
        const int8_t a = 2;
        const int8_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const int8_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const int8_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const int8_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }

    GIVEN("Int16 numbers")
    {
        const int16_t a = 2;
        const int16_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const int16_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const int16_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const int16_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }

    GIVEN("Int32 numbers")
    {
        const int32_t a = 2;
        const int32_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const int32_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const int32_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const int32_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }

    GIVEN("Int64 numbers")
    {
        const int64_t a = 2;
        const int64_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const int64_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const int64_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const int64_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }
    
    GIVEN("Uint8 numbers")
    {
        const uint8_t a = 2;
        const uint8_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const uint8_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const uint8_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const uint8_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }

    GIVEN("Uint16 numbers")
    {
        const uint16_t a = 2;
        const uint16_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const uint16_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const uint16_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const uint16_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }

    GIVEN("Uint32 numbers")
    {
        const uint32_t a = 2;
        const uint32_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const uint32_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const uint32_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const uint32_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }

    GIVEN("Uint64 numbers")
    {
        const uint64_t a = 2;
        const uint64_t b = 5;

        WHEN("Calling min(a, b)")
        {
            const uint64_t c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const uint64_t c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const uint64_t c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }

    GIVEN("Float numbers")
    {
        const float a = 2;
        const float b = 5;

        WHEN("Calling min(a, b)")
        {
            const float c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const float c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const float c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }
    
    GIVEN("Double numbers")
    {
        const double a = 2;
        const double b = 5;

        WHEN("Calling min(a, b)")
        {
            const double c = min(a, b);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(b, a)")
        {
            const double c = min(b, a);

            THEN("The result will be the smallest number")
            {
                CHECK(c == 2);
            }
        }

        WHEN("Calling min(a, a)")
        {
            const double c = min(a, a);

            THEN("The result will be the given number")
            {
                CHECK(c == 2);
            }
        }
    }
}
