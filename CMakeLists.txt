cmake_minimum_required(VERSION 3.13)

message(STATUS "Configuring vendor libraries")
add_subdirectory(vendor)

project(caverneer)
message(STATUS "Configuring main project")

set(CMAKE_CXX_STANDARD 17)
message(STATUS "Using C++${CMAKE_CXX_STANDARD}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")

message(STATUS "Configuring tests")
add_subdirectory(test)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Disable exceptions
    add_compile_options(-fno-exceptions)
    add_link_options(-fno-exceptions)
    message(STATUS "Disabled exception handling")
    
    # Disable rtti
    add_compile_options(-fno-rtti)
    add_link_options(-fno-rtti)
    message(STATUS "Disabled rtti")
    
    add_compile_options(-Wall)
else()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

add_subdirectory(core)

add_subdirectory(game)
add_subdirectory(sandbox)
