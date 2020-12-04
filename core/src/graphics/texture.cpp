#include "core/graphics/texture.h"

#include <glad/glad.h>

#include "graphics/gl_assert.h"

#include "core/debug/assert.h"
#include "core/graphics/image.h"

namespace caverneer {

Texture createTexture(const Image& image)
{
    ASSERT(image.width > 0 && image.width < INT32_MAX);
    ASSERT(image.height > 0 && image.height < INT32_MAX);
    ASSERT(image.data != nullptr);

    uint32_t texture;
    GL_ASSERT(glGenTextures(1, &texture));
    GL_ASSERT(glBindTexture(GL_TEXTURE_2D, texture));

    GL_ASSERT(
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    GL_ASSERT(
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    GL_ASSERT(
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GL_ASSERT(
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GL_ASSERT(glTexImage2D(GL_TEXTURE_2D,
                           0,
                           GL_RGBA,
                           int32_t(image.width),
                           int32_t(image.height),
                           0,
                           GL_RGBA,
                           GL_UNSIGNED_BYTE,
                           image.data));

    return Texture{ image.width, image.height, texture };
}

void deleteTexture(Texture& texture)
{
    ASSERT(texture.id != 0);

    GL_ASSERT(glDeleteTextures(1, &texture.id));

    texture.width = 0;
    texture.height = 0;
    texture.id = 0;
}

} // namespace caverneer
