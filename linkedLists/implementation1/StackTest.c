
#include "Stack.h"
#include <stdio.h>


int main (void)
{
	Stack * s = createStack();

	int x;
	for (x = 0; x < 5; x++)
		push(s, x);

	printf ("Stack contents: '");
	printStack (s);
	printf ("'\n");

	for (x = 0; x < 2; x++)
	{
		printf ("popped: %d  stack is now: '", pop(s));
		printStack (s);
		printf ("'\n");
	}

	destroyStack (s);
	printf ("Stack contents: '");
	printStack (s);
	printf ("'\n");

	return 0;
}
