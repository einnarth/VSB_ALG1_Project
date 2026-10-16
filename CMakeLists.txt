cmake_minimum_required(VERSION 4.1)
project(ALG_Hull)

set(CMAKE_CXX_STANDARD 20)

add_executable(ALG_Hull main.cpp
        Tree.h
        QuickHull.cpp
        QuickHull.h)
