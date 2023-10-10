cmake_minimum_required(VERSION 3.24)
project(naloga0502)

set(CMAKE_CXX_STANDARD 14)


add_executable(naloga0502
        Date.cpp
        Person.cpp
        Account.cpp SavingAccount.cpp Bank.cpp naloga0502.cpp transaction.cpp)
