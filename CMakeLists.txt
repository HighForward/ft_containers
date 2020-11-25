cmake_minimum_required(VERSION 3.15)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++98")

add_executable(ft_containers Map/Map.hpp Map/main.cpp)