message(STATUS "Configuring unit tests")
add_subdirectory(unit)

add_custom_target(test
    DEPENDS run_unittests)
