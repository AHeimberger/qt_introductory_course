cmake_minimum_required(VERSION 3.14)

project(01_cpp_03_qt_ownership LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS REQUIRED Core)

add_executable(01_cpp_03_qt_ownership
    header.h
    main.cpp
)

target_link_libraries(01_cpp_03_qt_ownership Qt${QT_VERSION_MAJOR}::Core)
