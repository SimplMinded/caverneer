#include "core/graphics/image.h"

#include "core/debug/assert.h"
#include "core/graphics/pixel.h"

namespace caverneer {

Image makeImage(uint32_t width, uint32_t height, uint8_t* data)
{
    ASSERT(data != nullptr);

    return Image{ width, height, data };
}

Pixel getPixelAt(const Image& image, uint32_t x, uint32_t y)
{
    ASSERT(image.data != nullptr);
    ASSERT(x < image.width);
    ASSERT(y < image.height);

    uint8_t const* pixelData = &image.data[(x * 4) + (y * image.width * 4)];
    
    return makePixel(pixelData[0], pixelData[1], pixelData[2], pixelData[3]);
}

void setPixelAt(Image& image, uint32_t x, uint32_t y, const Pixel& pixel)
{
    ASSERT(image.data != nullptr);
    ASSERT(x < image.width);
    ASSERT(y < image.height);

    uint8_t* pixelData = &image.data[(x * 4) + (y * image.width * 4)];

    pixelData[0] = pixel.r;
    pixelData[1] = pixel.g;
    pixelData[2] = pixel.b;
    pixelData[3] = pixel.a;
}

} // namespace caverneer
