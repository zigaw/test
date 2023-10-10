cmake_minimum_required(VERSION 3.24)
project(naloga1102)

set(CMAKE_CXX_STANDARD 14)

add_executable(naloga1102
        DuplicatedSensorIdExeption.cpp
        naloga1101.cpp
        PressureSensor.cpp
        PressureSensorP12.cpp
        Sensor.cpp
        SensorHub.cpp Log.cpp FileAccessException.cpp)
