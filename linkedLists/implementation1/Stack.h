


#ifndef STACK_H
#define STACK_H

#include "NodeData.h"
#include "LinkedList.h"

typedef struct stack_struct {
	LinkedList * list;
} Stack;


/* Create a new, empty stack "object" */
Stack * createStack (void);

/* Push an item onto the top of this stack */
void push (Stack * stack, NodeData data);

/* removes and returns the top item from the stack */
NodeData pop (Stack * stack);

/* destroys a stack created via a call to createStack */
void destroyStack (Stack * stack);

/* prints a stack */
void printStack (Stack * s);

#endif
