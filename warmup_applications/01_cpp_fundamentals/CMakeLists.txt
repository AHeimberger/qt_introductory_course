cmake_minimum_required(VERSION 3.14)
project(weather_application)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(00_meta_object)
add_subdirectory(01_qt_core_signal_slots)
add_subdirectory(02_qt_core_properties)
# add_subdirectory(03_method_invocation) # Q_SLOT, Q_INVOKABLE
add_subdirectory(03_qt_ownership)
add_subdirectory(04_exercise)


