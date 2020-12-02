#pragma once

namespace caverneer {

struct Color;
union Matrix;
struct Rect;

void initRenderer();
void destroyRenderer();

void beginRendering(const Matrix& viewProjection);
void endRendering();

void drawQuad(const Rect& rect, const Color& color);
void drawQuad(const Rect& rect);

} // namespace caverneer
