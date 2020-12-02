#pragma once

namespace caverneer {

union Matrix;

Matrix makeOrthogonalProjectionMatrix(float left,
                                      float right,
                                      float bottom,
                                      float top,
                                      float near,
                                      float far);

} // namespace caverneer
