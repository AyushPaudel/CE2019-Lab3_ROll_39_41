cmake_minimum_required(VERSION 3.16)
project(ayush)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ayush
        AbstractBST.h
        ArrayBST.cpp
        ArrayBST.h
        main.cpp)
