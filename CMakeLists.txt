cmake_minimum_required(VERSION 3.3)
project(CprojectMta)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CprojectMta/main.c CprojectMta/Menu/Menu.c CprojectMta/Menu/Menu.h CprojectMta/Game.h CprojectMta/PositionList/PositionList.c CprojectMta/PositionList/PositionList.h CprojectMta/greedyCheapPath/GreedyCheapPath.c CprojectMta/greedyCheapPath/GreedyCheapPath.h CprojectMta/findAllPathsSortedPrices/findAllPathsSortedPrices.h CprojectMta/findAllPathsSortedPrices/findAllPathsSortedPrices.c CprojectMta/streamIo/StreamIo.c CprojectMta/streamIo/StreamIo.h CprojectMta/findAllPosiblePaths/FindAllPossiblePaths.h CprojectMta/findAllPosiblePaths/FindAllPossiblePaths.h CprojectMta/findTheCheapestPath/findTheCheapestPath.c CprojectMta/findTheCheapestPath/findTheCheapestPath.h)
add_executable(CprojectMta ${SOURCE_FILES})