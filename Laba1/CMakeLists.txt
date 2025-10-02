cmake_minimum_required(VERSION 3.10)
project(lab1)

# ИСПРАВЛЕНО: указываем папку header вместо include
include_directories(header)

add_executable(lab1
    src/application.cpp
    src/date.cpp
    src/employee.cpp
    src/main.cpp
    src/utilities.cpp
)