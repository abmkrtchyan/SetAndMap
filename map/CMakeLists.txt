cmake_minimum_required(VERSION 3.0)

project(map)

set(SOURCE_FILES
        src/main.cpp
)
include_directories(include)

add_executable(map_bin ${SOURCE_FILES})

target_link_libraries(map_bin Lib)