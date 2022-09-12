cmake_minimum_required(VERSION 3.17)


project(shapes2d_gui_qt_helper
    VERSION 0.1
    DESCRIPTION "Shapes GUI qt helper"
    LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)


set(SOURCES
    src/painter_plotter.cpp
)

set(HEADERS
    include/shapes2d/gui/qt_helper/painter_plotter.hpp
)


add_library(shapes2d_gui_qt_helper
    ${SOURCES}
    ${HEADERS}
)


# Qt
find_package(Qt6 COMPONENTS Gui QUIET)
if (Qt6_FOUND)
    set(QT_COMPONENTS Qt6::Gui)
else()
    find_package(Qt5 COMPONENTS Gui REQUIRED)
    set(QT_COMPONENTS Qt5::Gui)
endif()


target_link_libraries(shapes2d_gui_qt_helper
    PUBLIC
        ${QT_COMPONENTS}    
        shapes2d_model
)


target_include_directories(shapes2d_gui_qt_helper
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
