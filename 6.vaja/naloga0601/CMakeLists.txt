cmake_minimum_required(VERSION 3.24)
project(naloga0601)

set(CMAKE_CXX_STANDARD 14)


add_executable(naloga0601
        Graph.cpp
        PrintUtility.cpp
        VerticalPictograph.cpp naloga0601.cpp HorizonatalPictograph.cpp)
