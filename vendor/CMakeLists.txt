message(STATUS "Configuring GLFW")
add_subdirectory(glfw EXCLUDE_FROM_ALL)

message(STATUS "Configuring GLAD")
add_subdirectory(glad)

message(STATUS "Configuring stb_image")
add_subdirectory(stb_image)

message(STATUS "Configuring Catch")
add_subdirectory(catch)
