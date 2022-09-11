cmake_minimum_required(VERSION 3.17)


project(shapes2d_gui_desktop_qml
    VERSION 0.1
    DESCRIPTION "Shapes dekstop GUI app QML based"
    LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)


set(SOURCES
    main.cpp
    shapes2d/gui/quick_plot_area.cpp
    shapes2d/gui/main_window_controller.cpp
)

set(HEADERS
    shapes2d/gui/quick_plot_area.hpp
    shapes2d/gui/main_window_controller.hpp
)


add_executable(shapes2d_gui_desktop_qml
    ${SOURCES}
    ${HEADERS}
)


# Qt
find_package(Qt6 COMPONENTS Quick Gui)
if (Qt6_FOUND)
    qt_add_qml_module(shapes2d_gui_desktop_qml
        URI shapes2d
        VERSION 0.1
        QML_FILES
            main.qml
    )
    set(QT_COMPONENTS Qt6::Gui Qt6::Quick)
else()
    find_package(Qt5 COMPONENTS Widgets Quick Qml REQUIRED)
    set(QT_COMPONENTS Qt5::Widgets Qt5::Qml Qt5::Quick)
endif()


target_link_libraries(shapes2d_gui_desktop_qml
    PRIVATE
        ${QT_COMPONENTS}
        shapes2d_model
        shapes2d_gui_qt_helper
)


target_include_directories(shapes2d_gui_desktop_qml
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)
