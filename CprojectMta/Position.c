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

	(*p)[0] = 'A' + i;
	(*p)[1] = '1' + j;

	return p;
}

BOOL inboard(int idx) {
	if (idx >= 0 && idx <BOARD_SIZE) {
		return TRUE;
	}
	return FALSE;
}

BOOL isEqualPos(Position a, Position b) {
	if (a[0] == b[0] &&
		a[1] == b[1]) {
		return TRUE;
	}
	return FALSE;
	
}

BOOL isPositionOnBoard(Position pos) {
	return inboard(coordinateToInt(pos[0])) && 
		   inboard(coordinateToInt(pos[1])) ? 
				TRUE : FALSE;
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