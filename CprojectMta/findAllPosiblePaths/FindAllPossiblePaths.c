//
//
//


#include <stdio.h>
#include <stdlib.h>
#include "../Game.h"
#include "../TreePath.h"
#include "../Position.h"
#include "FindAllPossiblePaths.h"

pathTree findAllPossiblePaths(Board board, Position *startingPosition) {
	pathTree* pt = createNewPathTree();
	int arrSize = 0;
	pt->root = createTreeNode(startingPosition);
	connectAllBoardTreeNodes(pt->root, arrSize, board);

	return *pt;

}

static void changeBoardValue(Position pos, Board board, char c) {
	int x = coordinateToInt(pos[0]), y = coordinateToInt(pos[1]);

	board[y][x] = c;
}

void connectAllBoardTreeNodes(treeNode* tn, int arrSize, Board board) {
	int x = coordinateToInt(tn->position[0]), y = coordinateToInt(tn->position[1]);

	char tmp = getPosValue(tn, board);
	changeBoardValue(tn, board, 0);

	connectTreeNodeWithCoordinates(x, y - 1, 'u', tn, arrSize, board);
	connectTreeNodeWithCoordinates(x, y + 1, 'd', tn, arrSize, board);
	connectTreeNodeWithCoordinates(x + 1, y, 'r', tn, arrSize, board);
	connectTreeNodeWithCoordinates(x - 1, y, 'l', tn, arrSize, board);

	changeBoardValue(tn, board, tmp);
}

void connectTreeNodeWithCoordinates(int x, int y, char direction, treeNode* source, int arrSize, Board board) {
	if (inboard(x) && inboard(y)) {
		Position* pos = createPos(x, y);
		if (getPosValue(*pos, board) != 0) {
			treeNode* target = createTreeNode(pos);
			connectTreeNodeWith(direction, source, target);
			connectAllBoardTreeNodes(target, arrSize, board);
		}
		free(pos);
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