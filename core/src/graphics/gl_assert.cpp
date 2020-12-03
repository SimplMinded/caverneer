#include "graphics/gl_assert.h"

#include <cstdlib>

#include <glad/glad.h>

#include "core/debug/terminal.h"
#include "core/util/unreachable.h"

namespace caverneer::detail {

namespace {

const char* getErrorMessage(GLenum error)
{
    switch (error)
    {
        case GL_NO_ERROR:
            return "No error";
        case GL_INVALID_ENUM:
            return "Invalid enum";
        case GL_INVALID_VALUE:
            return "Invalid value";
        case GL_INVALID_OPERATION:
            return "Invalid operation";
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            return "Invalid framebuffer operation";
        case GL_OUT_OF_MEMORY:
            return "Out of memory";
        case GL_STACK_UNDERFLOW:
            return "Stack underflow";
        case GL_STACK_OVERFLOW:
            return "Stack overflow";
        default:
            UNREACHABLE("Unexpected OpenGL error: %u", error);
    }
}

} // namespace

void flushGlErrors()
{
    while (glGetError() != GL_NO_ERROR);
}

void glAssert(const char* file, uint64_t line, const char* statement)
{
    const GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        debugPrint("[GL_ASSERT] %s:%lu \"%s (%s)\"",
                   file,
                   line,
                   statement,
                   getErrorMessage(error));
        abort();
    }
}

} // namespace caverneer::detail
