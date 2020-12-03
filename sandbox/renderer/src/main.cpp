#include <glad/glad.h>

#include <core/debug/terminal.h>
#include <core/graphics/color.h>
#include <core/graphics/projection.h>
#include <core/graphics/rect.h>
#include <core/graphics/renderer.h>
#include <core/math/matrix.h>
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

    const Matrix projection = makeOrthogonalProjectionMatrix(0,
                                                             720,
                                                             0,
                                                             480,
                                                             -1,
                                                             1);
    initRenderer(projection);

    const Matrix view = makeMatrix(1, 0, 0, -50,
                                   0, 1, 0, -50,
                                   0, 0, 1,   0,
                                   0, 0, 0,   1);

    while (!shouldWindowClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        beginRendering();
        enterView(view);
        drawQuad(makeRect(100, 100, 50, 50));
        exitView();
        drawQuad(makeRect(150, 150, 200, 200), COLOR_MAGENTA);
        endRendering();
        updateWindow();
    }

    destroyRenderer();
    destroyWindow();
}
