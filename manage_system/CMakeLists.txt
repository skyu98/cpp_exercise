cmake_minimum_required(VERSION 3.13)
project(manage_system)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(include)

add_executable(manage_system
        src/workerManager.cpp
        src/main.cpp
        src/employee.cpp
        src/manager.cpp
        src/boss.cpp)
