cmake_minimum_required(VERSION 3.16)
project(matrixApp)
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/matrixLib)

add_library(matrixLib STATIC src/matrix.cpp)

add_executable(matrixApp src/main.cpp)

target_link_libraries(matrixApp matrixLib)