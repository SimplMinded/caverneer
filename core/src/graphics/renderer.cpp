#include "core/graphics/renderer.h"

#include <cstdint>

#include <glad/glad.h>

#include "core/graphics/rect.h"

namespace caverneer {

namespace {

constexpr const char* vertex_shader =
    "#version 400\n"
    "\n"
    "layout(location=0) in vec4 in_position;\n"
    "\n"
    "void main() {\n"
    "    gl_Position = in_position;\n"
    "}\n";

constexpr const char* fragment_shader =
    "#version 400\n"
    "\n"
    "out vec4 frag_color;\n"
    "\n"
    "void main() {\n"
    "    frag_color = vec4(1, 1, 1, 1);\n"
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

} // namespace

void initRenderer()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

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

    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);

    const uint32_t indices[6] = {
        0, 1, 2,
        0, 2, 3
    };
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indices, GL_STATIC_DRAW);
}

void destroyRenderer()
{
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void drawQuad(const Rect& rect)
{
    const float x1 = rect.x;
    const float x2 = rect.x + rect.width;
    const float y1 = rect.y;
    const float y2 = rect.y + rect.height;
    const float vertices[4 * 2] = {
        x1, y1,
        x1, y2,
        x2, y2,
        x2, y1
    };
    glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * 2 * sizeof(float), vertices);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

} // namespace caverneer
