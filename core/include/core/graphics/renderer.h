#pragma once

namespace caverneer {

struct Color;
union Matrix;
struct Rect;
struct TextureRegion;

void initRenderer(const Matrix& projection);
void destroyRenderer();

void beginRendering();
void endRendering();

void enterView(const Matrix& view);
void exitView();

void drawQuad(const Rect& rect,
              const TextureRegion& region,
              const Color& color);
void drawQuad(const Rect& rect, const TextureRegion& region);
void drawQuad(const Rect& rect, const Color& color);
void drawQuad(const Rect& rect);

} // namespace caverneer
