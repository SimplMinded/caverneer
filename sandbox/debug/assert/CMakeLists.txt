include_directories(src)

add_executable(assert src/main.cpp)
target_link_libraries(assert
    PRIVATE core)
