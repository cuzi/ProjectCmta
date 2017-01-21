//
// Created by Fishman Ben on 20/01/2017.
//


#include <stddef.h>
#include "../PositionList/PositionList.h"
#include "../Game.h"
#include "FindCheapestPathList.h"
#define DELETE 1;
#define KEEP 0;

static int findCheapestPathRec(PositionList* pl,treeNode* node, treeNode*  tnDst) {

    if (node == NULL) {
        return DELETE;
    }
    if (node == tnDst) {
        insertDataToEndPositionList(pl, node->position);
        return KEEP;
    }
    else {
        // continue searching
        insertDataToEndPositionList(pl, node->position);

        if ((findCheapestPathRec(pl, node->up, tnDst) && findCheapestPathRec(pl, node->down, tnDst) &&
             findCheapestPathRec(pl, node->left, tnDst) && findCheapestPathRec(pl, node->right, tnDst)) == 1){

            deleteLastNode(pl);
            return DELETE;
        } // cant continue search from that node , delete it
        else {
            return KEEP;
        }
    }
}

static PositionList* findCheapestPathListAux(Board board, pathTree* tree, treeNode* tnDst){
    PositionList* pl = makeEmptyPositionList();
    findCheapestPathRec(pl, tree->root, tnDst);
    return pl;
}

PositionList* findTheCheapestPath(Board board, pathTree* tree, Position* dst){
    treeNode* tnDst;
    tnDst = findTheCheapestPathEndNode(board, tree->root, dst);

    PositionList* pa = findCheapestPathListAux(board, tree, tnDst);

    return pa;
}
