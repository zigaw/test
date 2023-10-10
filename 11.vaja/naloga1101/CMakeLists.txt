cmake_minimum_required(VERSION 3.24)
project(naloga1101)

set(CMAKE_CXX_STANDARD 14)


add_executable(naloga1101
        Sensor.cpp
        PressureSensor.cpp
        PressureSensorP12.cpp
        SensorHub.cpp DuplicatedSensorIdExeption.cpp naloga1101.cpp InvalidLocationExeption.cpp)
