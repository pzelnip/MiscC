/*
   LinkedListTest.c - a test suite for the LinkedList API 

   Author: Adam Parkin
   Date: July 19, 2006
*/

#include "LinkedList.h"
#include <stdio.h>

int main (void)
{
	LinkedList * list = createList();

	printf ("contents of empty list: '");
	printList (list);
	printf ("'\n");

	/* try destroying an empty list */
	destroyList (list);
	list = NULL;

	list = createList();
	addData (list, 5);
	printf ("contents of list with 1 item: '");
	printList (list);
	printf ("'\n");
	
	addData (list, 7);
	addDataAtStart (list, 2);

	/* should get list 2 5 7 */
	printf ("contents of list with 3 items: '");
	printList (list);
	printf ("'\n");

	/* should get "removed 1st item: 2  list is now '5 7'" */
	printf ("removed 1st item: %d  list is now '", removeFirst(list));
	printList (list);
	printf ("'\n");

	printf ("removed last item: %d list is now '", removeLast (list));
	printList (list);
	printf ("'\n");
	printf ("removed last item: %d list is now '", removeLast (list));
	printList (list);
	printf ("'\n");
	
	/* list should now be empty */
	printf ("list should be empty: '");
	printList (list);
	printf ("'\n");

	/* add a few items */
	addData (addData(addData(list, 10), 20), 30);
	printf ("after chaining addData calls: '");
	printList (list);
	printf ("'\n");

	destroyList (list);

	return 0;
}
