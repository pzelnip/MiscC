#include <stdio.h>

int main (void)
{
	char x[] = "adam is cool";
	char * y = "adam is cool";

	printf ("Size of char array: %d,  Size of pointer array: %d\n", 
		sizeof x / sizeof (char),
		sizeof y / sizeof (char));

	/* modify element of array - legal */
	x[0] = 'A';

	/* modify element of string constant -- UNDEFINED! */
	y[0] = 'A';

	/* make char pointer point to a different string - legal */
	y = "hello";

	/* assign value to array name -- ILLEGAL! */
	x = "hello";

	return 0;
}

