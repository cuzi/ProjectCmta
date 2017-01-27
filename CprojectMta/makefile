Program: main.o Menu.o PositionList.o findAllPathsSortedPrices.o StreamIo.o FindAllPossiblePaths.o findTheCheapestPath.o TreePath.o TreePath.o Position.o GameFn.o FindCheapestPathList.o LoadBoardFromBinFile.o
gcc -o Program main.o Menu.o PositionList.o findAllPathsSortedPrices.o StreamIo.o FindAllPossiblePaths.o findTheCheapestPath.o TreePath.o TreePath.o Position.o GameFn.o FindCheapestPathList.o LoadBoardFromBinFile.o

main.o: CprojectMta/main.c CprojectMta/Menu/Menu.h
gcc -c main.c

Menu.o: CprojectMta/Menu/Menu.c CprojectMta/Game.h CprojectMta/Position.h CprojectMta/TreePath.h CprojectMta/greedyCheapPath/GreedyCheapPath.h CprojectMta/streamIo/StreamIo.h
gcc -c CprojectMta/Menu/Menu.c

PositionList.o: CprojectMta/PositionList/PositionList.c CprojectMta/PositionList/PositionList.h
gcc -c CprojectMta/PositionList/PositionList.c

findAllPathsSortedPrices.o: CprojectMta/findAllPathsSortedPrices/findAllPathsSortedPrices.c  CprojectMta/Menu/Menu.h CprojectMta/Game.h CprojectMta/TreePath.c CprojectMta/Position.h
gcc -c CprojectMta/findAllPathsSortedPrices/findAllPathsSortedPrices.c

StreamIo.o: CprojectMta/Game.h CprojectMta/streamIo/StreamIo.c CprojectMta/streamIo/StreamIo.h
gcc -c  CprojectMta/streamIo/StreamIo.c

FindAllPossiblePaths.o: CprojectMta/Game.h CprojectMta/TreePath.h CprojectMta/Position.h CprojectMta/findAllPosiblePaths/FindAllPossiblePaths.c CprojectMta/findAllPosiblePaths/FindAllPossiblePaths.h
gcc -c CprojectMta/findAllPosiblePaths/FindAllPossiblePaths.c


findTheCheapestPath.o: CprojectMta/Game.h CprojectMta/TreePath.h CprojectMta/Position.h CprojectMta/findTheCheapestPath/findTheCheapestPath.h CprojectMta/findTheCheapestPath/findTheCheapestPath.c
gcc -c CprojectMta/findTheCheapestPath/findTheCheapestPath.c

TreePath.o: CprojectMta/Game.h CprojectMta/TreePath.h CprojectMta/Position.h CprojectMta/TreePath.c CprojectMta/TreePath.h CprojectMta/TreePath.c CprojectMta/TreePath.c
gcc -c CprojectMta/TreePath.c

Position.o:  CprojectMta/Game.h CprojectMta/Position.h CprojectMta/Position.h CprojectMta/Position.c
gcc -c CprojectMta/Position.c

GameFn.o: CprojectMta/Game.h CprojectMta/Position.h CprojectMta/GameFn.c CprojectMta/GameFn.h
gcc -c CprojectMta/GameFn.c

FindCheapestPathList.o: CprojectMta/PositionList/PositionList.h CprojectMta/Game.h CprojectMta/FindCheapestPathList/FindCheapestPathList.c CprojectMta/FindCheapestPathList/FindCheapestPathList.h
gcc -c CprojectMta/FindCheapestPathList/FindCheapestPathList.c

LoadBoardFromBinFile.o: CprojectMta/Game.h CprojectMta/streamIo/StreamIo.h CprojectMta/LoadBoardFromBinFile/LoadBoardFromBinFile.c CprojectMta/LoadBoardFromBinFile/LoadBoardFromBinFile.h
gcc -c CprojectMta/LoadBoardFromBinFile/LoadBoardFromBinFile.c