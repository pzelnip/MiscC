#include "list.h"
#include "comps.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printslist (list * l);
void printilist (list * l);

int main (void)
{
	list * slist = create_list(&strComp);
	char * a = malloc (6);
	strcpy (a, "hello"); 
	char * b = malloc (6);
	strcpy (b, "world"); 
	char * c = malloc (100);
	strcpy (c, "foo bar!"); 
	printslist (slist);
	slist = list_insert (slist, a);
	printslist (slist);
	slist = list_insert (slist, b);
	printslist (slist);
	slist = list_insert (slist, c);
	printslist (slist);

	slist = list_remove (slist, "dlfkajflsadkfja");
	printslist (slist);
	slist = list_remove (slist, "world");
	printslist (slist);
	printf ("world %s found in ", (list_find (slist, "world")) ? "was" : "was not");
	printslist (slist);
	printf ("hello %s found in ", (list_find (slist, "hello")) ? "was" : "was not");
	printslist (slist);

	destroy_list (slist);

	list * ilist = create_list(&intComp);
	printilist (ilist);

	int x = 0;
	for (x = 0; x < 5; x++)
	{
		int * a = malloc (sizeof (int));
		*a = x;
		list_insert (ilist, a);
		printilist (ilist);
	}

	x = 3;
	ilist = list_remove (ilist, &x);
	printilist (ilist);
	x = 10;
	ilist = list_remove (ilist, &x);
	printilist (ilist);

	x = 1;
	printf ("%d %s found in ", x, (list_find (ilist, &x)) ? "was" : "was not");
	printilist (ilist);
	x = 4;
	printf ("%d %s found in ", x, (list_find (ilist, &x)) ? "was" : "was not");
	printilist (ilist);

	x = 10;
	printf ("%d %s found in ", x, (list_find (ilist, &x)) ? "was" : "was not");
	printilist (ilist);

	destroy_list (slist);
	
	return 0;
}

void printslist (list * l)
{
	if (l == NULL || l->item == NULL)
	{
		printf ("list is empty\n");
		return;
	}

	printf ("[");
	while (l != NULL)
	{
		printf ("'%s', ", (char *)l->item);
		l = l->link;
	}
	printf ("]\n");
}

void printilist (list * l)
{
	if (l == NULL || l->item == NULL)
	{
		printf ("list is empty\n");
		return;
	}

	printf ("[");
	while (l != NULL)
	{
		printf ("'%d', ", *(int *)l->item);

		l = l->link;
	}
	printf ("]\n");
}
	
