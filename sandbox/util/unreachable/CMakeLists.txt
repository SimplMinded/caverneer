include_directories(src)

add_executable(unreachable src/main.cpp)
target_link_libraries(unreachable
    PRIVATE core)
