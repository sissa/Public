# CMake configuration demo

# version 3.16 is bundled with ubuntu20.04
cmake_minimum_required(VERSION 3.16)

# set the project name, version, and primary programming language (C++)
project(canvas-draw VERSION 0.1 LANGUAGES CXX)

# add the executable
add_executable(canvas-draw main.cpp)
