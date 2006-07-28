/*
   NodeTest.c - a test suite for the Node.c & Node.h files

   Author: Adam Parkin
   Date: July 19, 2006
*/

#include "Node.h"
#include <stdio.h>

int main (void)
{
	Node * someNode = createNode (5);

	printf ("somenode has value: '");
	printNode (someNode);
	printf ("'\n");
	destroyNode (someNode);
	
	Node * head = appendNode (NULL, createNode (0));
	Node * next = (appendNode (head, createNode (1)))->next;

	printf ("head: '");
	printNode (head);
	printf ("'   tail: '");
	printNode (next);
	printf ("'\n");

	printf ("head->next and tail %s the same\n", (head->next == next) ? "are" : "are not");

	destroyNode (next);
	destroyNode (head);
	return 0;
}
