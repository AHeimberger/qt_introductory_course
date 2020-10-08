project(04_cmdline LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5
    COMPONENTS Core Network)

add_executable(04_cmdline
        "main.cpp")

target_link_libraries(04_cmdline
    PRIVATE Qt5::Core Qt5::Network businesslogiclib openweathermaplib)
