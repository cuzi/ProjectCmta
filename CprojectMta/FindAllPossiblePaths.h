//
// 
//

#ifndef CPROJECTMTA_CREATEPATHTREE_H
#define CPROJECTMTA_CREATEPATHTREE_H

#include "Game.h"

void connectAllBoardTreeNodes(treeNode* tn, Position** positions);
void connectTreeNodeWith(char direction, treeNode* base, treeNode* next);
pathTree findAllPossiblePaths(Board board, Position *startingPosition);
BOOL isPositionInArray(Position** positions, Position *position);
void addPositionToArray(Position** positions, Position* position);
void connectTreeNodeWithCoordinates(int x, int y, char direction, treeNode* source, Position** positions);

#endif //CPROJECTMTA_CREATEPATHTREE_H