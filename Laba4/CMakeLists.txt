cmake_minimum_required(VERSION 3.10)
project(Laba4 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    src/main.cpp
    src/Application.cpp
    src/Employee.cpp
    src/HourlyEmployee.cpp
    src/StaffEmployee.cpp
    src/PercentBasedEmployee.cpp
    src/Utilities.cpp
)

add_executable(laba4_exec ${SOURCES})

