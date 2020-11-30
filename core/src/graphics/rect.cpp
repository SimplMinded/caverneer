#include "core/graphics/rect.h"

#include "core/debug/assert.h"

namespace caverneer {

Rect makeRect(float x, float y, float width, float height)
{
    ASSERT(width > 0);
    ASSERT(height > 0);

    return Rect{ x, y, width, height };
}

} // namespace caverneer
