#include <cstdio>

#include <glad/glad.h>

#include <core/debug/terminal.h>
#include <core/window.h>

using namespace caverneer;

int main()
{
    if (!createWindow(720, 480, "Hello, World!"))
    {
        debugPrint("Window creation failed!");
        return 1;
    }

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    while (!shouldWindowClose())
    {
        updateWindow();
    }

    destroyWindow();
}
