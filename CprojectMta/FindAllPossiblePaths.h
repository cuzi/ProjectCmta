//
// 
//

#ifndef CPROJECTMTA_CREATEPATHTREE_H
#define CPROJECTMTA_CREATEPATHTREE_H

#include "Game.h"

void connectAllBoardTreeNodes(treeNode* tn, Position* positions, int arrSize);
void connectTreeNodeWith(char direction, treeNode* base, treeNode* next);
pathTree findAllPossiblePaths(Board board, Position *startingPosition);
BOOL isPositionInArray(Position *position, Position* positions, int arrSize);
//void addPositionToArray(Position** positions, Position* position);
void connectTreeNodeWithCoordinates(int x, int y, char direction, treeNode* source, Position* positions, int arrSize);


#endif //CPROJECTMTA_CREATEPATHTREE_H