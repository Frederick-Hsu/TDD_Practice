cmake_minimum_required(VERSION 3.23)

project(UTest4GUI LANGUAGES CXX)
find_package(Qt6Test REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
enable_testing(true)

add_executable(UTest4GUI tst_testgui.cpp)
add_test(NAME UTest4GUI COMMAND UTest4GUI)
target_link_libraries(UTest4GUI PRIVATE Qt6::Test)