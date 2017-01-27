//
// Main Header
//

#ifndef CPROJECTMTA_GAME_H
#define CPROJECTMTA_GAME_H

#include "PositionList/PositionList.h"
#define SIZE 100
#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#define BOARD_SIZE 6  

// Define Types
typedef int BOOL;
typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];

// Define Structs
typedef struct _PositionArray {
    int	logical_size, physical_size;
    Position		*positions;
} PositionArray;


typedef struct _treeNode {
    Position			position;
    struct _treeNode	*up, *down, *right, *left;
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
BOOL			isNumberInBoard(char c); 
BOOL			isCapLetterInBoard(char c);
void			toUpperChar(char* c);
int				getPosValue(Position pos, Board board);
void			quicksort(int *A, int len);
#endif //CPROJECTMTA_GAME_H
