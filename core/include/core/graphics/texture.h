#pragma once

#include <cstdint>

namespace caverneer {

struct Image;

struct Texture
{
    uint32_t width;
    uint32_t height;
    uint32_t id;
};

Texture createTexture(const Image& image);
void deleteTexture(Texture& texture);

} // namespace caverneer
