include_directories(src)

add_executable(renderer src/main.cpp)
target_link_libraries(renderer
    PRIVATE core
            glad)
