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
	*tn->position = *position;
	tn->up = NULL;
	tn->down = NULL;
	tn->right = NULL;
	tn->left = NULL;

	return tn;
}