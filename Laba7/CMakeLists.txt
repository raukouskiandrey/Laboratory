cmake_minimum_required(VERSION 3.10)
project(Laba7 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)  

set(SOURCES
    source/main.cpp
    source/Utils.cpp
    source/FileReader.cpp
    source/menuActions.cpp
)

add_executable(laba7_exec ${SOURCES})