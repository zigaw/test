cmake_minimum_required(VERSION 3.24)
project(naloga0702)

set(CMAKE_CXX_STANDARD 14)


add_executable(naloga0702
        naloga0701.cpp
        Point.cpp PrintUtility.cpp Time.cpp StrengthExercise.cpp Person.cpp ExerciseTracker.cpp Excercise.cpp Date.cpp CompetitiveExercise.cpp)
