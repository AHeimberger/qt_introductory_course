project(04_tests_businesslogic LANGUAGES CXX)

find_package(Qt5
    COMPONENTS Core Test Network REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing(true)

add_executable(04_tests_businesslogic
        "test_model_today.h"
        "test_model_today.cpp"
        "main.cpp")

add_test(NAME 04_tests_businesslogic
    COMMAND 04_tests_businesslogic
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(04_tests_businesslogic
    PRIVATE Qt5::Core Qt5::Test Qt5::Network openweathermaplib)
