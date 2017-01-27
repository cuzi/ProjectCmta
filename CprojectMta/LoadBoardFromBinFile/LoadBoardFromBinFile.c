//
// Created by Ben Fishman on 22/01/2017.
//

#include "../Game.h"
#include "../streamIo/StreamIo.h"
#include "LoadBoardFromBinFile.h"

void initialize_board(Board brd) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			brd[i][j] = 0;

		}
	}
}

void loadBoardFromBinFile(char* file_name, Board brd) {
	int read;
	int buf_len = 0;
	buffer buff = 0;

	initialize_board(brd);
	FILE *f = fopen(file_name, "rb");
	if (!f)
	{
		printf("Unable to open %s file!\n", file_name);
	}
	else {
		read = readPosition(f, brd, &buff, &buf_len);

		while (read) {
			read = readPosition(f, brd, &buff, &buf_len);
		}
	}
	fclose(f);
}

