cmake_minimum_required(VERSION 3.2)

set(project "Laba22Cmake")
project(${project})

set(CMAKE_CXX_STANDARD 17)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/avia.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/planet.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)


set(${project}_SOURCES
        main.cpp)

add_subdirectory(Avia)
add_subdirectory(Planet)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} Avia)
target_link_libraries(${project} Planet)
