//
// Position module header file
//

#ifndef CPROJECTMTA_TREEPATH_H
#define CPROJECTMTA_TREEPATH_H

#include "Game.h"


pathTree* createNewPathTree();
treeNode* createTreeNode(Position* position);
BOOL isTreeNodeIsLeaf(treeNode* tn);

#endif //CPROJECTMTA_TREEPATH_H