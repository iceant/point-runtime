cmake_minimum_required(VERSION 2.8)
project(point_runtime C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_library(point_runtime pr_types.c)

include(test.cmake)