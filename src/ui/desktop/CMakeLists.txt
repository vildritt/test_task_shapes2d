cmake_minimum_required(VERSION 3.17)


project(shapes2d_gui_desktop
    VERSION 0.1
    DESCRIPTION "Shapes dekstop GUI app"
    LANGUAGES CXX)


set(SOURCES
    main.cpp
)


add_executable(shapes2d_gui_desktop
    ${SOURCES}
)


target_link_libraries(shapes2d_gui_desktop
    PRIVATE shapes2d_model
)
