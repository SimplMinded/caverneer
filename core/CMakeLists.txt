include_directories(src)

add_library(core STATIC
    src/debug/assert.cpp
    src/debug/terminal.cpp
    src/graphics/color.cpp
    src/graphics/font.cpp
    src/graphics/gl_assert.cpp
    src/graphics/image.cpp
    src/graphics/pixel.cpp
    src/graphics/projection.cpp
    src/graphics/rect.cpp
    src/graphics/renderer.cpp
    src/graphics/spritesheet.cpp
    src/graphics/texture.cpp
    src/graphics/texture_region.cpp
    src/math/matrix.cpp
    src/math/point.cpp
    src/math/util.cpp
    src/math/vector.cpp
    src/util/error.cpp
    src/util/unreachable.cpp
    src/window.cpp)

target_include_directories(core
    PUBLIC include)

target_link_libraries(core
    PRIVATE glfw
            glad
            stb_image)
