project(openweathermaplib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

find_package(Qt5
    COMPONENTS Core Network REQUIRED)

add_library(openweathermaplib SHARED
    include/icon_mappings.h source/icon_mappings.cpp
    include/requests.h source/requests.cpp
    include/replies.h source/replies.cpp)

target_sources(openweathermaplib
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include/icon_mappings.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/requests.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/replies.h")

target_include_directories(openweathermaplib
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(openweathermaplib
    PRIVATE Qt5::Core Qt5::Network)

target_compile_definitions(openweathermaplib
    PUBLIC OPENWEATHERMAP_LIBRARY_VERSION="1.0.0")
