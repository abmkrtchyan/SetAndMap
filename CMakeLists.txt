cmake_minimum_required(VERSION 3.0)
project(SetAndMap)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(SetAndMap
        src/main.cpp
        src/Node.cpp)