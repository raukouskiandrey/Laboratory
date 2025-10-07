cmake_minimum_required(VERSION 3.10)
project(Laba3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    src/main.cpp
    srcHuman.cpp
    src/Entrepreneur.cpp
    src/Application.cpp
    src/Canoe.cpp
    src/Tourist.cpp
    src/Utilities.cpp
)

add_executable(laba3_exec ${SOURCES})
