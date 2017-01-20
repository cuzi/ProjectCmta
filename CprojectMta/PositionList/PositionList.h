//
// Created by Ben Fishman haomo on 09/01/2017.
//

#ifndef CPROJECTMTA_POSITIONLIST_H
#define CPROJECTMTA_POSITIONLIST_H

typedef char Position[2];

typedef struct _PositionListCell {
    Position* position;
    struct _PositionListCell* next;
} PositionListCell;

typedef struct _PositionList {
    PositionListCell *head, *tail;
} PositionList;

PositionList* makeEmptyPositionList();
PositionListCell* CreateNewNode(Position data);
void insertDataToEndPositionList(PositionList* lst, Position data);
void freePositionList(PositionList* lst);

#endif //CPROJECTMTA_POSITIONLIST_H
