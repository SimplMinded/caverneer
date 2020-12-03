#include "core/graphics/pixel.h"

#include "core/graphics/color.h"

namespace caverneer {

Pixel makePixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return Pixel{ r, g, b, a };
}

Pixel makePixel(uint8_t r, uint8_t g, uint8_t b)
{
    return makePixel(r, g, b, UINT8_MAX);
}

Pixel makePixel(const Color& color)
{
    return makePixel(color.r * UINT8_MAX,
                     color.g * UINT8_MAX,
                     color.b * UINT8_MAX,
                     color.a * UINT8_MAX);
}

} // namespace caverneer
