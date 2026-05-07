cmake_minimum_required(VERSION 3.26)

project(BugsLife_Simulation_CPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(BugsLife_Simulation_CPP
        main.cpp
        Bug.cpp
        Crawler.cpp
        Hopper.cpp
        DiagonalBug.cpp
        Board.cpp
)

configure_file(${CMAKE_SOURCE_DIR}/bugs.txt ${CMAKE_BINARY_DIR}/bugs.txt COPYONLY)