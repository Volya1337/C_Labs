cmake_minimum_required(VERSION 3.8)
project(lab_08)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(lab_08 ${SOURCE_FILES})
target_link_libraries(lab_08 m)
target_link_libraries(lab_08 -fopenmp)
