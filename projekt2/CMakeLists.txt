cmake_minimum_required(VERSION 3.16)

project(chess)
include_directories(include)

add_executable(chess src/main.cpp src/point.cpp src/piece.cpp src/pawn.cpp src/rook.cpp src/knight.cpp src/bishop.cpp src/king.cpp src/queen.cpp src/board.cpp)