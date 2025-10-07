cmake_minimum_required(VERSION 3.10)
project(Laba1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    src/main.cpp
    src/application.cpp
    src/utilities.cpp
    src/date.cpp
    src/employee.cpp
)

add_executable(laba1_exec ${SOURCES})
