//
//  GameFn.c Implement global functions
//



#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

BOOL isCapLetterInBoard(char c) {
	return c >= 'A' && c < 'A' + BOARD_SIZE ? TRUE : FALSE;

}


BOOL isNumberInBoard(char c) {
	return c >= '0' && c < '0' + BOARD_SIZE ? TRUE : FALSE;
}


void toUpperChar(char *c) {
	*c = (*c <= 'z' && *c >= 'a') ? *c - 32 : *c;
}