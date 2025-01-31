cmake_minimum_required(VERSION 3.2)

set(project "Laba33")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        Laba33.cpp)

set(${project}_HEADERS
        Laba33.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
