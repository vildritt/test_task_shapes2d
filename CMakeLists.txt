cmake_minimum_required(VERSION 3.17)

project(shapes2d_task
    VERSION 0.1
    DESCRIPTION "Shapes model and UI app"
    LANGUAGES CXX)

add_subdirectory(src)

if(NOT DEFINED SHAPES_TESTS_DISABLED)
    enable_testing()
    add_subdirectory(test)
endif()
