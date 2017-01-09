//
// Headers declerations
//

#ifndef TREE_H
#define TREE_H
#define FALSE 0
#define TRUE 1
#define SIZE 100
#define _CRT_SECURE_NO_WARNINGS
#define BOARD_SIZE 4  // TODO: need to be 6 

// Define Types
typedef int BOOL;
typedef char Position[2];
typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];

// Define Structs
typedef struct _PositionArray {
	unsigned int	logical_size, physical_size;
	Position		*positions;
} PositionArray;

typedef struct _PositionListCell {
	Position				    position;
	struct _PositionListCell	*next;
} PositionListCell;

typedef struct _PositionList {
	PositionListCell *head, *tail;
} PositionList;

typedef struct _treeNode {
	Position			position;
	struct _treeNode	*up, *down, *top, *left;
} treeNode;

typedef struct _pathTree {
	treeNode *root;
} pathTree;




// Functions Declerations
PositionArray	*greedyCheapPath(Board board, Position *src, Position *dst);
pathTree		findAllPossiblePaths(Board board, Position *startingPosition);
int				findAllPathsSortedPrices(Board board, pathTree *tree, Position *dst, int **prices);
treeNode		*findTheCheapestPathEndNode(Board board, treeNode *node, Position *dst);
PositionList    *findTheCheapestPath(Board board, pathTree *tree, Position *dst);
void			loadBoardFromBinFile(char *file_name, Board brd);
int				showMenu(Position *source, Position *destination, Board *board);
void			scanXY(char *x, char *y);
void			scanPositions(Position *source, Position *destination);

#endif
