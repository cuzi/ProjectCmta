//
// StreamIo module contain functions that interact with the file system
//
#include <stdio.h>
#include <stdlib.h>
#include "../Game.h"
#include "../Position.h"
#include "StreamIo.h"


static int writeToBuffer(FILE* file, buffer* buff, int* buf_len) {
	int succes;
	int a;
	succes = fread(buff, sizeof(buffer), 1, file);
	a = *buff;

	if (succes) {
		*buf_len = sizeof(buffer) * 8;
		return succes;
	}
	else {
		return succes;
	}
}

static int readFromBuffer(FILE* file, buffer* data, int bits, buffer* buffer, int* buf_len) {

	unsigned char bit = 1 << 7;
	int state = -1;
	int a;
	a = *buffer;
	for (int i = 0; i < bits; i++) {
		if (*buf_len == 0) {

			state = writeToBuffer(file, buffer, buf_len);
			a = *buffer;
		}
		if (state == 0) {
			return FALSE;
		}
		else {
			(*buf_len)--;
			(*data) <<= 1;
			*data |= ((bit & *buffer) >> 7);
			(*buffer) <<= 1;
		}

	}
	return TRUE;

}

int readPosition(FILE* file, Board brd, buffer* buff, int* buf_len) {
	unsigned char x = 0, y = 0, score = 0;
	int br, bc, bs;
	int row = 0, col = 0;

	br = readFromBuffer(file, &x, 3, buff, buf_len);
	bc = readFromBuffer(file, &y, 3, buff, buf_len);
	bs = readFromBuffer(file, &score, 8, buff, buf_len);

	if (br && bc && bs) //reading position successfully
	{
		row = x;
		col = y;
		brd[row][col] = score;

		return TRUE;
	}
	return FALSE;
	


}

static void flushBufferToFile(FILE *file, buffer buff) {
	fwrite(&buff, sizeof(buffer), 1, file);
}

void queueToBuffer(buffer data, int bits, FILE *file) {
	static buffer buff = 0;
	static short buffi = 0;

	if (!data && !bits) {
		buff <<= 8 - buffi;
		flushBufferToFile(file, buff);
		buff = buffi = 0;
	}

	for (int i = bits - 1; i >= 0; i--) {
		if (buffi == 8) {
			flushBufferToFile(file, buff);
			buff = buffi = 0;
		}

		buff <<= 1;

		buff |= (data >> i) & 1;
		buffi++;
	}
}

void saveBoardToBinFile(const char *filename, Board board) {
	FILE *file = fopen(filename, "wb");
	if (!file) {
		printf("Error opening file!\n");
		exit(1);
	}

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j]) {
				buffer row = i, col = j, cost = board[i][j];

				queueToBuffer(row, 3, file);
				queueToBuffer(col, 3, file);
				queueToBuffer(cost, 8, file);
			}
		}
	}

	queueToBuffer(0, 0, file);

	fclose(file);
}