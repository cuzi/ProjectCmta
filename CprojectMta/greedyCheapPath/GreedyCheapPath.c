//
// GreadyCheapPath Module is create a gready cheap path between to positions and return it as a pointer to PositionArray
//

#include <stdlib.h>
#include <stdio.h>
#include "../Game.h"
#include "../LoadBoardFromBinFile/LoadBoardFromBinFile.h"
#include "../Position.h"

static void copyBoard(Board b1, Board b2) {
	for (int i = 0; i<BOARD_SIZE; i++) {
		for (int j = 0; j<BOARD_SIZE; j++) {
			if (b1[i][j] != 0){
				b2[i][j] = b1[i][j];
			}
		}
	}
}

static Position* findCheapestCell(Board b, Position* pos){
    int min = 256;
    Position pmin;

    int moves[8] = {-1,0,1,0,0,-1,0,1};
    int cr = coordinateToInt(*pos[0]);
    int cc = coordinateToInt((*pos + 1)[0]);
    int mr,mc, minr, minc;
    int found = 0;

    for(int i = 0; i <=6; i+=2){
            mr = cr+moves[i];
            mc = cc +moves[i+1];

            if (inboard(mr) && inboard(mc) && b[mr][mc] < min && b[mr][mc] != 0){
                min = b[mr][mc];
                minr = mr;
                minc = mc;
                found=1;
        }

    }
    if (found == 1){

        pmin[0] = 'A' + minr;
        pmin[1] = '1' + minc;
        b[minr][minc] = 0;

        return &pmin;
    }
    else{
        return NULL;
    }
}


void printPositionArray(PositionArray* pa){
    Position* p;
    if(pa){
       for(int i=0; i<pa->logical_size;i++){
           p = pa->positions[i];
           printf("(%c , %c) -> ",pa->positions[i][0],pa->positions[i][1]);
       }
        printf(" -|");
    }
    else{
        printf("Position array is empty");
    }
}

static PositionArray* allocateNewPa(){
    PositionArray* pa = (PositionArray*) malloc(sizeof(PositionArray));
    pa->logical_size  = 0;
    pa->physical_size = 0;
    pa->positions     = NULL;

    return pa;
}

static void insertNewPos(PositionArray*pa ,Position* p){
    if (pa->logical_size <= pa->physical_size-1) {
        pa->positions[pa->logical_size][0]= *p[0];
        pa->positions[pa->logical_size][1]= (*p + 1)[0];
        pa->logical_size++;
    }
    else{
        pa->physical_size= (pa->physical_size)*2 + 1;
        pa->positions = (Position*) realloc(pa->positions,sizeof(Position)*(pa->physical_size));
        pa->positions[pa->logical_size][0]= *p[0];
        pa->positions[pa->logical_size][1]= (*p + 1)[0];
        pa->logical_size++;

    }
}

PositionArray* greedyCheapPath(Board board, Position* src, Position* dst){
    int xr= coordinateToInt(*src[0]), xc=coordinateToInt((*src + 1)[0]);
    int yr= coordinateToInt(*dst[0]), yc=coordinateToInt((*dst + 1)[0]);
    Position* p;
    PositionArray* pa = allocateNewPa();
	Board b;

	initialize_board(b);
	copyBoard(board, b);

    p = createPos(xr,xc);
    insertNewPos(pa, p);
    b[xr][xc]=0;

    while((inboard(xr) && inboard(xc)) && !(xr == yr && xc == yc)){

        p = findCheapestCell(b,p);

        if (p == NULL){
            free(pa);
            return NULL;
        }
        else{
            insertNewPos(pa, p);
            xr= coordinateToInt(**p);
            xc= coordinateToInt(*(*p + 1));
        }
    }

    if (xr == yr && xc == yc){
        return pa;
    }
    else{
        return NULL;
    }

}