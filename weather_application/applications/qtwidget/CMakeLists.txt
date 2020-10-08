project(04_qtwidget LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5
    COMPONENTS Widgets Core Network Svg)

add_executable(04_qtwidget
        "main.cpp"
        "main_window.h"
        "main_window.cpp"
        "label_aspect_ratio.h"
        "label_aspect_ratio.cpp"
        "widget_settings.h"
        "widget_settings.cpp"
        "widget_content.h"
        "widget_content.cpp"
        "widget_today.h"
        "widget_today.cpp"
        "widget_forecast_item.h"
        "widget_forecast_item.cpp"
        "style_sheet.h"
        "style_sheet.cpp"
        "resources.qrc")

target_link_libraries(04_qtwidget
    PRIVATE Qt5::Widgets Qt5::Core Qt5::Network Qt5::Svg businesslogiclib openweathermaplib)

option(GRAPHICAL_DEBUG "Adds additional widget information for graphical debugging ON/OFF" OFF)
if(GRAPHICAL_DEBUG)
    ADD_DEFINITIONS(-DGRAPHICAL_DEBUG)
endif(GRAPHICAL_DEBUG)
unset(GRAPHICAL_DEBUG CACHE)
