cmake_minimum_required(VERSION 3.10)

project(robot)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

