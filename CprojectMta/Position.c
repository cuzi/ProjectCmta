//
// Position.c position module
//


#include <stdio.h>
#include <stdlib.h>
#include "Game.h"


Position* createEmptyPos() {
	Position* pos = (Position*)malloc(sizeof(Position));
	*pos[0] = NULL;
	*pos[1] = NULL;

	return &pos;
}