
#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

/* Create a new, empty stack "object" */
Stack * createStack (void)
{
	Stack * s = malloc (sizeof (*s));
	assert (s != NULL);

	s->list = createList();
	
	return s;
}

/* Push an item onto the top of this stack */
void push (Stack * stack, NodeData data)
{
	assert (stack != NULL);
	addDataAtStart(stack->list, data);
}

/* removes and returns the top item from the stack */
NodeData pop (Stack * stack)
{
	assert (stack != NULL);
	return removeFirst(stack->list);
}

/* destroys a stack created via a call to createStack */
void destroyStack (Stack * stack)
{
	assert (stack != NULL);
	destroyList(stack->list);
	free (stack);
}

/* prints a stack */
void printStack (Stack * s)
{
	assert (s != NULL);
	printList (s->list);
}
