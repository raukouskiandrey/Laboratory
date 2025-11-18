cmake_minimum_required(VERSION 3.10)
project(Laba6 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    src/main.cpp
    src/Human.cpp
    src/Entrepreneur.cpp
    src/Application.cpp
    src/Shuttle.cpp
    src/Tourist.cpp
    src/Utilities.cpp
    src/TaxPaymentList.cpp
    src/ShopAddressList.cpp
    src/BorderCrossingList.cpp
)

add_executable(laba6_exec ${SOURCES})