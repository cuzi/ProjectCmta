//
// Created by Ben Fishman on 10/01/2017.
//
#include<stdio.h>
#include "../Game.h"

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

    unsigned char* r;
    FILE *ptr_myfile;

    ptr_myfile=fopen(fileName,mode);
    if (!ptr_myfile)
    {
        printf("Unable to open %s file!\n", fileName);
        return 1;
    }
    for (int row=0; row < BOARD_SIZE; row++)
    {
        fread(r,sizeof(unsigned char)*BOARD_SIZE,1,ptr_myfile);
        for(int i=0;i<BOARD_SIZE;i++){
            *obj[row][i] = r[i];
        }
    }
    fclose(ptr_myfile);
    return 0;
}

