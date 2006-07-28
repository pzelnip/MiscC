#ifndef HASH_H
#define HASH_H

typedef struct hash_struct {
	void *key;
	void *value;
	int (*cmpFunc) (void *, void *);
	struct hash_struct * link;
} hash;

/* create an empty list. Use the key_eq_fn to compare
whether two keys are equal or not
*/
hash *
create_hash(int (*key_eq_fn) (void*,void*));

/* returns true (non-zero) if insertion was succesful.
insert key k and value v into hashtable h.
*/
int
hash_insert(hash *h, void *k, void *v);

/* returns the value associated with key
if they key is in the hash or NULL if
not found
*/
void *
hash_search(hash *h, void *k);

/* remove key and associated value from hash.
returns the value */
void *
hash_remove(hash *h, void *k);

/* free all memory used by the hash */
void
hash_destroy(hash *h);


#endif
