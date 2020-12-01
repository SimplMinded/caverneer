#pragma once

namespace caverneer {

struct Color;
struct Rect;

void initRenderer();
void destroyRenderer();

void beginRendering();
void endRendering();

void drawQuad(const Rect& rect, const Color& color);
void drawQuad(const Rect& rect);

} // namespace caverneer
