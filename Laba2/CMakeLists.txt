cmake_minimum_required(VERSION 3.10)
project(Laba2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    src/main.cpp
    src/String.cpp
    src/utilities.cpp
)

add_executable(laba2_exec ${SOURCES})
