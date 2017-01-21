//
// Created by Fishman Ben on 20/01/2017.
//


#include <stddef.h>
#include "../CprojectMta/PositionList/PositionList.h"
#include "../CprojectMta/Game.h"
#define DELETE 1;
#define KEEP 0;

PositionList* findTheCheapestPath(Board board, pathTree* tree, Position* dst){
    PositionList* pa = findCheapestPathListAux(board, tree, dst);

    return pa;
}

static PositionList* findCheapestPathListAux(Board board, pathTree* tree, Position* dst){
    PositionList* pl = makeEmptyPositionList();

    insertDataToEndPositionList(pl, tree->root->position);
    findCheapestPathRec(pl, tree->root, dst);
    return pl;
}

static int findCheapestPathRec(PositionList* pl,treeNode* node, Position* dst) {
    
    if (node == NULL) {
        return DELETE;
    }
    if (node == dst) {
        insertDataToEndPositionList(pl, node->position);
        return KEEP;
    } else {
        // continue searching
        insertDataToEndPositionList(pl, node->position);

        if ((findCheapestPathRec(pl, node->up, dst) &&
             findCheapestPathRec(pl, node->down, dst) &&
             findCheapestPathRec(pl, node->left, dst) &&
             findCheapestPathRec(pl, node->right, dst)) == 1) {
            deleteLastNode(pl);
        }// cant continue search from that node , delete it
        else {
            return KEEP;
        }
    }
}
