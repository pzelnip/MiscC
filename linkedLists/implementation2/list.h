
#ifndef LIST_H
#define LIST_H

typedef struct list_struct {
	void *item;
	int (*cmpFunc) (void *, void *);
	struct list_struct *link;
} list;

/* create an empty list. Use the item_eq_fn to compare
whether two items are equal or not
*/
list *
create_list(int (*item_eq_fn) (void*,void*));

/* add an item to a list */
list* list_insert(list* lp, void* item);

/* remove an item from a list */
list* list_remove(list* lp, void* item);

/* returns true (non-zero) if item is in the list */
int list_find(list* lp, void* item);

/* free all memory used by lp */
void destroy_list(list* lp);

#endif
