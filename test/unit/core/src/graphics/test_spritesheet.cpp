#include <catch.hpp>
#include <core/graphics/spritesheet.h>

#include <core/graphics/texture_region.h>

using namespace caverneer;

SCENARIO("Spritesheets are divided in indexed sprites")
{
    GIVEN("A spritesheet without gaps")
    {
        const Spritesheet ss = makeSpritesheet(Texture{ 12, 8, 1 }, 4, 2);

        WHEN("The amount of sprites in the spritesheet is requested")
        {
            THEN("The total amount of sprites is 12")
            {
                CHECK(getSpriteCount(ss) == 12);
            }

            THEN("The amount of sprites along the x-axis is 3")
            {
                CHECK(getSpriteCountX(ss) == 3);
            }

            THEN("The amount of sprites along the y-axis is 4")
            {
                CHECK(getSpriteCountY(ss) == 4);
            }
        }

        WHEN("The texture region of index 7 is requested")
        {
            const TextureRegion region = getSpriteAt(ss, 7);

            THEN("The texture region will contain the sprite at index 7")
            {
                CHECK(region.u1 == 0.333333333f);
                CHECK(region.v1 == 0.5f);
                CHECK(region.u2 == 0.666666667f);
                CHECK(region.v2 == 0.75f);
            }
        }
    }

    GIVEN("A spritesheet with gaps")
    {
        const Spritesheet ss = makeSpritesheet(Texture{ 15, 9, 1 }, 4, 2);

        WHEN("The amount of sprites in the spritesheet is requested")
        {
            THEN("The total amount of sprites is 12")
            {
                CHECK(getSpriteCount(ss) == 12);
            }

            THEN("The amount of sprites along the x-axis is 3")
            {
                CHECK(getSpriteCountX(ss) == 3);
            }

            THEN("The amount of sprites along the y-axis is 4")
            {
                CHECK(getSpriteCountY(ss) == 4);
            }
        }

        WHEN("The texture region of index 7 is requested")
        {
            const TextureRegion region = getSpriteAt(ss, 7);

            THEN("The texture region will contain the sprite at index 7")
            {
                CHECK(region.u1 == 0.266666667f);
                CHECK(region.v1 == 0.444444444f);
                CHECK(region.u2 == 0.533333333f);
                CHECK(region.v2 == 0.666666667f);
            }
        }
    }
}
