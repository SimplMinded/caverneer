include_directories(src)

add_library(core STATIC src/window.cpp)

target_include_directories(core
    PUBLIC include)

target_link_libraries(core
    PRIVATE glfw
            glad)
