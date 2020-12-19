#include "core/graphics/image.h"

#include <stb_image.h>

#include "core/debug/assert.h"
#include "core/graphics/pixel.h"

namespace caverneer {

Image makeImage(uint32_t width, uint32_t height, uint8_t* data)
{
    ASSERT(data != nullptr);

    return Image{ width, height, data };
}

Image loadImage(const char* path)
{
    ASSERT(path != nullptr);

    stbi_set_flip_vertically_on_load(true);

    int32_t width;
    int32_t height;
    int32_t channelCount;
    uint8_t* data = stbi_load(path, &width, &height, &channelCount, 4);

    return makeImage(uint32_t(width), uint32_t(height), data);
}

void deleteImage(Image& image)
{
    ASSERT(image.width > 0);
    ASSERT(image.height > 0);
    ASSERT(image.data != nullptr);

    stbi_image_free(image.data);

    image.width = 0;
    image.height = 0;
    image.data = nullptr;
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
