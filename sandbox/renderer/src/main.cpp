#include <glad/glad.h>

#include <core/debug/terminal.h>
#include <core/graphics/renderer.h>
#include <core/util/error.h>
#include <core/window.h>

using namespace caverneer;

int main()
{
    const Error error = createWindow(720, 480, "Hello, Triangle!");
    if (isError(error))
    {
        debugPrint("Window creation failed: %s", error.message);
        return 1;
    }

    initRenderer();

    while (!shouldWindowClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        render();
        updateWindow();
    }

    destroyRenderer();
    destroyWindow();
}
