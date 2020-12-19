#pragma once

#include <cstdint>

#include <core/graphics/texture.h>

namespace caverneer {

struct Image;
struct TextureRegion;

struct Spritesheet
{
    Texture texture;
    uint32_t spriteWidth;
    uint32_t spriteHeight;
};

Spritesheet makeSpritesheet(const Texture& texture,
                            uint32_t spriteWidth,
                            uint32_t spriteHeight);

Spritesheet createSpritesheet(const Image& image,
                              uint32_t spriteWidth,
                              uint32_t spriteHeight);

Spritesheet loadSpritesheet(const char* path,
                            uint32_t spriteWidth,
                            uint32_t spriteHeight);

void deleteSpritesheet(Spritesheet& spritesheet);

uint32_t getSpriteCount(const Spritesheet& spritesheet);
uint32_t getSpriteCountX(const Spritesheet& spritesheet);
uint32_t getSpriteCountY(const Spritesheet& spritesheet);

TextureRegion getSpriteAt(const Spritesheet& spritesheet, uint32_t index);

} // namespace caverneer
