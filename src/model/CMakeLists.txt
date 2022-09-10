cmake_minimum_required(VERSION 3.17)

project(shapes2d_model
    VERSION 0.1
    DESCRIPTION "Shapes model and UI app"
    LANGUAGES CXX)


set(SOURCES
    model.cpp
    shape.cpp
    plotter.cpp
    vector2d.cpp
    color.cpp
    scene_composer.cpp
    shape_meta_info.cpp
    shapes_registry.cpp
    shapes/triangle.cpp
    shapes/circle.cpp
    shapes/rectangle.cpp
)


set(HEADERS_PUBLIC
    include/shapes2d/misc.hpp
    include/shapes2d/color.hpp
    include/shapes2d/model.hpp
    include/shapes2d/model_ptr.hpp
    include/shapes2d/plotter.hpp
    include/shapes2d/vector2d.hpp
    include/shapes2d/scene_composer.hpp
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
    "${CMAKE_CURRENT_BINARY_DIR}/include/shapes2d/export.h"
)


add_library(shapes2d_model
    ${SOURCES}
    ${HEADERS_PRIVATE}
    ${HEADERS_PUBLIC}
)


target_include_directories(shapes2d_model
    PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_BINARY_DIR}/include"
)


include(GenerateExportHeader)
generate_export_header(shapes2d_model EXPORT_FILE_NAME include/shapes2d/export.h)
