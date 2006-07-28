/*
  Node.h - the implementation of the Node "module" 

  Author(s) - Adam Parkin
  Date: July 19, 2006
*/

#include "Node.h"
#include <stdlib.h>	/* for malloc, free, and NULL */
#include <assert.h>	/* for assert() */
#include <stdio.h>	/* for printf() */

/* create a new node object containing data */
Node * createNode (NodeData data)
{
	Node * newNode;

	/* Allocate memory for the new node using malloc, be sure
	   to check that it was successful */
	newNode = malloc (sizeof (Node));
	assert (newNode != NULL);

	/* copy data to the newly created node */
	newNode->data = data;

	/* terminate the node (initialize it's "next" field to NULL) */
	newNode->next = NULL;

	/* return the newly created node */
	return newNode;
}

/* free all memory used by someNode. someNode must have been allocated by
	a call to createNode */ 
void destroyNode (Node * someNode)
{
	free (someNode);
}

/* appends newNode to head in a linked list fashion,
	if head is NULL returns newNode, else returns
	head */
Node * appendNode (Node * head, Node * newNode)
{
	if (head == NULL)
		return newNode;

	head->next = newNode;
	return head;
}

/* print out the contents of someNode to STDOUT. */
void printNode (Node * someNode)
{
	if (someNode == NULL)
		printf ("--NULL NODE--");
	else
		printData (someNode->data);
}
