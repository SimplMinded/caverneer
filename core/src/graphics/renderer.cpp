#include "core/graphics/renderer.h"

#include <cstddef>
#include <cstdint>

#include <glad/glad.h>

#include "core/graphics/color.h"
#include "core/graphics/rect.h"
#include "core/math/point.h"

namespace caverneer {

namespace {

constexpr const char* vertex_shader =
    "#version 400\n"
    "\n"
    "layout(location=0) in vec4 in_position;\n"
    "layout(location=1) in vec4 in_color;\n"
    "\n"
    "out vec4 vert_color;\n"
    "\n"
    "void main() {\n"
    "    gl_Position = in_position;\n"
    "    vert_color = in_color;\n"
    "}\n";

constexpr const char* fragment_shader =
    "#version 400\n"
    "\n"
    "in vec4 vert_color;\n"
    "\n"
    "out vec4 frag_color;\n"
    "\n"
    "void main() {\n"
    "    frag_color = vert_color;\n"
    "}\n";

uint32_t createShader(uint32_t type, const char* source)
{
    const uint32_t shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    return shader;
}

uint32_t vao;
uint32_t vbo;
uint32_t ibo;
uint32_t program;

struct Vertex
{
    Point position;
    Color color;
};

constexpr uint32_t max_sprite_count = 10000;

Vertex vertices[4 * max_sprite_count];
uint32_t spriteCount;

} // namespace

void initRenderer()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, color)));

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    const uint32_t vertexShader = createShader(GL_VERTEX_SHADER, vertex_shader);
    const uint32_t fragmentShader = createShader(GL_FRAGMENT_SHADER, fragment_shader);
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glUseProgram(program);

    glBufferData(GL_ARRAY_BUFFER, 4 * max_sprite_count * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * max_sprite_count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    delete[] indices;
}

void destroyRenderer()
{
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void beginRendering()
{
    spriteCount = 0;
}

void endRendering()
{
    glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * spriteCount * sizeof(Vertex), vertices);
    glDrawElements(GL_TRIANGLES, 6 * spriteCount, GL_UNSIGNED_INT, 0);
}

void drawQuad(const Rect& rect, const Color& color)
{
    const float x1 = rect.x;
    const float x2 = rect.x + rect.width;
    const float y1 = rect.y;
    const float y2 = rect.y + rect.height;
    vertices[(spriteCount * 4) + 0] = Vertex{ makePoint(x1, y1), color };
    vertices[(spriteCount * 4) + 1] = Vertex{ makePoint(x1, y2), color };
    vertices[(spriteCount * 4) + 2] = Vertex{ makePoint(x2, y2), color };
    vertices[(spriteCount * 4) + 3] = Vertex{ makePoint(x2, y1), color };
    spriteCount++;
}

void drawQuad(const Rect& rect)
{
    drawQuad(rect, COLOR_WHITE);
}

} // namespace caverneer
