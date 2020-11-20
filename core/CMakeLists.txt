include_directories(src)

add_library(core STATIC
    src/debug/assert.cpp
    src/debug/terminal.cpp
    src/math/util.cpp
    src/util/error.cpp
    src/window.cpp)

target_include_directories(core
    PUBLIC include)

target_link_libraries(core
    PRIVATE glfw
            glad)
