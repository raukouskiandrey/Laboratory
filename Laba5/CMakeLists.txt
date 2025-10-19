cmake_minimum_required(VERSION 3.10)
project(Laba5 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    src/main.cpp
    src/Menu.cpp
    src/Utilities.cpp
)

add_executable(laba5_exec ${SOURCES})