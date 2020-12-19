#include "core/graphics/spritesheet.h"

#include "core/debug/assert.h"
#include "core/graphics/image.h"
#include "core/graphics/texture_region.h"

namespace caverneer {

Spritesheet makeSpritesheet(const Texture& texture,
                            uint32_t spriteWidth,
                            uint32_t spriteHeight)
{
    ASSERT(texture.id != 0);
    ASSERT(spriteWidth > 0 && spriteWidth < texture.width);
    ASSERT(spriteHeight > 0 && spriteHeight < texture.height);

    return Spritesheet{ texture, spriteWidth, spriteHeight };
}

Spritesheet createSpritesheet(const Image& image,
                              uint32_t spriteWidth,
                              uint32_t spriteHeight)
{
    return makeSpritesheet(createTexture(image), spriteWidth, spriteHeight);
}

Spritesheet loadSpritesheet(const char* path,
                            uint32_t spriteWidth,
                            uint32_t spriteHeight)
{
    Image image = loadImage(path);
    const Texture texture = createTexture(image);
    deleteImage(image);

    return makeSpritesheet(texture, spriteWidth, spriteHeight);
}

void deleteSpritesheet(Spritesheet& spritesheet)
{
    deleteTexture(spritesheet.texture);

    spritesheet.texture.id = 0;
    spritesheet.texture.width = 0;
    spritesheet.texture.height = 0;
    spritesheet.spriteWidth = 0;
    spritesheet.spriteHeight = 0;
}

uint32_t getSpriteCount(const Spritesheet& spritesheet)
{
    return getSpriteCountX(spritesheet) * getSpriteCountY(spritesheet);
}

uint32_t getSpriteCountX(const Spritesheet& spritesheet)
{
    ASSERT(spritesheet.texture.width > 0);
    ASSERT(spritesheet.spriteWidth > 0);

    return spritesheet.texture.width / spritesheet.spriteWidth;
}

uint32_t getSpriteCountY(const Spritesheet& spritesheet)
{
    ASSERT(spritesheet.texture.height > 0);
    ASSERT(spritesheet.spriteHeight > 0);

    return spritesheet.texture.height / spritesheet.spriteHeight;
}

TextureRegion getSpriteAt(const Spritesheet& spritesheet, uint32_t index)
{
    ASSERT(index < getSpriteCount(spritesheet));
    ASSERT(spritesheet.spriteWidth > 0 &&
           spritesheet.spriteWidth < spritesheet.texture.width);
    ASSERT(spritesheet.spriteHeight > 0 &&
           spritesheet.spriteHeight < spritesheet.texture.height);

    const uint32_t xIndex = index % getSpriteCountX(spritesheet);
    const uint32_t yIndex = index / getSpriteCountX(spritesheet);

    const uint32_t x1 = xIndex * spritesheet.spriteWidth;
    const uint32_t y1 = yIndex * spritesheet.spriteHeight;
    const uint32_t x2 = x1 + spritesheet.spriteWidth;
    const uint32_t y2 = y1 + spritesheet.spriteHeight;

    return makeTextureRegionFromPixels(spritesheet.texture, x1, y1, x2, y2);
}

} // namespace caverneer
