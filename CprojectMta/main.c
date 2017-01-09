/*
Name:		Ben Fishman
ID number:	203838495
Name:		Tomer Abenheimer
ID number:	203539564
File name:	main.c
*/

#include <stdio.h>
#include "main.h"


void main()
{
	Position source		 = malloc(sizeof(Position));
	Position destination = malloc(sizeof(Position));
	Board    board		 = malloc(sizeof(Board));
	int		 ans		 = 0;

	while (ans != 7) {
		ans = showMenu(&source, &destination, &board);
	}

	// TODO: free vars
}