cmake_minimum_required(VERSION 3.17)


project(shapes2d_gui_desktop_widgets
    VERSION 0.1
    DESCRIPTION "Shapes dekstop GUI app Widget based"
    LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)


set(SOURCES
    main.cpp
    #main_form_controller.cpp
    shapes2d/gui/main_window.cpp
    shapes2d/gui/plot_area_widget.cpp
)

set(HEADERS
    #main_form_controller.hpp
    #shapes2d/gui/plotter.hpp
    shapes2d/gui/main_window.hpp
    shapes2d/gui/plot_area_widget.hpp
)


add_executable(shapes2d_gui_desktop_widgets
    ${SOURCES}
    ${HEADERS}
)


# Qt
find_package(Qt6 6 COMPONENTS Gui Widgets REQUIRED)

target_link_libraries(shapes2d_gui_desktop_widgets
    PRIVATE
        Qt6::Gui Qt6::Widgets
        shapes2d_model
)


target_include_directories(shapes2d_gui_desktop_widgets
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)
