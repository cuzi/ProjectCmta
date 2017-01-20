//
//
//

#include <stdio.h>
#include "../Game.h"
#include "../TreePath.h"
#include "../Position.h"

void sumToDestination(treeNode *tn,  Position *dst, int **prices, int* pricesSize, int pathSum, Board board) {
	if (tn == NULL) return;

	pathSum += getPosValue(tn->position, board);

	if (isEqualPos(tn->position, *dst)) {
		// arrived to destination
		*(*prices + *pricesSize) = pathSum ;
		++*pricesSize;
	}

	if (isTreeNodeIsLeaf(tn) )
		return ;


	sumToDestination(tn->up, dst, prices, pricesSize, pathSum , board);
	sumToDestination(tn->down, dst, prices, pricesSize, pathSum , board);
	sumToDestination(tn->right, dst, prices, pricesSize, pathSum , board);
	sumToDestination(tn->left, dst, prices, pricesSize, pathSum , board);
}

int	findAllPathsSortedPrices(Board board, pathTree *tree, Position *dst, int **prices) {
	int pricesSize = 0;

	sumToDestination(tree->root, dst, prices, &pricesSize, 0, board);
	quicksort(*prices, pricesSize);

	return pricesSize;
}