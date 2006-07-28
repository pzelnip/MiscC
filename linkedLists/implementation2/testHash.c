#include "hash.h"
#include "comps.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char * mallocString (char * a);
int * mallocInt (int x);
void printshash (hash * h);
void printihash (hash * h);

int main (void)
{
	hash * shash = create_hash (&strComp);

	printshash (shash);
	hash_insert (shash, mallocString ("key1"), mallocString("value1"));
	printshash (shash);

	hash_insert (shash, mallocString ("key2"), mallocString("value2"));
	printshash (shash);

	hash_insert (shash, mallocString ("key3"), mallocString("value3"));
	printshash (shash);


	char * c = "key1";
	char * v = hash_search (shash, c);
	printf ("key: '%s' has value %s\n", c, (v == NULL) ? "NULL" : v); 
	c = "key3";
	v = hash_search (shash, c);
	printf ("key: '%s' has value %s\n", c, (v == NULL) ? "NULL" : v); 
	c = "keydasflkja1";
	v = hash_search (shash, c);
	printf ("key: '%s' has value %s\n", c, (v == NULL) ? "NULL" : v); 

	c = "key2";
	printf ("removed '%s' from hash using key '%s', hash is now: ", (char *)hash_remove(shash, c), c);
	printshash (shash);

	c = "key1";
	printf ("removed '%s' from hash using key '%s', hash is now: ", (char *)hash_remove(shash, c), c);
	printshash (shash);

	hash_destroy (shash);

	hash * ihash = create_hash (&intComp);
	printihash (ihash);

	int x = 0;
	for (x = 0; x < 5; x++)
	{
		hash_insert (ihash, mallocInt(x), mallocInt (2 * x));
		printihash (ihash);
	}

	int k = 3;
	int * iv = hash_search (ihash, &k);
	printf ("key: '%d' has value %d\n", k, (iv == NULL) ? 0 : *iv); 
	

	k = 0;
	iv = hash_search (ihash, &k);
	printf ("key: '%d' has value %d\n", k, (iv == NULL) ? 0 : *iv); 

	k = 5;
	iv = hash_search (ihash, &k);
	printf ("key: '%d' has value %d\n", k, (iv == NULL) ? 0 : *iv); 


	k = 3;
	printf ("removed %d from hash using key %d, hash is now: ", *(int *)hash_remove(ihash, &k), k);
	printihash(ihash);

	k = 0;
	printf ("removed %d from hash using key %d, hash is now: ", *(int *)hash_remove(ihash, &k), k);
	printihash(ihash);

	k = 100;
	iv = (int *) hash_remove (ihash, &k);
	printf ("removed %d from hash using key %d, hash is now: ", (iv == NULL) ? 0 : *iv,  k);
	printihash(ihash);

	hash_destroy(ihash);
	return 0;
}

char * mallocString (char * a)
{
	int l = strlen (a);
	char * str = malloc (sizeof (char) * (l + 1));
	strncpy (str, a, l);

	return str;
}
	
void printshash (hash * h)
{
	assert (h != NULL);

	if (h->key == NULL)
		printf ("hash is empty\n");
	else
	{
		printf ("[");
		while (h != NULL)
		{
			printf ("('%s', '%s'), ", (char *)h->key, (char *)h->value);

			h= h->link;
		}
		printf ("]\n");

	}
}

void printihash (hash * h)
{
	assert (h != NULL);

	if (h->key == NULL)
		printf ("hash is empty\n");
	else
	{
		printf ("[");
		while (h != NULL)
		{
			printf ("(%d, %d), ", *(int *)h->key, *(int *)h->value);
			h = h->link;
		}
		printf ("]\n");
	}
}

int * mallocInt (int x)
{
	int * a = malloc (sizeof (int));
	*a = x;

	return a;
}
