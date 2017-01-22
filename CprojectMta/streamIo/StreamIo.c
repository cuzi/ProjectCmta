//
// Created by Ben Fishman on 10/01/2017.
//
#include <stdio.h>
#include "../Game.h"
#include "../Position.h"

typedef unsigned char buffer;

typedef buffer pos;
#define MASK_BIT_RANGE(START, END, TYPE)  ((TYPE)((1 << (END - START + 1)) - 1) << START)

static int writeToBuffer(FILE* file, buffer* buff,int* buf_len){
    int succes;
    succes = fread(buff, sizeof(buffer), 1, file);
    if (succes){
        *buf_len = sizeof(buffer)*8;
        return succes;
    }
    else{
        return succes;
    }
}

static int readFromBuffer(FILE* file,buffer* data, int bits, buffer* buffer,int* buf_len){

    unsigned char bit = 1<<7;
    int state;

    for(int i =0 ; i< bits;i++){
        if(*buf_len == 0){

            state=writeToBuffer(file,buffer,buf_len);
            printf("read from file to buffer\n");
        }
        if(state ==0){
            return 0;
        }
        else{
            (*buf_len)--;
            (*data) <<= 1;
            *data |= ((bit & *buffer)>>7);
            (*buffer) <<= 1;
        }

    }
    return 1;

}



int readPosition(FILE* file,Board brd){
    unsigned char x=0,y=0,score=0;
    int br,bc,bs;
    int buf_len=0;
    int row =0,col =0;
    buffer buff=0;
    br=readFromBuffer(file,&x,3,&buff,&buf_len);
    bc=readFromBuffer(file,&y,3,&buff,&buf_len);
    bs=readFromBuffer(file,&score,8,&buff,&buf_len);

    if(br && bc && bs) //reading position successfully
    {
        row = x;
        col = y;
        brd[row][col] = score;

        return 1;
    }
    else{
        return 0;
    }


}
