cmake_minimum_required(VERSION 3.26)
project(Complex_numbers)

set(CMAKE_CXX_STANDARD 23)

add_executable(Complex_numbers main.cpp
        basic_operations.cpp
        io_complex_numbers.cpp)
