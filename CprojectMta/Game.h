//
// Created by Ben Fishman on 09/01/2017.
//

#ifndef CPROJECTMTA_GAME_H
#define CPROJECTMTA_GAME_H

#include "PositionList.h"
#ifndef TREE_H
#define TREE_H
#define SIZE 100
#define BOARD_SIZE 4  // TODO: need to be 6

// Define Types

typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];

// Define Structs
typedef struct _PositionArray {
    unsigned int	logical_size, physical_size;
    Position		*positions;
} PositionArray;


typedef struct _treeNode {
    Position			position;
    struct _treeNode	*up, *down, *top, *left;
} treeNode;

typedef struct _pathTree {
    treeNode *root;
} pathTree;


// Functions Declerations
pathTree		findAllPossiblePaths(Board board, Position *startingPosition);
int				findAllPathsSortedPrices(Board board, pathTree *tree, Position *dst, int **prices);
treeNode		*findTheCheapestPathEndNode(Board board, treeNode *node, Position *dst);
PositionList    *findTheCheapestPath(Board board, pathTree *tree, Position *dst);
void			loadBoardFromBinFile(char *file_name, Board brd);
void			scanXY(char *x, char *y);
void			scanPositions(Position *source, Position *destination);

#endif

#endif //CPROJECTMTA_GAME_H
