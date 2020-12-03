#include <catch.hpp>
#include <core/graphics/pixel.h>

#include <core/graphics/color.h>

using namespace caverneer;

SCENARIO("Pixels can be created from a color")
{
    GIVEN("A white color")
    {
        const Color c = COLOR_WHITE;

        WHEN("The color is used to make a pixel")
        {
            const Pixel p = makePixel(c);

            THEN("The components of the pixel are the max value")
            {
                CHECK(p.r == 255);
                CHECK(p.g == 255);
                CHECK(p.b == 255);
                CHECK(p.a == 255);
            }
        }
    }

    GIVEN("A black color")
    {
        const Color c = COLOR_BLACK;

        WHEN("The color is used to make a pixel")
        {
            const Pixel p = makePixel(c);

            THEN("The components of the pixel are the min value")
            {
                CHECK(p.r == 0);
                CHECK(p.g == 0);
                CHECK(p.b == 0);
                CHECK(p.a == 255);
            }
        }
    }

    GIVEN("A red color")
    {
        const Color c = makeColor(0.5f, 0.0f, 0.0f);

        WHEN("The color is used to make a pixel")
        {
            const Pixel p = makePixel(c);

            THEN("The components of the pixel are the correct value")
            {
                CHECK(p.r == 127);
                CHECK(p.g == 0);
                CHECK(p.b == 0);
                CHECK(p.a == 255);
            }
        }
    }

    GIVEN("A green color")
    {
        const Color c = makeColor(0.0f, 0.5f, 0.0f);

        WHEN("The color is used to make a pixel")
        {
            const Pixel p = makePixel(c);

            THEN("The components of the pixel are the correct value")
            {
                CHECK(p.r == 0);
                CHECK(p.g == 127);
                CHECK(p.b == 0);
                CHECK(p.a == 255);
            }
        }
    }

    GIVEN("A blue color")
    {
        const Color c = makeColor(0.0f, 0.0f, 0.5f);

        WHEN("The color is used to make a pixel")
        {
            const Pixel p = makePixel(c);

            THEN("The components of the pixel are the correct value")
            {
                CHECK(p.r == 0);
                CHECK(p.g == 0);
                CHECK(p.b == 127);
                CHECK(p.a == 255);
            }
        }
    }

    GIVEN("A translucent color")
    {
        const Color c = makeColor(1.0f, 1.0f, 1.0f, 0.5f);

        WHEN("The color is used to make a pixel")
        {
            const Pixel p = makePixel(c);

            THEN("The components of the pixel are the correct value")
            {
                CHECK(p.r == 255);
                CHECK(p.g == 255);
                CHECK(p.b == 255);
                CHECK(p.a == 127);
            }
        }
    }
}
