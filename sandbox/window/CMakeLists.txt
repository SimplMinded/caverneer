include_directories(src)

add_executable(window src/main.cpp)
target_link_libraries(window
    PRIVATE core
            glad)
