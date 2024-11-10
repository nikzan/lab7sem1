cmake_minimum_required(VERSION 3.29)
project(lab7)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab7 src/main.cpp
        src/task1.cpp
        src/task2.cpp
        src/task3.cpp
        src/task4.cpp
        include/fill_array.h
        src/fill_array.cpp
        include/tasks.h
        src/task5.cpp
        src/task6.cpp
        src/task7.cpp
        src/task8.cpp)
