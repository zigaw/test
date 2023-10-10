cmake_minimum_required(VERSION 3.24)
project(naloga0402)

set(CMAKE_CXX_STANDARD 14)

add_executable(naloga0402
        Date.cpp
        DateTime.cpp
        Mailbox.cpp
        Message.cpp
        Time.cpp
        User.cpp
        Date.h
        DateTime.h
        Mailbox.h
        Message.h
        Time.h
        User.h
        Priority.h
        naloga0402.cpp
        )
