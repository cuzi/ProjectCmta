//
// Load Board from bin file header
//

#ifndef CPROJECTMTA_LOADBOARDFROMBINFILE_H
#define CPROJECTMTA_LOADBOARDFROMBINFILE_H

#include "../Game.h"
#include "../streamIo/StreamIo.h"

int readPosition(FILE* file,Board brd,buffer* buff, int* buf_len);
void initialize_board(Board brd);
#endif //CPROJECTMTA_LOADBOARDFROMBINFILE_H
