//
//
//

#include <stdio.h>
#include "../Game.h"
#include "../TreePath.h"
#include "../Position.h"

static void setLowestPathTreeNode(treeNode *tn, treeNode **lowTn, Position *dst, int *lowSum, int pathSum, Board board) {
	if (tn == NULL || (pathSum > *lowSum && *lowSum != -1)) return;

	pathSum += getPosValue(tn->position, board);

	if (isEqualPos(tn->position, *dst)) {
		// arrived to destination
		*lowSum = pathSum;
		*lowTn = tn;
		return;
	}

	if (isTreeNodeIsLeaf(tn))
		return;

	setLowestPathTreeNode(tn->up, lowTn, dst, lowSum, pathSum, board);
	setLowestPathTreeNode(tn->down, lowTn, dst, lowSum, pathSum, board);
	setLowestPathTreeNode(tn->right, lowTn, dst, lowSum, pathSum, board);
	setLowestPathTreeNode(tn->left, lowTn, dst, lowSum, pathSum, board);
}

treeNode *findTheCheapestPathEndNode(Board board, treeNode *node, Position *dst) {
	int lowestSum = -1;
	treeNode *lowTn = NULL;

	setLowestPathTreeNode(node, &lowTn, dst, &lowestSum, 0, board);

	return lowTn;

}