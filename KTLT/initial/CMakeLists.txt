cmake_minimum_required(VERSION 3.23)
project(initial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(initial
        main.cpp
        main.h
        study_in_pink1.cpp
        study_in_pink1.h)
