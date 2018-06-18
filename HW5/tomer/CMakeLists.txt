cmake_minimum_required(VERSION 3.3)
project(hw5_clion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES main.cpp registers.cpp stack.cpp output.cpp helpers.cpp bp.cpp parser.hpp)
add_executable(hw5_clion ${SOURCE_FILES})