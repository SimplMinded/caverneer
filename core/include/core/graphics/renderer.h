#pragma once

namespace caverneer {

struct Color;
union Matrix;
struct Point;
struct Rect;
struct Spritesheet;
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

void drawText(const Point& pos,
              float lineHeight,
              const char* text,
              const Spritesheet& font,
              const Color& color);
void drawText(const Point& pos,
              float lineHeight,
              const char* text,
              const Spritesheet& font);

} // namespace caverneer
