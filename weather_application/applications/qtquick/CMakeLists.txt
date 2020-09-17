project(qtquick LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5
    COMPONENTS Quick Core Network)

add_executable(qtquick
    main.cpp
    application.h application.cpp
    resources.qrc)

target_link_libraries(qtquick
    PRIVATE Qt5::Quick Qt5::Core Qt5::Network businesslogiclib openweathermaplib)
