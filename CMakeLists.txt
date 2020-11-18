cmake_minimum_required(VERSION 3.12)

project(caverneer)

set(CMAKE_CXX_STANDARD 17)
message(STATUS "Using C++${CMAKE_CXX_STANDARD}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")

add_subdirectory(game)
