cmake_minimum_required(VERSION 3.17)

project(shapes_model
    VERSION 0.1
    DESCRIPTION "Shapes model and UI app"
    LANGUAGES CXX)


set(SOURCES
    model.cpp
)


set(HEADERS_PRIVATE
    include/shapes/model.hpp
)


set(HEADERS_PRIVATE
)


add_library(shapes_model
    ${SOURCES}
    ${HEADERS_PRIVATE}
    ${HEADERS_PUBLIC}
)


target_include_directories(shapes_model
    PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC   ${CMAKE_CURRENT_SOURCE_DIR}/include
)
