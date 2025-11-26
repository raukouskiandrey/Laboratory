cmake_minimum_required(VERSION 3.10)
project(Laba8 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    source/main.cpp
    source/Menu.cpp
    source/Algorithm.cpp
    source/DoublyLinkedList.cpp
    source/Utilities.cpp
)

add_executable(laba8_exec ${SOURCES})
