add_executable(test_core
    src/graphics/test_image.cpp
    src/graphics/test_pixel.cpp
    src/math/test_matrix.cpp
    src/math/test_max.cpp
    src/math/test_min.cpp
    src/math/test_point.cpp
    src/math/test_vector.cpp
    src/util/test_error.cpp)

target_link_libraries(test_core
    PRIVATE core
            catch)

add_test(NAME test_core COMMAND test_core)

add_custom_target(run_test_core
    COMMAND ctest
    DEPENDS test_core)
