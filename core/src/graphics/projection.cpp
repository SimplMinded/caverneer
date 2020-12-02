#include "core/graphics/projection.h"

#include "core/math/matrix.h"

namespace caverneer {

Matrix makeOrthogonalProjectionMatrix(float left,
                                      float right,
                                      float bottom,
                                      float top,
                                      float near,
                                      float far)
{
    const float xScale = 2 / (right - left);
    const float xMove = (left + right) / (left - right);
    const float yScale = 2 / (top - bottom);
    const float yMove = (bottom + top) / (bottom - top);
    const float zScale = 2 / (near - far);
    const float zMove = (near + far) / (near - far);

    return makeMatrix(
        xScale, 0,      0,      xMove,
        0,      yScale, 0,      yMove,
        0,      0,      zScale, zMove,
        0,      0,      0,      1);
}

} // namespace caverneer
