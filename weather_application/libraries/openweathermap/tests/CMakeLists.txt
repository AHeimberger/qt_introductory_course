project(04_tests_openweathermap LANGUAGES CXX)

find_package(Qt5
    COMPONENTS Core Test Network REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing(true)

add_executable(04_tests_openweathermap
        "test_requests.h"
        "test_requests.cpp"
        "test_replies.h"
        "test_replies.cpp"
        "main.cpp"
        "resources.qrc")

add_test(NAME 04_tests_openweathermap
    COMMAND 04_tests_openweathermap
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(04_tests_openweathermap
    PRIVATE Qt5::Core Qt5::Test Qt5::Network openweathermaplib)
