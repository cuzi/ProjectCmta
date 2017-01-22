//
// Project menu
//

#include <stdio.h>
#include <stdlib.h>
#include "../Game.h"
#include "../Position.h"
#include "../TreePath.h"
#include "../greedyCheapPath/GreedyCheapPath.h"
#include "../streamIo/StreamIo.h"
#include "Menu.h"

void showMenu() {

    PositionList* pl;
    Position* source = createEmptyPos();
    Position* destination = createEmptyPos();
    pathTree* pt = createNewPathTree();
	int *pricesArray = (int *)malloc(SIZE * sizeof(int));
    PositionArray* pa;
	int paLength = 0;

    Board c;
    Board board =
            {
                    {1, 6, 3, 0},
                    {4, 5, 6, 0},
                    {0, 0, 7, 0},
                    {0, 0, 0, 0}
            };
	const char *menuOptions[] = {
								  "Load a board from file", 
								  "Enter a source position and destination", 
								  "Find a greedy cheap path between the source and destination",
								  "Create a tree of all possible paths starting from source position",
								  "Find all sorted path prices starting from source",
								  "Find the cheapest path between source and destination",
								  "Exit"
								};
	unsigned int input;
	char file_name[SIZE] ="/Users/benfishman/Desktop/boardExamples/1.bin";


    // print menu with enumeration
	for (int i = 0; i < 7; ++i) {
		printf("%d.\t%s\n", i + 1, menuOptions[i]);
	}

    // menu
    printf("\nEnter new command: \n");
    scanf("%d", &input);

    while(input != 7){

        switch (input)
        {
            case 1: // load board from binary file
                //printf("Enter File Path:\n");
                //scanf("%s",&file_name);
                loadBoardFromBinFile(file_name,c);
                for(int i=0;i<BOARD_SIZE;i++){
                    for(int j=0;j<BOARD_SIZE;j++){
                        printf("%d,%d: %d\n",i,j,c[i][j]);
                    }
                }
                break;

            case 2: // scan source and dest positions
                scanPositions(source, destination);
                break;

            case 3:
                scanPositions(source, destination);
                 pa = greedyCheapPath(board,source,destination);
                printPositionArray(pa);
                break;
            case 4: 
            case 5:
            case 6: // Check if there is existing positions and then end then execute the correct gateways
                if (*source[0] == NULL || *destination[0] == NULL) {
                    printf("You forgot to enter positions\n");
                    scanPositions(source, destination);
                }

                switch (input)
                {
                    case 3:  // execute greedyCheapPath1 function
						greedyCheapPath(board, source, destination);
						break;
                    case 4:  // execute findAllPossiblePaths
						*pt = findAllPossiblePaths(board, source);
						break;
                    case 5:  // execute findAllPathSortedPrices
						if (pt->root == NULL)
							*pt = findAllPossiblePaths(board, source);

						paLength = findAllPathsSortedPrices(board, pt, destination, &pricesArray);

                        break;
                    case 6:
						if (pt->root != NULL)
							*pt = findAllPossiblePaths(board, source);
                            pl = findTheCheapestPath(board, pt, destination);
                            printPositionList(pl);

                        break;
                }

				break;
            default:
                printf("\n%d is unknown input please try again..\n\n", input);
                showMenu(source, destination, board);
				return;
        }
        printf("\nEnter new command: \n");
        scanf("%d", &input);
    }

    printf("Bye Bye ...");


	// TODO: free vars
}

void scanXY(char *x, char *y) {
    while (TRUE) {
		printf("Enter [ROW] position, Capital letter:\n");
		scanf(" %c", x);
        printf("Enter [COL] position, number:\n");
        scanf(" %c", y);

		toUpperChar(x);

		if ( isNumberInBoard(*y) && isCapLetterInBoard(*x) ) {
        break;
        } // coordinates are valid !
        else{
            printf("\nWrong Positions ! \n");
        }
    }

}

void scanPositions(Position *source, Position *destination) {
	printf("Enter source position: \n");
	scanXY(&(*source)[0], &(*source)[1]);
	printf("Enter target position: \n");
	scanXY(&(*destination)[0], &(*destination)[1]);

}
