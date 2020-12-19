include_directories(src)

add_executable(text_rendering src/main.cpp)
target_link_libraries(text_rendering
    PRIVATE core)

add_custom_target(copy_res_text_rendering ALL
    COMMAND rm -rf "${CMAKE_CURRENT_BINARY_DIR}/res"
    COMMAND cp -r "${CMAKE_CURRENT_SOURCE_DIR}/res"
                  "${CMAKE_CURRENT_BINARY_DIR}/res")
