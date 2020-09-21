project(businesslogiclib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set(YOUR_OPENWEATHERMAP_APPID "YOUR_OPPENWEATHERMAP_APPID" CACHE STRING "Add your open weathermap appid")

find_package(Qt5
    COMPONENTS Core Network REQUIRED)

add_library(businesslogiclib SHARED
    include/settings.h source/settings.cpp
    include/model_today.h source/model_today.cpp
    include/model_forecast.h source/model_forecast.cpp
    include/weather_controller.h source/weather_controller.cpp)

target_sources(businesslogiclib
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include/settings.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/model_today.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/model_forecast.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/weather_controller.h")

target_include_directories(businesslogiclib
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(businesslogiclib
    PRIVATE Qt5::Core Qt5::Network openweathermaplib)

target_compile_definitions(businesslogiclib
    PUBLIC OPENWEATHERMAP_APPID="${YOUR_OPENWEATHERMAP_APPID}")
