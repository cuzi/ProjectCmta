//
// Gready cheap path header file
//

#include "../Game.h"

#ifndef CPROJECTMTA_GREEDYCHEAPPATH_H
#define CPROJECTMTA_GREEDYCHEAPPATH_H

PositionArray* greedyCheapPath(Board board, Position* src, Position* dst);
void printPositionArray(PositionArray* pa);
#endif //CPROJECTMTA_GREEDYCHEAPPATH_H
