//
// Created by Ben Fishman on 09/01/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "PositionList.h"
#include "../Game.h"


//create a new Empty List
PositionList* makeEmptyPositionList()
{
    PositionList* lst = (PositionList*) malloc(sizeof(PositionList));
    lst->head = NULL;
    lst->tail = NULL;

    return lst;
}

//create a new Node
PositionListCell* CreateNewNode(Position data)
{
    PositionListCell* newNode = (PositionListCell*)malloc(sizeof(PositionListCell));
    newNode->position = data;
    newNode->next = NULL;
    return newNode;
}

//insert the Node to the end of the list - before dummy tail
void insertDataToEndPositionList(PositionList* lst, Position data)
{
    PositionListCell* newNode = CreateNewNode(data);
    PositionListCell* tmp = lst->head;
    PositionListCell* node = lst->head->next;
    while(node->next!=NULL)
    {
        tmp = node;
        node = node->next;
    }
    newNode->next = lst->tail;
    tmp->next = newNode;
}


//free all memory allocations
void freePositionList(PositionList* lst)
{
    PositionListCell* tmp;
    PositionListCell* node = lst->head;
    while(node->next!=NULL)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(node);
}