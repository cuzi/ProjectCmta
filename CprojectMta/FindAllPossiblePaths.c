//
//
//


#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "TreePath.h"
#include "Position.h"
#include "findAllPossiblePaths.h"

pathTree findAllPossiblePaths(Board board, Position *startingPosition) {
	pathTree* pt      = createNewPathTree();
	Position pa[SIZE] = { NULL };
	int arrSize		  = 0;
	pt->root	      = createTreeNode(startingPosition);
	connectAllBoardTreeNodes(pt->root, pa, arrSize, board);

	return *pt;

}
BOOL isPositionInArray(Position *position, Position* positions, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		if (isEqualPos(positions[i], *position))
			return TRUE;
	}
	return FALSE;
}

static void addPosition(Position* positions, int *arrSize, treeNode* tn) {
	positions[*arrSize][0] = tn->position[0];
	positions[*arrSize][1] = tn->position[1];
	++(*arrSize);
}
static void removeLastPosition(Position* positions, int *arrSize) {

	positions[*arrSize][0] = '\0';
	positions[*arrSize][1] = '\0';
	--(*arrSize);
}

void connectAllBoardTreeNodes(treeNode* tn, Position* positions, int arrSize, Board board) {
	int x = coordinateToInt( tn->position[0]), y = coordinateToInt( tn->position[1] );


	addPosition(positions, &arrSize, tn);
	
	connectTreeNodeWithCoordinates(x, y - 1, 'u', tn, positions, arrSize, board);
	connectTreeNodeWithCoordinates(x, y + 1, 'd', tn, positions, arrSize, board);
	connectTreeNodeWithCoordinates(x + 1, y, 'r', tn, positions, arrSize, board);
	connectTreeNodeWithCoordinates(x - 1, y, 'l', tn, positions, arrSize, board);
	
	removeLastPosition(positions, &arrSize);
}
	
void connectTreeNodeWithCoordinates(int x, int y, char direction, treeNode* source, Position* positions, int arrSize, Board board) {
	if (inboard(x) && inboard(y)) {
		Position* pos = createPos(x, y);
		if (!isPositionInArray(pos, positions, arrSize) && getPosValue(*pos, board) != 0) {
			treeNode* target = createTreeNode(pos);
			connectTreeNodeWith(direction, source, target);
			connectAllBoardTreeNodes(target, positions, arrSize, board);
		}
	}
}
void connectTreeNodeWith(char direction, treeNode* base, treeNode* next) {
	switch (direction)
	{
	case 'u': // UP
		base->up = next;
		break;
	case 'd': // DOWN
		base->down = next;
		break;
	case 'r': // RIGHT
		base->right = next;
		break;
	case 'l': // LEFT
		base->left = next;
		break;
		
	}

}