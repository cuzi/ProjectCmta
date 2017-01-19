//
//
//

#include <stdio.h>
#include "Game.h"
#include "TreePath.h"
#include "Position.h"

void sumToDestination(treeNode *tn,  Position *dst, int **prices, int* pricesSize, int pathSum, Board board, char dir) {
	int currVal = getPosValue(tn->position, board);

	if (isEqualPos(tn->position, *dst)) {
		//if (!isTreeNodeIsLeaf(tn))
			//return;

		// arrived to destination
		*(*prices + *pricesSize) = pathSum + currVal;
		++*pricesSize;
	}
	if (isTreeNodeIsLeaf(tn) && dir != '\0')
		return ;


	if (dir != 'd' && tn->up != NULL)
		sumToDestination(tn->up, dst, prices, pricesSize, pathSum + currVal, board, 'u');
	if (dir != 'u' && tn->down != NULL)
		sumToDestination(tn->down, dst, prices, pricesSize, pathSum + currVal, board, 'd');
	if (dir != 'l' && tn->right != NULL)
		sumToDestination(tn->right, dst, prices, pricesSize, pathSum + currVal, board, 'r');
	if (dir != 'r' && tn->left != NULL)
		sumToDestination(tn->left, dst, prices, pricesSize, pathSum + currVal, board, 'l');
}

int	findAllPathsSortedPrices(Board board, pathTree *tree, Position *dst, int **prices) {
	int pricesSize = 0;

	sumToDestination(tree->root, dst, prices, &pricesSize, 0, board, '\0');
	quick_sort(prices, 0, pricesSize);

	return pricesSize;
}