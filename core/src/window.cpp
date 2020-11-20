#include "core/window.h"

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "core/debug/assert.h"
#include "core/util/error.h"

namespace caverneer {

static GLFWwindow* window = nullptr;

Error createWindow(uint32_t width, uint32_t height, const char* title)
{
    ASSERT(width <= uint32_t(INT32_MAX));
    ASSERT(height <= uint32_t(INT32_MAX));
    ASSERT(title != nullptr);

    if (!glfwInit())
    {
        return makeError("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(int32_t(width), int32_t(height), title, nullptr, nullptr);
    if (window == nullptr)
    {
        glfwTerminate();
        return makeError("Failed to create window");
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
    {
        glfwTerminate();
        return makeError("Failed to initialize GLAD");;
    }

    return makeSuccess();
}

void destroyWindow()
{
    ASSERT(window != nullptr);

    glfwTerminate();
}

void updateWindow()
{
    ASSERT(window != nullptr);

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool shouldWindowClose()
{
    ASSERT(window != nullptr);

    return glfwWindowShouldClose(window);
}

} // namespace caverneer
