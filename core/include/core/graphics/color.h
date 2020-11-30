#pragma once

namespace caverneer {

struct Color
{
    float r;
    float g;
    float b;
    float a;
};

constexpr Color COLOR_BLACK   = Color{ 0.0f, 0.0f, 0.0f, 1.0f };
constexpr Color COLOR_BLUE    = Color{ 0.0f, 0.0f, 1.0f, 1.0f };
constexpr Color COLOR_CYAN    = Color{ 0.0f, 1.0f, 1.0f, 1.0f };
constexpr Color COLOR_GREEN   = Color{ 0.0f, 1.0f, 0.0f, 1.0f };
constexpr Color COLOR_MAGENTA = Color{ 1.0f, 0.0f, 1.0f, 1.0f };
constexpr Color COLOR_RED     = Color{ 1.0f, 0.0f, 0.0f, 1.0f };
constexpr Color COLOR_YELLOW  = Color{ 1.0f, 1.0f, 0.0f, 1.0f };
constexpr Color COLOR_WHITE   = Color{ 1.0f, 1.0f, 1.0f, 1.0f };

Color makeColor(float r, float g, float b, float a);
Color makeColor(float r, float g, float b);

} // namespace caverneer
