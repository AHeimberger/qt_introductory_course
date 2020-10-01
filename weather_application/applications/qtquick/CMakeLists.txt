project(final_qtquick LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5
    COMPONENTS Quick Core Network REQUIRED)

add_executable(final_qtquick
    application.h application.cpp
    resources.qrc
    main.cpp)

target_link_libraries(final_qtquick
    PRIVATE Qt5::Quick Qt5::Core Qt5::Network businesslogiclib openweathermaplib)

add_custom_command(TARGET final_qtquick
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/update_l10n.sh ${CMAKE_CURRENT_BINARY_DIR}
    )
