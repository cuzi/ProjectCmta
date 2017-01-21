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

//delete current node from list
void deleteNode(PositionList* pl, PositionListCell* pc){
    PositionListCell* tmp ,* crm;
    tmp = pl->head;

    if (pl->head == pc == pl->tail){
        free(pl->head);
        pl->head = pl->tail = NULL;
    } // list length is 1
    else if (pl->head == pc){
        crm = pl->head;
        pl->head = pl->head->next;
        free(crm);
    }// head
    else{

        while (tmp->next != NULL && tmp->next != pc) {
            tmp = tmp->next;
        }

        if (tmp->next == pc){

            if (tmp->next == pl->tail){
                pl->tail = tmp;
            } // end

            crm = tmp->next;
            tmp->next = tmp->next->next;
            free(crm);

        } // node found
    } // middle

}

//delete last node from list
void deleteLastNode(PositionList* pl){
    PositionListCell* tmp ;
    tmp = pl->head;

    if(pl->head != NULL && pl->tail != NULL){

        if (pl->head == tmp == pl->tail){
            free(pl->head);
            pl->head = pl->tail = NULL;
        } // list length is 1
        else{

            while (tmp->next != pl->tail) {
                tmp = tmp->next;
            }
            free(pl->tail);
            pl->tail = tmp;
        }
    }


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