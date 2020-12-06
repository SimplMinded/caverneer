#include <catch.hpp>
#include <core/graphics/texture_region.h>

#include <core/graphics/texture.h>

using namespace caverneer;

SCENARIO("Texture regions can be constructed")
{
    GIVEN("A texture and 2 texture coordinates")
    {
        const Texture texture = Texture{ 256, 128, 1 };
        const float u1 = 0.2f;
        const float v1 = 0.1f;
        const float u2 = 0.7f;
        const float v2 = 0.9f;

        WHEN("A texture region is created from the given texture and texture "
             "coordinates")
        {
            const TextureRegion region =
                makeTextureRegion(texture, u1, v1, u2, v2);

            THEN("The created texture region uses the given texture and "
                 "texture coordinates")
            {
                CHECK(region.texture == texture.id);
                CHECK(region.u1 == u1);
                CHECK(region.v1 == v1);
                CHECK(region.u2 == u2);
                CHECK(region.v2 == v2);
            }
        }
    }

    GIVEN("A single texture")
    {
        const Texture texture = Texture{ 256, 128, 1 };

        WHEN("A texture region is created from the given texture")
        {
            const TextureRegion region = makeTextureRegion(texture);

            THEN("The created texture region encompasses the entire texture")
            {
                CHECK(region.texture == texture.id);
                CHECK(region.u1 == 0);
                CHECK(region.v1 == 0);
                CHECK(region.u2 == 1);
                CHECK(region.v2 == 1);
            }
        }
    }

    GIVEN("A texture and 2 texture coordinates expressed in pixels")
    {
        const Texture texture = Texture{ 256, 128, 1 };
        const uint32_t x1 = 64;
        const uint32_t y1 = 0;
        const uint32_t x2 = 256;
        const uint32_t y2 = 64;

        WHEN("A texture region is created from the given texture and texture "
             "coordinates")
        {
            const TextureRegion region =
                makeTextureRegionFromPixels(texture, x1, y1, x2, y2);

            THEN("The created texture region uses the converted texture "
                 "coordinates")
            {
                CHECK(region.texture == texture.id);
                CHECK(region.u1 == 0.25f);
                CHECK(region.v1 == 0.0f);
                CHECK(region.u2 == 1.0f);
                CHECK(region.v2 == 0.5f);
            }
        }
    }
}
