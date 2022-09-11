cmake_minimum_required(VERSION 3.17)


project(shapes2d_gui_desktop_widgets
    VERSION 0.1
    DESCRIPTION "Shapes dekstop GUI app Widget based"
    LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)


set(SOURCES
    main.cpp
    shapes2d/gui/main_window.cpp
    shapes2d/gui/plot_area_widget.cpp
)

set(HEADERS
    shapes2d/gui/main_window.hpp
    shapes2d/gui/plot_area_widget.hpp
)


add_executable(shapes2d_gui_desktop_widgets
    ${SOURCES}
    ${HEADERS}
)


# Qt
find_package(Qt6 COMPONENTS Gui Widgets)
if (Qt6_FOUND)
    set(QT_COMPONENTS Qt6::Gui Qt6::Widgets)
else()
    find_package(Qt5 COMPONENTS Gui Widgets REQUIRED)
    set(QT_COMPONENTS Qt5::Gui Qt5::Widgets)
endif()

target_link_libraries(shapes2d_gui_desktop_widgets
    PRIVATE
        ${QT_COMPONENTS}
        shapes2d_model
        shapes2d_gui_qt_helper
)


target_include_directories(shapes2d_gui_desktop_widgets
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)
