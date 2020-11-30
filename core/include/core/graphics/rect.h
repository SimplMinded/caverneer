#pragma once

namespace caverneer {

struct Rect
{
    float x;
    float y;
    float width;
    float height;
};

Rect makeRect(float x, float y, float width, float height);

} // namespace caverneer
