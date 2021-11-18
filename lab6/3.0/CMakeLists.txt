cmake_minimum_required(VERSION 3.16)

project(vector)
include_directories(include)

add_executable(vector src/main.cpp src/vector.cpp src/imaginary.cpp src/triangle.cpp src/node.cpp)
