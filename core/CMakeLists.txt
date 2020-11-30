include_directories(src)

add_library(core STATIC
    src/debug/assert.cpp
    src/debug/terminal.cpp
    src/graphics/color.cpp
    src/graphics/rect.cpp
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
            glad)
