cmake_minimum_required(VERSION 3.17)
project(P1_Quicksort)

set(CMAKE_CXX_STANDARD 14)

add_executable(P1_Quicksort main.cpp)

include_directories(Sorts)
add_subdirectory(Sorts)

target_link_libraries(P1_Quicksort Sorts)

add_subdirectory(Google_tests)