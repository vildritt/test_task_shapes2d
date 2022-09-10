cmake_minimum_required(VERSION 3.17)

project(shapes2d_model
    VERSION 0.1
    DESCRIPTION "Shapes model and UI app"
    LANGUAGES CXX)


set(SOURCES
    model.cpp
    shape.cpp
    plotter.cpp
    shape_meta_info.cpp
    shapes_registry.cpp
    shapes/triangle.cpp
    shapes/circle.cpp
    shapes/rectangle.cpp
)


set(HEADERS_PUBLIC
    include/shapes2d/misc.hpp
    include/shapes2d/model.hpp
    include/shapes2d/plotter.hpp
    include/shapes2d/shape.hpp
    include/shapes2d/shape_meta_info.hpp
    include/shapes2d/shapes_registry.hpp
    include/shapes2d/shapes.hpp
    include/shapes2d/shapes/triangle.hpp
    include/shapes2d/shapes/circle.hpp
    include/shapes2d/shapes/rectangle.hpp
)


set(HEADERS_PRIVATE
    shapes_registry.hpp
)


add_library(shapes2d_model
    ${SOURCES}
    ${HEADERS_PRIVATE}
    ${HEADERS_PUBLIC}
)


target_include_directories(shapes2d_model
    PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC   ${CMAKE_CURRENT_SOURCE_DIR}/include
)
