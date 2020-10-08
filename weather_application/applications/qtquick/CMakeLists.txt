project(04_qtquick LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5
    COMPONENTS Quick Core Network REQUIRED)

add_executable(04_qtquick
        "main.cpp"
        "resources.qrc"
        "application.h"
        "application.cpp")

target_link_libraries(04_qtquick
    PRIVATE Qt5::Quick Qt5::Core Qt5::Network businesslogiclib openweathermaplib)

add_custom_command(TARGET 04_qtquick
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/update_l10n.sh ${CMAKE_CURRENT_BINARY_DIR}
    )
