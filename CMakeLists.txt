cmake_minimum_required(VERSION 4.3)
project(COP3530_Project_2b)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        dataPulling.cpp
        dataPulling.h
        main.cpp
        dataPulling.cpp
        minHeap.cpp)
