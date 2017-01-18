//
// Position.c position module
//


#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Position.h"


Position* createEmptyPos() {
	Position* pos = (char *)malloc(sizeof(char) * 2) ;
	(*pos)[0] = NULL;
	(*pos)[1] = NULL;

	return pos;
}


Position* createPos(int i, int j) {
	Position* p = (char *)malloc(sizeof(char) * 2);

	(*p)[0] = '1' + i;
	(*p)[1] = 'A' + j;

	return p;
}

BOOL inboard(int idx) {
	if (idx >= 0 && idx <BOARD_SIZE) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int coordinateToInt(char idx) {
	if (isCapLetterInBoard(idx)) {
		return idx - 'A';
	}

	if (isNumberInBoard(idx)) {
		return idx - '1';
	}
	return -1;

}