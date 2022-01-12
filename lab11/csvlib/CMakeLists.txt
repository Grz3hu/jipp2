cmake_minimum_required(VERSION 3.16)

project(csvlib)
include_directories(include)

add_executable(csvlib src/csvlib.cpp src/main.cpp)
