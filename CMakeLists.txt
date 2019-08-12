cmake_minimum_required(VERSION 3.13)
project(A4_handout)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A4_handout
        a4.cpp
        a4.hpp
        symbol.hpp)
