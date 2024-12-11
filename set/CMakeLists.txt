cmake_minimum_required(VERSION 3.0)

project(set)

set(SOURCE_FILES
        src/main.cpp
)
include_directories(include)

add_executable(set_bin ${SOURCE_FILES})

target_link_libraries(set_bin Lib)