#include "core/graphics/texture_region.h"

#include "core/debug/assert.h"
#include "core/graphics/texture.h"

namespace caverneer {

TextureRegion makeTextureRegion(const Texture& texture,
                                float u1,
                                float v1,
                                float u2,
                                float v2)
{
    ASSERT(texture.id != 0);
    ASSERT(u1 >= 0 && u1 < u2 && u2 <= 1);
    ASSERT(v1 >= 0 && v1 < v2 && v2 <= 1);

    return TextureRegion{ u1, v1, u2, v2, texture.id };
}

TextureRegion makeTextureRegion(const Texture& texture)
{
    return makeTextureRegion(texture, 0, 0, 1, 1);
}

TextureRegion makeTextureRegionFromPixels(const Texture& texture,
                                          uint32_t x1,
                                          uint32_t y1,
                                          uint32_t x2,
                                          uint32_t y2)
{
    ASSERT(texture.width > 0);
    ASSERT(texture.height > 0);
    ASSERT(texture.id != 0);
    ASSERT(x1 < x2 <= texture.width);
    ASSERT(y1 < y2 <= texture.height);

    const float u1 = float(x1) / float(texture.width);
    const float v1 = float(y1) / float(texture.height);
    const float u2 = float(x2) / float(texture.width);
    const float v2 = float(y2) / float(texture.height);

    return makeTextureRegion(texture, u1, v1, u2, v2);
}

} // namespace caverneer
