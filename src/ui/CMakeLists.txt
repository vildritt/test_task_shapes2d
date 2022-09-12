add_subdirectory(qt_helper)
add_subdirectory(desktop_widgets)


set(S2D_BUILD_QML YES)
find_package(Qt6 COMPONENTS Quick QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS Quick QUIET)
    if(NOT Qt5_FOUND)
        set(S2D_BUILD_QML NO)
        message(STATUS "No QtQuick found, QML build DISABLED")
    endif()
endif()

if(S2D_BUILD_QML)
    add_subdirectory(desktop_qml)
endif()
