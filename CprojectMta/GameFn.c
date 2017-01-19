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

	return board[y][x];
}
// Quick sort algoritim
void quicksort(int *A, int len)
{
	if (len < 2) return;

	int pivot = A[len / 2];

	int i, j;
	for (i = 0, j = len - 1; ; i++, j--)
	{
		while (A[i] < pivot) i++;
		while (A[j] > pivot) j--;

		if (i >= j) break;

		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	quicksort(A, i);
	quicksort(A + i, len - i);
}

