#include "core/graphics/color.h"

namespace caverneer {

Color makeColor(float r, float g, float b, float a)
{
    return Color{ r, g, b, a };
}

Color makeColor(float r, float g, float b)
{
    return makeColor(r, g, b, 1.0f);
}

} // namespace caverneer
