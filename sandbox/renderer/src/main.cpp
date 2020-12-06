#include <core/debug/terminal.h>
#include <core/graphics/color.h>
#include <core/graphics/image.h>
#include <core/graphics/pixel.h>
#include <core/graphics/projection.h>
#include <core/graphics/rect.h>
#include <core/graphics/renderer.h>
#include <core/graphics/texture.h>
#include <core/graphics/texture_region.h>
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

    uint8_t data[16 * 16 * 4];
    Image image = makeImage(16, 16, data);
    for (uint32_t y = 0; y < 16; y++)
    for (uint32_t x = 0; x < 16; x++)
    {
        Pixel pixel;
        if (y < 4) pixel = makePixel(COLOR_RED);
        else if (y < 8) pixel = makePixel(COLOR_GREEN);
        else if (y < 12) pixel = makePixel(COLOR_BLUE);
        else pixel = makePixel(COLOR_YELLOW);
        setPixelAt(image, x, y, pixel);
    }

    Texture texture = createTexture(image);

    while (!shouldWindowClose())
    {
        beginRendering();
        enterView(view);
        drawQuad(makeRect(100, 100, 50, 50));
        exitView();
        drawQuad(makeRect(150, 150, 200, 200), COLOR_MAGENTA);
        drawQuad(makeRect(50, 200, 100, 100), makeTextureRegion(texture));
        drawQuad(makeRect(200, 50, 100, 100), makeTextureRegionFromPixels(texture, 0, 12, 3, 15), COLOR_GREEN);
        endRendering();
    }

    deleteTexture(texture);
    destroyRenderer();
    destroyWindow();
}
