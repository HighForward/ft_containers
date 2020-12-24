cmake_minimum_required(VERSION 3.15)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
set (CMAKE_CXX_FLAGS "-std=c++98")

add_executable(ft_containers List/main.cpp List/List.hpp Vector/VectorIterator.hpp List/ListIterator.hpp)