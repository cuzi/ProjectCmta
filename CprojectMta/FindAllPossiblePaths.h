//
// 
//

#ifndef CPROJECTMTA_CREATEPATHTREE_H
#define CPROJECTMTA_CREATEPATHTREE_H

#include "Game.h"

treeNode* connectAllBoardTreeNodes(Board board, treeNode* tn, Position** positions);
void connectTreeNodeWith(char direction, treeNode* base, treeNode* next);

#endif //CPROJECTMTA_CREATEPATHTREE_H