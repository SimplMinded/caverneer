#include <cstdio>

#include <glad/glad.h>

#include <core/debug/terminal.h>
#include <core/util/error.h>
#include <core/window.h>

using namespace caverneer;

int main()
{
    const Error error = createWindow(720, 480, "Hello, World!");
    if (isError(error))
    {
        debugPrint(error.message);
        return 1;
    }

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    while (!shouldWindowClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        updateWindow();
    }

    destroyWindow();
}
