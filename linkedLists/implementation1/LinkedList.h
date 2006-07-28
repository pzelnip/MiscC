/*
  LinkedList.h - the interface to a LinkedList "module" 

  Author(s) - Adam Parkin
  Date: July 19, 2006
*/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "NodeData.h"

/* define a LinkedList "type" */

typedef struct llist_struct {
	Node * head;
	Node * tail;
} LinkedList;

/* functions for manipulating linked lists */

/* create a new empty linked list, or NULL if one cannot be created */
LinkedList * createList (void);

/* print the contents of the linked list to STDOUT */
void printList (LinkedList * list);

/* free all memory used by the linked list passed in.  Note
	that list must have been created by a call to 
	createList */
void destroyList (LinkedList * list);

/* adds data to the end of the list.  Note that the return value
	is the same list as the list passed in, but returning 
	the list from the function allows one to "chain" calls
	to addData like so: 
	addData(addData(addData (x, list), y), z) */
LinkedList * addData (LinkedList * list, NodeData data);

/* adds data to the beginning of the list.  Return type is same
	as addData */
LinkedList * addDataAtStart (LinkedList * list, NodeData data);

/* remove and return the last element of the list, if list is empty
	program is halted with an error message */
NodeData removeLast (LinkedList * list);

/* remove and return the first element of the list, if list is empty
	program is halted with an error message */
NodeData removeFirst (LinkedList * list);

#endif
