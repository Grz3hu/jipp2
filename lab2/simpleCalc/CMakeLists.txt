cmake_minimum_required(VERSION 3.16)
project(simpleCalc)
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(calc SHARED src/calc.cpp)

add_executable(simpleCalc src/main.cpp)

target_link_libraries(simpleCalc calc)
