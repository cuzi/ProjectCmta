/*
Name:		Ben Fishman
ID number:	203838495
Name:		Tomer Abenheimer
ID number:	203539564
File name:	main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


void main()
{
	Position* source = (Position*)malloc(sizeof(Position));
	Position* destination = (Position*)malloc(sizeof(Position));
	Board* board = (Board*)malloc(sizeof(Board));

    showMenu(source, destination, board);

	// TODO: free vars
}