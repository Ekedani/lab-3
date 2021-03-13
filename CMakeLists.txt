cmake_minimum_required(VERSION 3.16)
project(lab_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_3
        CMakeLists.txt
        library.cpp
        library.h
        main.cpp
        Queue.cpp
        Queue.h)
