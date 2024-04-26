cmake_minimum_required(VERSION 3.27)
project(CA2BiancaValicec)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA2BiancaValicec main.cpp
        Bug.cpp
        Bug.h
        Crawler.h
        Hopper.h
        Hopper.cpp
        Crawler.cpp
        Bishop.h
        Bishop.cpp
        Board.h
        Board.cpp)
