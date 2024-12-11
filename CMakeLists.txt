cmake_minimum_required(VERSION 3.0)
project(SetAndMap)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(SOURCE_FILES
    src/Node.cpp
)

add_library(Lib STATIC ${SOURCE_FILES})

add_subdirectory(set)
add_subdirectory(map)
