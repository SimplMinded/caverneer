#pragma once

namespace caverneer {

struct Color;
union Matrix;
struct Rect;

void initRenderer(const Matrix& projection);
void destroyRenderer();

void beginRendering();
void endRendering();

void enterView(const Matrix& view);
void exitView();

void drawQuad(const Rect& rect, const Color& color);
void drawQuad(const Rect& rect);

} // namespace caverneer
