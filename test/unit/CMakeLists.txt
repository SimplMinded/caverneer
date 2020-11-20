project(unittests)

enable_testing()

add_subdirectory(core)

add_custom_target(unittests
    DEPENDS test_core)

add_custom_target(run_unittests
    DEPENDS run_test_core)
