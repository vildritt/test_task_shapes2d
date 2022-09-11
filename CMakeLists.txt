cmake_minimum_required(VERSION 3.17)

project(shapes2d_task
    VERSION 0.1
    DESCRIPTION "Shapes model and UI app"
    LANGUAGES CXX)

# global setup

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK    ccache)
endif(CCACHE_FOUND)

# sub projects

add_subdirectory(src)

if(NOT DEFINED SHAPES_TESTS_DISABLED)
    enable_testing()
    add_subdirectory(test)
endif()

# docs

add_custom_target(shapes2d-docs
    SOURCES
        README.md
        TODO
)
