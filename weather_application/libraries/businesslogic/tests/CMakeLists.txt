# well check this page:
# https://doc.qt.io/qt-5/qtest-overview.html

project(tests_businesslogic LANGUAGES CXX)

find_package(Qt5
    COMPONENTS Core Test Network REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing(true)

add_executable(tests_businesslogic
    test_model_today.h test_model_today.cpp
    main.cpp)

add_test(NAME tests_businesslogic
    COMMAND tests_businesslogic
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tests_businesslogic
    PRIVATE Qt5::Core Qt5::Test Qt5::Network openweathermaplib)
