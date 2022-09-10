cmake_minimum_required(VERSION 3.17)


project(shapes2d_tests
    VERSION 0.1
    DESCRIPTION "Shapes tests"
    LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(shapes2d_test_mso
    test_model_simple_operations.cpp)

target_link_libraries(shapes2d_test_mso
    PRIVATE Qt::Test shapes2d_model)

add_test(NAME "model simple operations" COMMAND shapes2d_test_mso)
