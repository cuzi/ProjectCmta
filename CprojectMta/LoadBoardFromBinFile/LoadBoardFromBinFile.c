//
// Created by Ben Fishman on 22/01/2017.
//

#include "../Game.h"
#include "../streamIo/StreamIo.h"

static void initialize_board(Board brd){
    for(int i=0 ;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            brd[i][j] = 0;

        }
    }
}

void loadBoardFromBinFile(char* file_name, Board brd){
    int read;
    initialize_board(brd);
    read = readPosition(file_name,brd);

    while(read){
        read = readPosition(file_name,brd);
    }
}

