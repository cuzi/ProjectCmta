//
//
//


#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "TreePath.h"
#include "Position.h"



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
	int i = 0;

	if (tn->up    != NULL) ++i;
	if (tn->down  != NULL) ++i;
	if (tn->right != NULL) ++i;
	if (tn->left  != NULL) ++i;

	return i == 1 ? TRUE : FALSE;
}