#pragma once

namespace caverneer {

struct Rect;

void initRenderer();
void destroyRenderer();

void drawQuad(const Rect& rect);

} // namespace caverneer
