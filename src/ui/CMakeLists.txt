add_subdirectory(qt_helper)
add_subdirectory(desktop_widgets)

find_package(Qt6 COMPONENTS Core)
if (Qt6_FOUND)
    # TODO 0: impl for Qt5
    add_subdirectory(desktop_qml)
endif()

