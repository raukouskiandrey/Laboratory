cmake_minimum_required(VERSION 3.10)
project(lab1)

# ДОБАВЬТЕ ЭТУ СТРОКУ ↓
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

add_executable(lab1
    src/application.cpp
    src/date.cpp
    src/employee.cpp
    src/main.cpp
    src/utilities.cpp
)