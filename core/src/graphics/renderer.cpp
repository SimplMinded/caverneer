#include "core/graphics/renderer.h"

#include <cstddef>
#include <cstdint>
#include <cstdlib>

#include <glad/glad.h>

#include "core/debug/assert.h"
#include "core/debug/terminal.h"
#include "core/graphics/color.h"
#include "core/graphics/font.h"
#include "core/graphics/rect.h"
#include "core/graphics/spritesheet.h"
#include "core/graphics/texture_region.h"
#include "core/math/matrix.h"
#include "core/math/point.h"
#include "core/util/unreachable.h"
#include "core/window.h"

#include "graphics/gl_assert.h"

namespace caverneer {

namespace {

constexpr const char* vertex_shader =
    "#version 400\n"
    "\n"
    "layout(location=0) in vec4 in_position;\n"
    "layout(location=1) in uint in_textureIndex;\n"
    "layout(location=2) in vec2 in_textureCoords;\n"
    "layout(location=3) in vec4 in_color;\n"
    "\n"
    "uniform mat4 u_projection;\n"
    "\n"
    "flat out uint vert_textureIndex;\n"
    "out vec2 vert_textureCoords;\n"
    "out vec4 vert_color;\n"
    "\n"
    "void main() {\n"
    "    gl_Position = u_projection * in_position;\n"
    "    vert_textureIndex = in_textureIndex;\n"
    "    vert_textureCoords = in_textureCoords;\n"
    "    vert_color = in_color;\n"
    "}\n";

constexpr const char* fragment_shader =
    "#version 400\n"
    "\n"
    "flat in uint vert_textureIndex;\n"
    "in vec2 vert_textureCoords;\n"
    "in vec4 vert_color;\n"
    "\n"
    "uniform sampler2D[16] u_samplers;\n"
    "\n"
    "out vec4 frag_color;\n"
    "\n"
    "void main() {\n"
    "    if (vert_textureIndex != 0) {\n"
    "        frag_color = texture(u_samplers[vert_textureIndex], "
                                 "vert_textureCoords) * vert_color;\n"
    "    } else {\n"
    "        frag_color = vert_color;\n"
    "    }\n"
    "}\n";

constexpr uint32_t max_log_length = 1024;

const char* getShaderTypeName(uint32_t type)
{
    switch (type)
    {
        case GL_VERTEX_SHADER:
            return "VERTEX";
        case GL_FRAGMENT_SHADER:
            return "FRAGMENT";
        default:
            UNREACHABLE("Unknown shader type: %u", type);
    }
}

void verifyShaderCompilation(uint32_t type, uint32_t shader)
{
    int32_t status;
    GL_ASSERT(glGetShaderiv(shader, GL_COMPILE_STATUS, &status));
    if (status != GL_TRUE)
    {
        int32_t logLength = 0;
        char message[max_log_length] = {};
        GL_ASSERT(glGetShaderInfoLog(shader,
                                     max_log_length,
                                     &logLength,
                                     message));
        debugPrint("[SHADER_COMPILATION] %s: %s",
                   getShaderTypeName(type),
                   message);
        abort();
    }
}

uint32_t createShader(uint32_t type, const char* source)
{
    GL_ASSERT(const uint32_t shader = glCreateShader(type));
    GL_ASSERT(glShaderSource(shader, 1, &source, nullptr));
    GL_ASSERT(glCompileShader(shader));

    verifyShaderCompilation(type, shader);

    return shader;
}

void verifyShaderProgramLinking(uint32_t program)
{
    int32_t status;
    GL_ASSERT(glGetProgramiv(program, GL_LINK_STATUS, &status));
    if (status != GL_TRUE)
    {
        int32_t logLength = 0;
        char message[max_log_length] = {};
        GL_ASSERT(glGetProgramInfoLog(program,
                                      max_log_length,
                                      &logLength,
                                      message));
        debugPrint("[PROGRAM LINKING] %s", message);
        abort();
    }
}

uint32_t createShaderProgram(uint32_t vertexShader, uint32_t fragmentShader)
{
    GL_ASSERT(const uint32_t program = glCreateProgram());
    GL_ASSERT(glAttachShader(program, vertexShader));
    GL_ASSERT(glAttachShader(program, fragmentShader));
    GL_ASSERT(glLinkProgram(program));

    verifyShaderProgramLinking(program);

    return program;
}

uint32_t vao;
uint32_t vbo;
uint32_t ibo;
uint32_t program;

struct Vertex
{
    Point position;
    uint32_t textureIndex;
    Point textureCoords;
    Color color;
};

constexpr uint32_t max_sprite_count = 10000;

Vertex vertices[4 * max_sprite_count];
uint32_t spriteCount;

Matrix viewTransform;

constexpr uint32_t max_texture_count = 16;

uint32_t textures[max_texture_count];
uint32_t textureCount;

} // namespace

void initRenderer(const Matrix& projection)
{
    ASSERT(projection != MATRIX_ZERO);

    ASSERT(vao == 0);
    ASSERT(vbo == 0);
    ASSERT(ibo == 0);
    ASSERT(program == 0);

    GL_ASSERT(glGenVertexArrays(1, &vao));
    GL_ASSERT(glBindVertexArray(vao));

    GL_ASSERT(glGenBuffers(1, &vbo));
    GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo));

    GL_ASSERT(glEnableVertexAttribArray(0));
    GL_ASSERT(glVertexAttribPointer(0,
                                    2,
                                    GL_FLOAT,
                                    GL_FALSE,
                                    sizeof(Vertex),
                                    reinterpret_cast<void*>(
                                        offsetof(Vertex, position))));

    GL_ASSERT(glEnableVertexAttribArray(1));
    GL_ASSERT(glVertexAttribIPointer(1,
                                     1,
                                     GL_UNSIGNED_INT,
                                     sizeof(Vertex),
                                     reinterpret_cast<void*>(
                                         offsetof(Vertex, textureIndex))));

    GL_ASSERT(glEnableVertexAttribArray(2));
    GL_ASSERT(glVertexAttribPointer(2,
                                    2,
                                    GL_FLOAT,
                                    GL_FALSE,
                                    sizeof(Vertex),
                                    reinterpret_cast<void*>(
                                        offsetof(Vertex, textureCoords))));

    GL_ASSERT(glEnableVertexAttribArray(3));
    GL_ASSERT(glVertexAttribPointer(3,
                                    4,
                                    GL_FLOAT,
                                    GL_FALSE,
                                    sizeof(Vertex),
                                    reinterpret_cast<void*>(
                                        offsetof(Vertex, color))));

    GL_ASSERT(glGenBuffers(1, &ibo));
    GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));

    const uint32_t vertexShader =
        createShader(GL_VERTEX_SHADER, vertex_shader);
    const uint32_t fragmentShader =
        createShader(GL_FRAGMENT_SHADER, fragment_shader);
    program = createShaderProgram(vertexShader, fragmentShader);
    GL_ASSERT(glDeleteShader(vertexShader));
    GL_ASSERT(glDeleteShader(fragmentShader));
    GL_ASSERT(glUseProgram(program));

    GL_ASSERT(glBufferData(GL_ARRAY_BUFFER,
                           4 * max_sprite_count * sizeof(Vertex),
                           nullptr,
                           GL_DYNAMIC_DRAW));

    uint32_t* indices = new uint32_t[6 * max_sprite_count];
    for (uint32_t i = 0; i < max_sprite_count; i++)
    {
        indices[(i * 6) + 0] = (i * 4) + 0;
        indices[(i * 6) + 1] = (i * 4) + 1;
        indices[(i * 6) + 2] = (i * 4) + 2;
        indices[(i * 6) + 3] = (i * 4) + 0;
        indices[(i * 6) + 4] = (i * 4) + 2;
        indices[(i * 6) + 5] = (i * 4) + 3;
    }
    GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                           6 * max_sprite_count * sizeof(uint32_t),
                           indices,
                           GL_STATIC_DRAW));
    delete[] indices;

    GL_ASSERT(const int32_t projectionLocation =
        glGetUniformLocation(program, "u_projection"));
    GL_ASSERT(glUniformMatrix4fv(projectionLocation,
                                 1,
                                 GL_FALSE,
                                 projection.elems));

    int32_t samplers[max_texture_count];
    for (int32_t i = 0; i < max_texture_count; i++)
    {
        samplers[i] = i;
    }
    GL_ASSERT(const int32_t samplersLocation =
        glGetUniformLocation(program, "u_samplers"));
    GL_ASSERT(glUniform1iv(samplersLocation, max_texture_count, samplers));

    GL_ASSERT(glEnable(GL_BLEND));
    GL_ASSERT(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    viewTransform = MATRIX_IDENTITY;

    textures[0] = 0;
}

