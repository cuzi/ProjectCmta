//
// Created by Ben Fishman on 10/01/2017.
//
#include <stdio.h>
#include "../Game.h"
#include "../Position.h"

typedef unsigned char buffer;

typedef buffer pos;
#define MASK_BIT_RANGE(START, END, TYPE)  ((TYPE)((1 << (END - START + 1)) - 1) << START)

int saveFile(char* fileName,Board obj, char* mode){

    FILE *ptr_myfile;

    ptr_myfile=fopen(fileName,"wb");
    if (!ptr_myfile)
    {
        printf("Unable to open %s file!\n", fileName);
        return 1;
    }
    for (int row=0; row < BOARD_SIZE; row++)
    {
        fwrite(obj[row], sizeof(obj[row]), 1, ptr_myfile);
    }
    fclose(ptr_myfile);
    return 0;
}


int readFile(char* fileName,Board* obj, char* mode){

    unsigned char r[BOARD_SIZE];
    FILE *ptr_myfile;

    ptr_myfile=fopen(fileName,mode);
    if (!ptr_myfile)
    {
        printf("Unable to open %s file!\n", fileName);
        return 1;
    }
    for (int row=0; row < BOARD_SIZE; row++)
    {
        fread(r, sizeof(unsigned char)*BOARD_SIZE,1,ptr_myfile);
        for(int i=0;i<BOARD_SIZE;i++){
            *obj[row][i] = r[i];
        }
    }
    fclose(ptr_myfile);
    return 0;
}

static int writeToBuffer(FILE* file, buffer* buff,int* buf_len){
    int succes;
    file = fopen(file,"rb");
    if (!file)
    {
        printf("Unable to open %s file!\n", file);
        return 0;
    }
    else{
        succes = fread(buff, sizeof(buffer), 1, file);
        if (succes){
            buf_len = sizeof(buffer);
            return succes;
        }
        else{
            return succes;
        }
    }
}

static int readFromBuffer(FILE* file,buffer* data, int bits, buffer* buffer,int* buf_len){

    unsigned char bit =1;
    int state;

    for(int i =0 ; i< bits;i++){
        if(*buf_len == 0){
            state=writeToBuffer(file,&buffer,buf_len);
        }
        if(state ==0){
            return 0;
        }
        else{
            *buf_len--;
            *data = bit | *buffer;
            *data <<= 1;
        }

    }
    return 1;

}



int readPosition(FILE* file,Board brd){
    unsigned char x=0,y=0,score=0;
    int buf_len=0;
    int row,col;
    buffer buff=0;
    if(readFromBuffer(file,x,3,&buff,&buf_len) &&
       readFromBuffer(file,y,3,&buff,&buf_len) &&
       readFromBuffer(file,score,8,&buff,&buf_len)) //reading position succesfully
    {
        row = coordinateToInt(x);
        col = coordinateToInt(y);
        brd[row][col] = score;

        return 1;
    }
    else{
        return 0;
    }


}
