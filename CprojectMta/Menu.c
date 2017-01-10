//
// Project menu
//

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GreedyCheapPath/GreedyCheapPath.h"

void showMenu() {

    Position* source = (Position*)malloc(sizeof(Position));
    Position* destination = (Position*)malloc(sizeof(Position));

    Board board=
            {
                    {'1', '5', '6', '7'},
                    {'4', '4', '8', '0'},
                    {'4', '4', '8', '0'},
                    {'2', '3', '4', '5'}
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
	char file_name[SIZE];


    // print menu with enumeration
	for (int i = 0; i < 7; ++i) {
		printf("%d.\t%s\n", i + 1, menuOptions[i]);
	}

    // menu
	scanf("%d", &input);

    while(input != 7){

        switch (input)
        {
            case 1: // load board from binary file
                printf("Enter File Path\n");
                scanf("%s",&file_name);
                // TODO:  loadBoardFromBinFile(file_name, board);
                break;

            case 2: // scan source and dest positions
                scanPositions(source, destination);
                break;

            case 3: // execute greedyCheapPath function
                greedyCheapPath(board,source,destination);
                break;

            case 4: // execute findAllPossiblePaths
                break;

            case 5: // execute findAllPathSortedPrices
                break;

            case 6: // bla bla
                if (*source == NULL || *destination == NULL) {
                    printf("You forgot to enter positions\n");
                    scanPositions(source, destination);
                }

                switch (input)
                {

                    case 3:
                        printf("hello3\n");
                        break;
                    case 4:
                        printf("hello4\n");
                        break;
                    case 5:
                        printf("hello5\n");
                        break;
                    case 6:
                        printf("hell6o\n");
                        break;
                }

            default:
                printf("\n%d is unknown input please try again..\n\n", input);
                showMenu(source, destination, board);
                break;
        }

    }

    printf("Bye Bye ...");
}

void scanXY(char *x, char *y) {
	printf("Enter X position, number\n");
	scanf("%d", x);
	printf("Enter Y position, Capital letter\n");
	scanf("%d", y);

	if (*x >= '0' + BOARD_SIZE || *y >= 'A' + BOARD_SIZE ||
		*x < '0' || *y < 'A' ) {
		printf("Wrong Positions\n");
		scanXY(x, y);
	}
}

void scanPositions(Position *source, Position *destination) {

	printf("Enter source position: \n");
	scanXY(&(*source)[0], &(*source)[1]);
	printf("Enter target position: \n");
	scanXY(&(*destination)[0], &(*destination)[1]);
}