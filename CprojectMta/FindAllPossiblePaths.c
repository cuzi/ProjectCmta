//
//
//


#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "TreePath.h"
#include "Position.h"

pathTree findAllPossiblePaths(Board board, Position *startingPosition) {
	pathTree* pt	   = createNewPathTree();
	Position** pa[SIZE] = (Position**)malloc(sizeof(Position));
	pt->root		   = createTreeNode(startingPosition);
	connectAllBoardTreeNodes(board, pt->root, pa);


}
BOOL isPositionInArray(Position*** positions, Position *position) {
	while (**positions) {
		if (**positions == *position)
			return TRUE;
		++*positions;
	}
	return FALSE;
}
void addPositionToArray(Position*** positions, Position* position) {
	int i = 0;
	while (**positions[i]) {
		++i;
	}
	*positions[i] = *position;
}
void connectAllBoardTreeNodes(Board board, treeNode* tn, Position*** positions) {
	int x = coordinateToInt( tn->position[0]), y = coordinateToInt( tn->position[1] );
	
	addPositionToArray(positions, tn);

	if (!tn->up) {
		if (inboard(y - 1)) {
			Position* pos = createPos(x, y - 1);
			if (!isPositionInArray(pos, positions)) {
				treeNode* up = createTreeNode(pos);
				connectTreeNodeWith('u', tn, pos);
				connectAllBoardTreeNodes(board, tn, pos);

			}
			else {
				tn->up = NULL;
			}

		}
		else {
			tn->up = NULL;
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