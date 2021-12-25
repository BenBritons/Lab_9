cmake_minimum_required(VERSION 3.20)
project(Lab_9)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-main)

include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)


add_executable(Lab_9 main.cpp RationalNumber.h)
target_link_libraries(Lab_9 gtest gtest_main)