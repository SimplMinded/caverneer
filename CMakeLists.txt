cmake_minimum_required(VERSION 3.12)

project(caverneer)

set(CMAKE_CXX_STANDARD 17)
message(STATUS "Using C++${CMAKE_CXX_STANDARD}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall)
else()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

add_subdirectory(game)
