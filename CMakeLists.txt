cmake_minimum_required(VERSION 3.26)
project(dag)

set(CMAKE_CXX_STANDARD 23)

add_executable(dag main.cpp
        head.cpp)
