cmake_minimum_required(VERSION 2.8)

project(containers)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

file(GLOB containers)

add_executable(module ${containers} main.cpp vector.hpp)