//
// Created by Ben Fishman on 10/01/2017.
//

#ifndef CPROJECTMTA_STREAMIO_H
#define CPROJECTMTA_STREAMIO_H

#include <stdio.h>
#include "../Game.h"

int saveFile(char* fileName, Board obj, char* mode);
int readFile(char* fileName,Board* obj, char* mode);
int readPosition(FILE* file,Board brd);
#endif //CPROJECTMTA_STREAMIO_H
