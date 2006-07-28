/*
  Node.h - the interface to a Node "module" 

  Author(s) - Adam Parkin
  Date: July 19, 2006
*/

#ifndef NODE_H
#define NODE_H

#include "NodeData.h"

/* define the structure of a Node object */
typedef struct node_struct {
	NodeData data;			/* the data contained in the node */
	struct node_struct * next;	/* a pointer to the next node */
} Node;

/* functions for working with nodes */

/* create a new node object containing data */
Node * createNode (NodeData data);

/* free all memory used by someNode. someNode must have been allocated by
	a call to createNode */ 
void destroyNode (Node * head);

/* appends newNode to head in a linked list fashion,
	if head is NULL returns newNode, else returns
	head */
Node * appendNode (Node * head, Node * newNode);

/* print out the contents of someNode to STDOUT */
void printNode (Node * someNode);
	

#endif
