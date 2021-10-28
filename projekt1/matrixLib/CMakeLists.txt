cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(matrixLib STATIC src/matrix.cpp)
