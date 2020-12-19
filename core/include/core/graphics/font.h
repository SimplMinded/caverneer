#pragma once

namespace caverneer {

struct Spritesheet;
struct TextureRegion;

TextureRegion getSpriteFor(const Spritesheet& font, char character);

} // namespace caverneer
