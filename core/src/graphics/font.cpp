#include "core/graphics/font.h"

#include <cstdint>

#include "core/debug/assert.h"
#include "core/graphics/spritesheet.h"
#include "core/graphics/texture_region.h"

namespace caverneer {

static uint32_t getSpriteIndexFor(char character)
{
    ASSERT(character >= ' ');

    return character - ' ';
}

TextureRegion getSpriteFor(const Spritesheet& font, char character)
{
    return getSpriteAt(font, getSpriteIndexFor(character));
}

} // namespace caverneer
