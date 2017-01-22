//
// Created by Ben Fishman on 22/01/2017.
//

#ifndef CPROJECTMTA_LOADBOARDFROMBINFILE_H
#define CPROJECTMTA_LOADBOARDFROMBINFILE_H

#include "../Game.h"
#include "../streamIo/StreamIo.h"

int readPosition(FILE* file,Board brd,buffer* buff, int* buf_len);
#endif //CPROJECTMTA_LOADBOARDFROMBINFILE_H
