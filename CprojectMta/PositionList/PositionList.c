//
// PositionList Module Implement Functions that belongs to PositionLit and PositionLitCell structs
//

#include <stdio.h>
#include <stdlib.h>
#include "PositionList.h"
#include "../Game.h"

// Free PositionListCell and he's childs
static void freePosListCell(PositionListCell *pc) {
	if (pc == NULL)
		return;

	freePosListCell(pc->next);
	free(pc);
}
// Free PositionList
void freePosList(PositionList *pl) {
	if (pl == NULL)
		return;
	freePosListCell(pl->head);
	free(pl);
}

//create a new Empty List
PositionList* makeEmptyPositionList()
{
	PositionList* lst = (PositionList*)malloc(sizeof(PositionList));
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
void deleteNode(PositionList* pl, PositionListCell* pc) {
	PositionListCell* tmp, *crm;
	tmp = pl->head;

	if (pl->head == pc == pl->tail) {
		free(pl->head);
		pl->head = pl->tail = NULL;
	} // list length is 1
	else if (pl->head == pc) {
		crm = pl->head;
		pl->head = pl->head->next;
		free(crm);
	}// head
	else {

		while (tmp->next != NULL && tmp->next != pc) {
			tmp = tmp->next;
		}

		if (tmp->next == pc) {

			if (tmp->next == pl->tail) {
				pl->tail = tmp;
			} // end

			crm = tmp->next;
			tmp->next = tmp->next->next;
			free(crm);

		} // node found
	} // middle

}

//delete last node from list
void deleteLastNode(PositionList* pl) {

	PositionListCell* t;
	PositionListCell* tmp = pl->head;

	if (pl->head->next == NULL)
	{
		free(pl->head);
		pl->head = NULL;
		pl->tail = NULL;
	}
	else
	{
		while (tmp->next != NULL)
		{
			t = tmp;
			tmp = tmp->next;
		}
		free(t->next);
		t->next = NULL;
		pl->tail = t;
	}

}


//insert the Node to the end of the list - before dummy tail
void insertDataToEndPositionList(PositionList* lst, Position data) {
	PositionListCell* newNode = CreateNewNode(data);
	if (lst->head == NULL) {
		lst->head = lst->tail = newNode;
	}
	else {

		PositionListCell* tmp = lst->head;
		PositionListCell* node = lst->head->next;
		while (node != NULL)
		{
			tmp = node;
			node = node->next;
		}
		lst->tail = newNode;
		tmp->next = lst->tail;
	}

}

//print list
void printPositionList(PositionList* lst)
{
	PositionListCell* tmp;
	Position* p;
	PositionListCell* node = lst->head;
	while (node->next != NULL)
	{
		tmp = node;
		node = node->next;
		p = tmp->position;

		printf(" (%c,%c) ->", (*p)[0], (*p + 1)[0]);
	}
	p = node->position;
	printf(" (%c,%c).", (*p)[0], (*p + 1)[0]);
}
