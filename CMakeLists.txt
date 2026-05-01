cmake_minimum_required(VERSION 3.26)

# Project name
project(BugsLife_Simulation_CPP)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)

# List all source files used in the project
add_executable(BugsLife_Simulation_CPP
        main.cpp
        Bug.cpp
        Crawler.cpp
        Hopper.cpp
        Board.cpp
)

# Copy bugs.txt from the project root into the build folder
configure_file(${CMAKE_SOURCE_DIR}/bugs.txt ${CMAKE_BINARY_DIR}/bugs.txt COPYONLY)