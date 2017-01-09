cmake_minimum_required(VERSION 3.3)
project(CprojectMta)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CprojectMta/main.c CprojectMta/Menu.c CprojectMta/Menu.h CprojectMta/Game.h)
add_executable(CprojectMta ${SOURCE_FILES})