#pragma once

#include <cstdint>

namespace caverneer {

struct Pixel;

struct Image
{
    uint32_t width;
    uint32_t height;
    uint8_t* data;
};

Image makeImage(uint32_t width, uint32_t height, uint8_t* data);

Image loadImage(const char* path);
void deleteImage(Image& image);

Pixel getPixelAt(const Image& image, uint32_t x, uint32_t y);
void setPixelAt(Image& image, uint32_t x, uint32_t y, const Pixel& pixel);

} // namespace caverneer
