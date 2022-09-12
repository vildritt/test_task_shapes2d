cmake_minimum_required(VERSION 3.16)


project(shapes2d_tests
    VERSION 0.1
    DESCRIPTION "Shapes tests"
    LANGUAGES CXX)


# Qt
find_package(Qt6 COMPONENTS Test QUIET)
if (Qt6_FOUND)
    set(QT_COMPONENTS Qt6::Test)
else()
    find_package(Qt5 COMPONENTS Test REQUIRED)
    set(QT_COMPONENTS Qt5::Test)
endif()


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(shapes2d_test_mso
    test_model_simple_operations.cpp)

target_link_libraries(shapes2d_test_mso
    PRIVATE ${QT_COMPONENTS} shapes2d_model)

add_test(NAME "model simple operations" COMMAND shapes2d_test_mso)
