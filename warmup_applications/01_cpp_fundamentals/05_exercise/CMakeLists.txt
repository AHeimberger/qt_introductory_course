cmake_minimum_required(VERSION 3.14)

project(01_cpp_05_exercise LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS REQUIRED Core)

add_executable(01_cpp_05_exercise
    main.cpp
    header.h
)

target_link_libraries(01_cpp_05_exercise Qt${QT_VERSION_MAJOR}::Core)
