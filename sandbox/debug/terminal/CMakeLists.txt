include_directories(src)

add_executable(terminal src/main.cpp)
target_link_libraries(terminal
    PRIVATE core)
