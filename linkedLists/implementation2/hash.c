#include "hash.h"
#include <stdlib.h>
#include <assert.h>

/* create an empty list. Use the key_eq_fn to compare
whether two keys are equal or not
*/
hash *
create_hash(int (*key_eq_fn) (void*,void*))
{
	hash * retVal = malloc (sizeof (*retVal));
	assert (retVal != NULL);

	retVal->key = NULL;
	retVal->value = NULL;
	retVal->cmpFunc = key_eq_fn;

	return retVal;
}

/* returns true (non-zero) if insertion was succesful.
insert key k and value v into hashtable h.
*/
int
hash_insert(hash *h, void *k, void *v)
{
	assert (h != NULL);

	hash * h2 = h; 
	if (h->key != NULL)
	{
		h2 = malloc (sizeof (*h));
		assert (h2);

		while (h->link != NULL)
			h = h->link;

		h->link = h2;
	}

	h2->link = NULL;
	h2->cmpFunc = h->cmpFunc;
	h2->key = k;
	h2->value = v;
	return 1;
}



/* returns the value associated with key
if they key is in the hash or NULL if
not found
*/
void *
hash_search(hash *h, void *k)
{
	assert (h != NULL);

	if (h->key == NULL)
		return NULL;

	while (h != NULL)
	{
		if (h->cmpFunc (h->key, k))
			return h->value;

		h = h->link;
	}

	return NULL;
}

/* remove key and associated value from hash.
returns the value */
void *
hash_remove(hash *h, void *k)
{
	hash * last = h;
	void * retVal = NULL;

	/* special case: when the first element matches */
	if (h->cmpFunc (h->key, k))
	{
		free (h->key);
		retVal = h->value;

		hash * next = h->link;
		h->key = next->key;
		h->value = next->value;
		h->link = next->link;
		free (next);
	}
	else
	{

		while (h != NULL)
		{
			if (h->cmpFunc (h->key, k))
			{
				free (h->key);
				h->key = NULL;
				retVal = h->value;
			
				last->link = h->link;
				free (h);
			
				break;
			}
			else
			{
				last = h;
				h = h->link;
			}
		}
	}

	return retVal;
}

/* free all memory used by the hash */
void
hash_destroy(hash *h)
{
	while (h != NULL)
	{
		hash * n = h->link;
		free (h->key);
		h->key = NULL;
		free (h->value);
		h->value = NULL;
		h->cmpFunc = NULL;
		free (h);
		h = n;
	}
}



