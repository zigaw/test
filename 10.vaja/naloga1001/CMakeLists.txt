cmake_minimum_required(VERSION 3.24)
project(naloga1001)

set(CMAKE_CXX_STANDARD 14)


add_executable(naloga1001
        CompetitiveExercise.cpp
        Date.cpp
        Excercise.cpp
        ExerciseTracker.cpp
        naloga1001.cpp
        Person.cpp
        StrengthExercise.cpp
        Time.cpp
        PrintIfStrengthExercise.cpp WeightLog.cpp)
