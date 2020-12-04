#include <catch.hpp>
#include <core/graphics/image.h>

#include <cstdint>

#include <core/graphics/pixel.h>

using namespace caverneer;

SCENARIO("Images can be created with 'makeImage'")
{
    GIVEN("A width, height and data pointer")
    {
        const uint32_t width = 2;
        const uint32_t height = 3;
        uint8_t data[width * height * 4] = {};

        WHEN("An image is created using the given values")
        {
            const Image image = makeImage(width, height, data);

            THEN("The data is correctly set in the image struct")
            {
                CHECK(image.width == width);
                CHECK(image.height == height);
                CHECK(image.data == data);
            }
        }
    }
}

SCENARIO("You can get pixels from images")
{
    GIVEN("An image")
    {
        uint8_t data[2 * 3 * 4] = {
              0,   0,   0,   0,
            255, 255, 255, 255,
            128, 128, 128, 128,
            255, 255, 255, 255,
            255, 255, 255, 255,
              0,   0,   0,   0
        };
        const Image image = makeImage(2, 3, data);

        WHEN("The pixel at (0, 0) is requested")
        {
            const Pixel pixel = getPixelAt(image, 0, 0);

            THEN("The pixel components are (0, 0, 0, 0)")
            {
                CHECK(pixel.r == 0);
                CHECK(pixel.g == 0);
                CHECK(pixel.b == 0);
                CHECK(pixel.a == 0);
            }
        }

        WHEN("The pixel at (0, 1) is requested")
        {
            const Pixel pixel = getPixelAt(image, 0, 1);

            THEN("The pixel components are (128, 128, 128, 128)")
            {
                CHECK(pixel.r == 128);
                CHECK(pixel.g == 128);
                CHECK(pixel.b == 128);
                CHECK(pixel.a == 128);
            }
        }

        WHEN("The pixel at (1, 2) is requested")
        {
            const Pixel pixel = getPixelAt(image, 1, 2);

            THEN("The pixel components are (0, 0, 0, 0)")
            {
                CHECK(pixel.r == 0);
                CHECK(pixel.g == 0);
                CHECK(pixel.b == 0);
                CHECK(pixel.a == 0);
            }
        }
    }
}

SCENARIO("You can set pixels in images")
{
    GIVEN("An image and a pixel")
    {
        uint8_t data[2 * 3 * 4] = {};
        Image image = makeImage(2, 3, data);

        const Pixel pixel = makePixel(128, 128, 128, 128);

        WHEN("The pixel at (0, 0) is set")
        {
            setPixelAt(image, 0, 0, pixel);

            THEN("The pixel at (0, 0) is the set pixel, the rest 0")
            {
                CHECK(image.data[0] == 128);
                CHECK(image.data[1] == 128);
                CHECK(image.data[2] == 128);
                CHECK(image.data[3] == 128);
 
                CHECK(image.data[4] == 0);
                CHECK(image.data[5] == 0);
                CHECK(image.data[6] == 0);
                CHECK(image.data[7] == 0);
 
                CHECK(image.data[8] == 0);
                CHECK(image.data[9] == 0);
                CHECK(image.data[10] == 0);
                CHECK(image.data[11] == 0);
 
                CHECK(image.data[12] == 0);
                CHECK(image.data[13] == 0);
                CHECK(image.data[14] == 0);
                CHECK(image.data[15] == 0);
 
                CHECK(image.data[16] == 0);
                CHECK(image.data[17] == 0);
                CHECK(image.data[18] == 0);
                CHECK(image.data[19] == 0);
 
                CHECK(image.data[20] == 0);
                CHECK(image.data[21] == 0);
                CHECK(image.data[22] == 0);
                CHECK(image.data[23] == 0);
            }
        }

        WHEN("The pixel at (0, 1) is set")
        {
            setPixelAt(image, 0, 1, pixel);

            THEN("The pixel at (0, 1) is the set pixel, the rest 0")
            {
                CHECK(image.data[0] == 0);
                CHECK(image.data[1] == 0);
                CHECK(image.data[2] == 0);
                CHECK(image.data[3] == 0);
 
                CHECK(image.data[4] == 0);
                CHECK(image.data[5] == 0);
                CHECK(image.data[6] == 0);
                CHECK(image.data[7] == 0);
 
                CHECK(image.data[8] == 128);
                CHECK(image.data[9] == 128);
                CHECK(image.data[10] == 128);
                CHECK(image.data[11] == 128);
 
                CHECK(image.data[12] == 0);
                CHECK(image.data[13] == 0);
                CHECK(image.data[14] == 0);
                CHECK(image.data[15] == 0);
 
                CHECK(image.data[16] == 0);
                CHECK(image.data[17] == 0);
                CHECK(image.data[18] == 0);
                CHECK(image.data[19] == 0);
 
                CHECK(image.data[20] == 0);
                CHECK(image.data[21] == 0);
                CHECK(image.data[22] == 0);
                CHECK(image.data[23] == 0);
            }
        }

        WHEN("The pixel at (1, 2) is set")
        {
            setPixelAt(image, 1, 2, pixel);

            THEN("The pixel at (1, 2) is the set pixel, the rest 0")
            {
                CHECK(image.data[0] == 0);
                CHECK(image.data[1] == 0);
                CHECK(image.data[2] == 0);
                CHECK(image.data[3] == 0);
 
                CHECK(image.data[4] == 0);
                CHECK(image.data[5] == 0);
                CHECK(image.data[6] == 0);
                CHECK(image.data[7] == 0);
 
                CHECK(image.data[8] == 0);
                CHECK(image.data[9] == 0);
                CHECK(image.data[10] == 0);
                CHECK(image.data[11] == 0);
 
                CHECK(image.data[12] == 0);
                CHECK(image.data[13] == 0);
                CHECK(image.data[14] == 0);
                CHECK(image.data[15] == 0);
 
                CHECK(image.data[16] == 0);
                CHECK(image.data[17] == 0);
                CHECK(image.data[18] == 0);
                CHECK(image.data[19] == 0);
 
                CHECK(image.data[20] == 128);
                CHECK(image.data[21] == 128);
                CHECK(image.data[22] == 128);
                CHECK(image.data[23] == 128);
            }
        }
    }
}
