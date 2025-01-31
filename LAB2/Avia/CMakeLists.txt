cmake_minimum_required(VERSION 3.2)

set(project "Avia")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        aviafunc.cpp)

set(${project}_HEADERS
        avia.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
