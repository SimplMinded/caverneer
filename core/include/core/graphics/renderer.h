#pragma once

namespace caverneer {

struct Rect;

void initRenderer();
void destroyRenderer();

void beginRendering();
void endRendering();

void drawQuad(const Rect& rect);

} // namespace caverneer
