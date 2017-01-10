//
// Created by Ben Fishman on 09/01/2017.
//


#include <MacTypes.h>
#include <stdlib.h>
#include "../Game.h"

static int cti(char idx){
    if (idx >= 'A' && idx < 'A' + BOARD_SIZE) {
        return idx - 'A';
    }
    else if (idx >= '0' && idx < '0' + BOARD_SIZE) {
        return idx - '0';
    }
    else{
        return NULL;
    }
}

static int inboard(int idx){
    if(idx >= 0 && idx <BOARD_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

static Position findCheapestCell(Board board, Position* pos){
    int max = 0;
    Position pmax;
    int cr = cti(pos[0]);
    int cc = cti(pos[1]);
    int mr,mc;

    for(int j=cr -1; j<= cr +1; j ++){
        if (inboard(cr) && inboard(cc) && (board[cr][cc] > max)){
            max = board[cr][cc];
            mr = cr;
            mc = cc;
        }
    }
    if (max > 0){
        pmax[0] = 'A' + mr;
        pmax[1] = '0' + mc;

        return pmax;
    }
    else{
        return NULL;
    }
}

static Position createPos(int i, int j){
    Position p;
    p[0] = 'A' + i;
    p[1] = '0' + j;

    return p;
}

static PositionArray* allocateNewPa(){
    PositionArray* pa = (PositionArray*) malloc(sizeof(PositionArray));
    pa->logical_size= 0;
    pa->physical_size=0;
    pa->positions= NULL;

    return pa;
}

static void insertNewPos(PositionArray*pa ,Position p){
    if (pa->logical_size <= pa->physical_size-1) {
        pa->logical_size++;
        pa->positions[pa->logical_size] = p;
    }
    else{
        pa->physical_size= (pa->physical_size)*2 + 1;
        pa->positions = (Position*) realloc(pa->positions,sizeof(Position)*(pa->physical_size));
        pa->logical_size++;
        pa->positions[pa->logical_size] = p;
    }
}

PositionArray* greedyCheapPath(Board board, Position* src, Position* dst){
    int xr= cti(src[0]), xc=cti(src[1]);

    int yr= cti(dst[0]), yc=cti(dst[1]);

    Position*  p;

    PositionArray* pa = allocateNewPa();

    while((inboard(xr) && inboard(xc)) && (xr != yr && xc != yc)){
        p = createPos(xr,xc);
        insertNewPos(pa,*p);
        p = findCheapestCell(board,p);

        xr= cti(p[0]);
        xc= cti(p[1]);
    }

    if (xr != yr && xc != yc){
        return pa;
    }
    else{
        return NULL;
    }

}
