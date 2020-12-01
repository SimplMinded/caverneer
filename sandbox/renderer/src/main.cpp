#include <glad/glad.h>

#include <core/debug/terminal.h>
#include <core/graphics/rect.h>
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
        drawQuad(makeRect(-0.5f, -0.5f, 1.0f, 1.0f));
        updateWindow();
    }

    destroyRenderer();
    destroyWindow();
}
