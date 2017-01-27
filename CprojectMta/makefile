#########################
# customise these

CFILES := CprojectMta/main.c CprojectMta/Menu/Menu.c CprojectMta/Menu/Menu.h CprojectMta/Game.h CprojectMta/PositionList/PositionList.c CprojectMta/PositionList/PositionList.h CprojectMta/greedyCheapPath/GreedyCheapPath.c CprojectMta/greedyCheapPath/GreedyCheapPath.h CprojectMta/findAllPathsSortedPrices/findAllPathsSortedPrices.h CprojectMta/findAllPathsSortedPrices/findAllPathsSortedPrices.c CprojectMta/streamIo/StreamIo.c CprojectMta/streamIo/StreamIo.h CprojectMta/findAllPosiblePaths/FindAllPossiblePaths.h CprojectMta/findAllPosiblePaths/FindAllPossiblePaths.c CprojectMta/findTheCheapestPath/findTheCheapestPath.c CprojectMta/findTheCheapestPath/findTheCheapestPath.h CprojectMta/TreePath.c CprojectMta/TreePath.h CprojectMta/Position.c CprojectMta/Position.h CprojectMta/GameFn.c CprojectMta/FindCheapestPathList/FindCheapestPathList.c CprojectMta/FindCheapestPathList/FindCheapestPathList.h CprojectMta/LoadBoardFromBinFile/LoadBoardFromBinFile.c CprojectMta/LoadBoardFromBinFile/LoadBoardFromBinFile.h
PROG := prog
CFLAGS := -Wall -Wextra -g
LDFLAGS :=
########################

# -MMD generates dependencies while compiling
CFLAGS += -MMD
CC := gcc

OBJFILES := $(CFILES:.c=.o)
DEPFILES := $(CFILES:.c=.d)

$(PROG) : $(OBJFILES)
$(LINK.o) $(LDFLAGS) -o $@ $^

clean :
rm -f $(PROG) $(OBJFILES) $(DEPFILES)

-include $(DEPFILES)