cmake_minimum_required(VERSION 3.24)
project(priprava_nakolokvij02)

set(CMAKE_CXX_STANDARD 14)


add_executable(priprava_nakolokvij02
        UnparsableDateException.cpp
        FileNotFound.cpp
        Date.cpp
        Fuel.cpp main.cpp)
