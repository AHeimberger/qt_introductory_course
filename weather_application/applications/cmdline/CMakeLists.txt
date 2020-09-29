project(final_cmdline LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5
    COMPONENTS Core Network)

add_executable(final_cmdline
    main.cpp)

target_link_libraries(final_cmdline
    PRIVATE Qt5::Core Qt5::Network businesslogiclib openweathermaplib)
