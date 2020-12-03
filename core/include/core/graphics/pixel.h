#pragma once

#include <cstdint>

namespace caverneer {

struct Color;

struct Pixel
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

Pixel makePixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
Pixel makePixel(uint8_t r, uint8_t g, uint8_t b);
Pixel makePixel(const Color& color);

} // namespace caverneer
