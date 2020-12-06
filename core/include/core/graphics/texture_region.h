#pragma once

#include <cstdint>

namespace caverneer {

struct Texture;

struct TextureRegion
{
    float u1;
    float v1;
    float u2;
    float v2;
    uint32_t texture;
};

TextureRegion makeTextureRegion(const Texture& texture,
                                float u1,
                                float v1,
                                float u2,
                                float v2);
TextureRegion makeTextureRegion(const Texture& texture);

TextureRegion makeTextureRegionFromPixels(const Texture& texture,
                                          uint32_t x1,
                                          uint32_t y1,
                                          uint32_t x2,
                                          uint32_t y2);

} // namespace caverneer
