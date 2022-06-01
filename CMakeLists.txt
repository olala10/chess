cmake_minimum_required(VERSION 3.22)
project(Moje_dokumenty)

set(CMAKE_CXX_STANDARD 11)

add_executable(ola main.cpp Field.hpp pieces/Piece.h pieces/Pawn.h Board.h Color.h Move.hpp pieces/King.h)
