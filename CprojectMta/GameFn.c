//
//  GameFn.c Implement global functions
//



#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

BOOL isCapLetterInBoard(char c) {
	return c >= 'A' && c <= 'A' + BOARD_SIZE ? TRUE : FALSE;

}


BOOL isNumberInBoard(char c) {
	return c > '0' && c <= '0' + BOARD_SIZE ? TRUE : FALSE;
}


void toUpperChar(char *c) {
	*c = (*c <= 'z' && *c >= 'a') ? *c - 32 : *c;
}

int getPosValue(Position pos, Board board) {
	int x = coordinateToInt(pos[0]), y = coordinateToInt(pos[1]);

	return board[y][x] - '0';
}
// Quick sort algoritim

static void swap(int *a, int *b) {
	int *tmp = a;
	a = b;
	b = tmp;
}
static int partition(int *A, int start, int end) {
	int i = start + 1;
	int piv = A[start];
	for (int j = start + 1; j <= end; j++) {

		if (A[j] < piv) {
			swap(A[i], A[j]);
			i += 1;
		}
	}
	swap(A[start], A[i - 1]);  
	return i - 1;
}

void quick_sort(int *a, int start, int end) {
	if (start < end) {
		int pos = partition(a, start, end);
		quick_sort(a, start, pos - 1);    
		quick_sort(a, pos + 1, end); 
	}
}