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
	pathTree* pt  = createNewPathTree();
	Position** pa = (Position*)malloc(sizeof(Position));
	pt->root	  = createTreeNode(startingPosition);
	connectAllBoardTreeNodes(pt->root, pa);

	return *pt;

}
BOOL isPositionInArray(Position** positions, Position *position) {
	while (*positions) {
		if (*positions == position)
			return TRUE;
		++positions;
	}
	return FALSE;
}
void addPositionToArray(Position** positions, Position* position) {
	int i = 0;
	while (positions[i]) {
		++i;
	}
	positions[i] = position;
}


void connectAllBoardTreeNodes(treeNode* tn, Position** positions) {
	int x = coordinateToInt( tn->position[0]), y = coordinateToInt( tn->position[1] );
	
	addPositionToArray(positions, tn->position);
	
	if (tn->up == NULL) {
		connectTreeNodeWithCoordinates(x, y - 1, 'u', tn, positions);
	}
	if (tn->down == NULL) {
		connectTreeNodeWithCoordinates(x, y + 1, 'd', tn, positions);
	}
	if (tn->right == NULL) {
		connectTreeNodeWithCoordinates(x + 1, y, 'r', tn, positions);
	}
	if (tn->right == NULL) {
		connectTreeNodeWithCoordinates(x - 1, y, 'l', tn, positions);
	}
}
	
void connectTreeNodeWithCoordinates(int x, int y, char direction, treeNode* source, Position** positions) {
	if (inboard(x) && inboard(y)) {
		Position* pos = createPos(x, y);
		if (!isPositionInArray(positions, pos)) {
			treeNode* target = createTreeNode(pos);
			connectTreeNodeWith(direction, source, target);
			connectAllBoardTreeNodes(target, positions);
		}
	}
}
void connectTreeNodeWith(char direction, treeNode* base, treeNode* next) {
	switch (direction)
	{
	case 'u': // UP
		base->up = next;
		next->down = base;
		break;
	case 'd': // DOWN
		base->down = next;
		next->up = base;
		break;
	case 'r': // RIGHT
		base->right = next;
		next->left = base;
		break;
	case 'l': // LEFT
		base->left = next;
		next->right = base;
		break;
		
	}

}