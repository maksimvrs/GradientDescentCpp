cmake_minimum_required(VERSION 3.12)
project(GradientDescentCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.,)

add_executable(GradientDescentCpp
        src/GradientDescent.cpp
        src/GradientDescent.hpp
        main.cpp)
