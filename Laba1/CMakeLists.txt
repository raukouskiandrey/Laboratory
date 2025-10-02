cmake_minimum_required(VERSION 3.10.0)
project(lab1 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/application.cpp
    src/date.cpp
    src/employee.cpp
    src/main.cpp
    src/utilities.cpp
)

set(HEADERS
    include/application.hpp  
    include/date.hpp         
    include/employee.hpp     
    include/utilities.hpp    
)

add_executable(lab1 ${SOURCES} ${HEADERS})