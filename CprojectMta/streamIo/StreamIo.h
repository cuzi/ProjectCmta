//
// StreamIo module header file
//

#ifndef CPROJECTMTA_STREAMIO_H
#define CPROJECTMTA_STREAMIO_H

#include <stdio.h>
#include "../Game.h"
#define MASK_BIT_RANGE(START, END, TYPE)  ((TYPE)((1 << (END - START + 1)) - 1) << START)

typedef unsigned char buffer;

void saveBoardToBinFile(const char *filename, Board board);
void queueToBuffer(buffer data, int bits, FILE *file);
#endif //CPROJECTMTA_STREAMIO_H
