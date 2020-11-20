#pragma once

#include <cstdint>

namespace caverneer {

struct Error;

Error createWindow(uint32_t width, uint32_t height, const char* title);
void destroyWindow();

void updateWindow();

bool shouldWindowClose();

} // namespace caverneer
