cmake_minimum_required(VERSION 3.8)
project(lab_05)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(lab_05 ${SOURCE_FILES})
target_link_libraries(lab_05 m)
set(CMAKE_C_FLAGS -pedantic-errors)