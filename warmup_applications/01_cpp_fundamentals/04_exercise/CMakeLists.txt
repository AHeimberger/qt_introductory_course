cmake_minimum_required(VERSION 3.14)

project(04_exercise LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(04_exercise
    main.cpp
)

target_link_libraries(04_exercise Qt${QT_VERSION_MAJOR}::Core)
