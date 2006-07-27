int foo (void);

/* C requires global variables to be only assigned with CONSTANT values.
As a result you cannot initialize a global variable with the return value
of a function, so the line below is invalid, even though foo always returns
20
*/

int x = foo();

int main (void)
{
	return 0;
}

int foo (void)
{
	return 20;
}