void destroyRenderer()
{
    ASSERT(vao != 0);
    ASSERT(vbo != 0);
    ASSERT(ibo != 0);
    ASSERT(program != 0);

    GL_ASSERT(glDeleteProgram(program));
    GL_ASSERT(glDeleteBuffers(1, &ibo));
    GL_ASSERT(glDeleteBuffers(1, &vbo));
    GL_ASSERT(glDeleteVertexArrays(1, &vao));

    vao = 0;
    vbo = 0;
    ibo = 0;
    program = 0;
}

void beginRendering()
{
    spriteCount = 0;
    textureCount = 1;

    GL_ASSERT(glClear(GL_COLOR_BUFFER_BIT));
}

void endRendering()
{
    for (uint32_t i = 0; i < textureCount; i++)
    {
        GL_ASSERT(glActiveTexture(GL_TEXTURE0 + i));
        GL_ASSERT(glBindTexture(GL_TEXTURE_2D, textures[i]));
    }

    GL_ASSERT(glBufferSubData(GL_ARRAY_BUFFER,
                              0,
                              4 * spriteCount * sizeof(Vertex),
                              vertices));
    GL_ASSERT(glDrawElements(GL_TRIANGLES,
                             6 * spriteCount,
                             GL_UNSIGNED_INT,
                             0));

    updateWindow();
}

