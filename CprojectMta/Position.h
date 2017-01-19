//
// Position module header file
//

#ifndef CPROJECTMTA_POSITION_H
#define CPROJECTMTA_POSITION_H

#include "Game.h"


Position* createEmptyPos();
Position* createPos(int i, int j);
BOOL inboard(int idx);
int coordinateToInt(char idx);
BOOL isEqualPos(Position a, Position b);
BOOL isPositionOnBoard(Position pos);

#endif //CPROJECTMTA_POSITION_H