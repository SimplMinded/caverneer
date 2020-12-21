#include <core/debug/terminal.h>
#include <core/graphics/color.h>
#include <core/graphics/image.h>
#include <core/graphics/projection.h>
#include <core/graphics/rect.h>
#include <core/graphics/renderer.h>
#include <core/graphics/spritesheet.h>
#include <core/math/matrix.h>
#include <core/math/point.h>
#include <core/util/error.h>
#include <core/util/filesystem.h>
#include <core/util/string_view.h>
#include <core/window.h>

using namespace caverneer;

int main(int argc, char* argv[])
{
    const Error workingDirError = setWorkingDir(getParentDir(argv[0]));
    if (isError(workingDirError))
    {
        debugPrint("Changing working directory failed: %s", workingDirError.message);
        return 1;
    }

    const Error windowError = createWindow(720, 480, "Hello, text!");
    if (isError(windowError))
    {
        debugPrint("Window creation failed: %s", windowError.message);
        return 1;
    }

    const Matrix projection = makeOrthogonalProjectionMatrix(0,
                                                             720,
                                                             0,
                                                             480,
                                                             -1,
                                                             1);
    initRenderer(projection);

    Spritesheet font = loadSpritesheet("res/font/oldschool.png", 7, 9);

    while (!shouldWindowClose())
    {
        beginRendering();
        drawQuad(makeRect(100, 100, 520, 20));
        drawText(makePoint(100, 100), 20, "Hello,     !", font);
        drawText(makePoint(100, 100), 20, "       Text", font, COLOR_RED);
        endRendering();
    }

    deleteSpritesheet(font);
    destroyRenderer();
    destroyWindow();
}
