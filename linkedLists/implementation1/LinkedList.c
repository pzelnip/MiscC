

#include "LinkedList.h"
#include <assert.h>	/* for assert() */
#include <stdlib.h>	/* for malloc & free */
#include <stdio.h>	/* for printf */

/* create a new empty linked list, or NULL if one cannot be created */
LinkedList * createList (void)
{
	LinkedList * retVal = malloc (sizeof (*retVal));

	retVal->head = NULL;
	retVal->tail = NULL;

	return retVal;
}


/* print the contents of the linked list to STDOUT */
void printList (LinkedList * list)
{
	Node * iterator = list->head;

	while (iterator != NULL)
	{
		printNode (iterator);
		printf(" ");
		iterator = iterator->next;
	}
}

/* free all memory used by the linked list passed in.  Note
	that list must have been created by a call to 
	createList */
void destroyList (LinkedList * list)
{
	/* free all nodes */
	while (list->head != NULL)
	{
		Node * next = list->head->next;
		free (list->head);
		list->head = next;
	}

	assert (list->head == NULL);

	/* not really necessary because we're about to free this memory, 
		but good practice nonetheless */
	list->tail = NULL;

	/* free the linked list structure */
	free (list);
}

/* adds data to the end of the list.  Note that the return value
	is the same list as the list passed in, but returning 
	the list from the function allows one to "chain" calls
	to addData like so: 
	addData(addData(addData (x, list), y), z) */
LinkedList * addData (LinkedList * list, NodeData data)
{	
	Node * newTail = createNode (data);

	/* if list is empty, update both head & tail */
	if (list->head == NULL)
	{
		assert (list->tail == NULL);
		list->head = list->tail = newTail;
	}
	else
	{
		appendNode (list->tail, newTail); 
		list->tail = newTail;
	}

	return list;
}

/* adds data to the beginning of the list.  Return type is same
	as addData */
LinkedList * addDataAtStart (LinkedList * list, NodeData data)
{
	list->head = appendNode (createNode (data), list->head);

	/* if list was empty, update the tail node */
	if (list->tail == NULL)
		list->tail = list->head;

	return list;
}

/* remove and return the last element of the list, if list is empty
	program is halted with an error message */
NodeData removeLast (LinkedList * list)
{
	/* make sure list is not empty */
	assert (list->head != NULL && list->tail != NULL);

	/* grab the data to return */
	NodeData retVal = list->tail->data;

	Node * newEnd;

	/* special case: when list has only 1 element */
	if (list->head == list->tail)
	{
		newEnd = NULL;
		list->head = newEnd;
	}
	else
	{
		/* find new end of list (the node preceeding tail).  Note that
			this is currently a O(n) algorithm, could be improved
			to O(1) if Node were doubly-linked instead of singly-linked */
		newEnd = list->head;		
		while (newEnd->next != list->tail)
			newEnd = newEnd->next;
		newEnd->next = NULL;
	}

	/* assert (newEnd == the new end of the list) */
	/* assert (retVal == the data to be returned) */

	/* free up the node & update the list */
	destroyNode (list->tail);
	list->tail = newEnd;

	return retVal;
}

/* remove and return the first element of the list, if list is empty
	program is halted with an error message */
NodeData removeFirst (LinkedList * list)
{
	/* make sure list is not empty */
	assert (list->head != NULL && list->tail != NULL);

	/* get data to return */
	NodeData retVal = list->head->data;

	/* find new beginning of list, just a simple follow the link
		to the next node, so O(1) time */
	Node * newHead = list->head->next;

	/* special case: if list has only 1 element update tail */
	if (list->head == list->tail)
	{
		list->tail = newHead;
	}

	/* destroy the old node & update the head of the list */
	destroyNode(list->head);
	list->head = newHead;
	
	return retVal;
}

