//
// TreePath Module Implement Functions that belongs to pathTree and treeNode structs
//


#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "TreePath.h"
#include "Position.h"

static void freeTreeNodeAndPointers(treeNode *tn) {
	if (tn == NULL)
		return;

	freeTreeNodeAndPointers(tn->up);
	freeTreeNodeAndPointers(tn->down);
	freeTreeNodeAndPointers(tn->left);
	freeTreeNodeAndPointers(tn->right);

	free(tn);

}

void freePathTree(pathTree *pt) {
	freeTreeNodeAndPointers(pt->root);
	free(pt);
}
pathTree* createNewPathTree() {
	pathTree* pt = (pathTree*)malloc(sizeof(pathTree));
	pt->root = NULL;

	return pt;
}

treeNode* createTreeNode(Position* position) {
	treeNode* tn = (treeNode*)malloc(sizeof(treeNode));
	tn->position[0] = (*position)[0];
	tn->position[1] = (*position)[1];
	tn->up = NULL;
	tn->down = NULL;
	tn->right = NULL;
	tn->left = NULL;

	return tn;
}


BOOL isTreeNodeIsLeaf(treeNode* tn) {

	return (tn->up == NULL)
		&& (tn->down == NULL)
		&& (tn->right == NULL)
		&& (tn->left == NULL) ? TRUE : FALSE;

}