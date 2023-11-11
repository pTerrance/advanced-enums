cmake_minimum_required(VERSION 3.26)
project(advanced_enum)

set(CMAKE_CXX_STANDARD 23)

add_executable(advanced_enum 
        main.cpp
        include/macro-hell.inc
        include/advanced-enums.h)
