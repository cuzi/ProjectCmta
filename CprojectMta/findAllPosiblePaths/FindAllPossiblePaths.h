//
// 
//

#ifndef CPROJECTMTA_CREATEPATHTREE_H
#define CPROJECTMTA_CREATEPATHTREE_H

#include "../Game.h"

void connectAllBoardTreeNodes(treeNode* tn, int arrSize, Board board);
void connectTreeNodeWith(char direction, treeNode* base, treeNode* next);
pathTree findAllPossiblePaths(Board board, Position *startingPosition);
void connectTreeNodeWithCoordinates(int x, int y, char direction, treeNode* source, int arrSize, Board board);


#endif //CPROJECTMTA_CREATEPATHTREE_H