void enterView(const Matrix& view)
{
    ASSERT(viewTransform == MATRIX_IDENTITY);

    viewTransform = view;
}

void exitView()
{
    viewTransform = MATRIX_IDENTITY;
}

void drawQuad(const Rect& rect,
              const TextureRegion& region,
              const Color& color)
{
    uint32_t textureIndex = 0;
    for (; textureIndex < textureCount; textureIndex++)
    {
        if (textures[textureIndex] == region.texture) break;
    }
    if (textureIndex == textureCount)
    {
        ASSERT(textureCount < max_texture_count);
        textures[textureCount++] = region.texture;
    }

    const float x1 = rect.x;
    const float x2 = rect.x + rect.width;
    const float y1 = rect.y;
    const float y2 = rect.y + rect.height;

    const Point p1 = viewTransform * makePoint(x1, y1);
    const Point p2 = viewTransform * makePoint(x1, y2);
    const Point p3 = viewTransform * makePoint(x2, y2);
    const Point p4 = viewTransform * makePoint(x2, y1);

    const Point uv1 = makePoint(region.u1, 1 - region.v2);
    const Point uv2 = makePoint(region.u1, 1 - region.v1);
    const Point uv3 = makePoint(region.u2, 1 - region.v1);
    const Point uv4 = makePoint(region.u2, 1 - region.v2);

    vertices[(spriteCount * 4) + 0] = Vertex{ p1, textureIndex, uv1, color };
    vertices[(spriteCount * 4) + 1] = Vertex{ p2, textureIndex, uv2, color };
    vertices[(spriteCount * 4) + 2] = Vertex{ p3, textureIndex, uv3, color };
    vertices[(spriteCount * 4) + 3] = Vertex{ p4, textureIndex, uv4, color };

    spriteCount++;
}

void drawQuad(const Rect& rect, const TextureRegion& region)
{
    drawQuad(rect, region, COLOR_WHITE);
}

void drawQuad(const Rect& rect, const Color& color)
{
    drawQuad(rect, {}, color);
}

void drawQuad(const Rect& rect)
{
    drawQuad(rect, COLOR_WHITE);
}

void drawText(const Point& pos,
              float lineHeight,
              const char* text,
              const Spritesheet& font,
              const Color& color)
{
    ASSERT(lineHeight > 0);
    ASSERT(text != nullptr);
    ASSERT(font.spriteWidth > 0);
    ASSERT(font.spriteHeight > 0);

    for (uint32_t i = 0; text[i] != '\0'; i++)
    {
        const float charWidth =
            (float(font.spriteWidth) / float(font.spriteHeight)) * lineHeight;
        const Rect rect = makeRect(
            pos.x + (i * charWidth),
            pos.y,
            charWidth,
            lineHeight);
        drawQuad(rect, getSpriteFor(font, text[i]), color);
    }
}

void drawText(const Point& pos,
              float lineHeight,
              const char* text,
              const Spritesheet& font)
{
    drawText(pos, lineHeight, text, font, COLOR_BLACK);
}

} // namespace caverneer
