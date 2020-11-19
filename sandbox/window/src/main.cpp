#include <cstdio>

#include <glad/glad.h>

#include <core/window.h>

using namespace caverneer;

int main()
{
    createWindow(720, 480, "Hello, World!");

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    while (!shouldWindowClose())
    {
        updateWindow();
    }

    destroyWindow();
}
