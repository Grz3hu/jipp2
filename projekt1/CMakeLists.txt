cmake_minimum_required(VERSION 3.16)
project(matrixCalc)
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(matrix STATIC src/matrix.cpp)

add_executable(matrixCalc src/main.cpp)

target_link_libraries(matrixCalc matrix)
