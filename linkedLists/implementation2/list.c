#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* create an empty list. Use the item_eq_fn to compare
whether two items are equal or not
*/
list *
create_list(int (*item_eq_fn) (void*,void*))
{
	list * retVal = malloc (sizeof (*retVal));
	assert (retVal != NULL);

	retVal->item = NULL;
	retVal->link = NULL;
	retVal->cmpFunc = item_eq_fn;

	return retVal;
}

/* add an item to a list */
list* list_insert(list* lp, void* item)
{
	assert (lp != NULL);
	list * p = lp;

	if (lp->item == NULL)
	{
		lp->item = item;
		return lp;
	}

	while (p->link != NULL)
		p = p->link;

	list * newItem = malloc (sizeof (*newItem));
	assert (newItem != NULL);

	p->link = newItem;
	newItem->link = NULL;
	newItem->item = item;
	newItem->cmpFunc = p->cmpFunc;

	return lp;
}

/* remove an item from a list */
list* list_remove(list* lp, void* item)
{
	list * p = lp;
	list * last = lp;

	assert (lp != NULL);

	if (lp->item == NULL)
		return lp;

	while (p != NULL)
	{
		if (p->cmpFunc (p->item, item))
		{
			last->link = p->link;
			free (p->item);
			free (p);

			break;
		}
		else
		{
			last = p;
			p = p->link;
		}
	}

	return lp;
}

/* returns true (non-zero) if item is in the list */
int list_find(list* lp, void* item)
{
	list * p = lp;

	while (p != NULL)
	{
		if (p->cmpFunc (p->item, item))
			return 1;
		p = p->link;
	} 

	return 0;
}

/* free all memory used by lp */
void destroy_list(list* lp)
{
	list * p = lp;

	while (p != NULL)
	{
		p = lp->link;
		free (lp->item);
		lp->item = NULL;
		free (lp);
		lp = p;
	}

}

