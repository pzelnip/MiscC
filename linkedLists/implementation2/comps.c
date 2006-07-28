
#include "comps.h"

#include <string.h>
#include <stdio.h>

int intComp (void * a, void * b)
{
	return (*(int *)a == *(int *)b);
}
	
int strComp (void * a, void * b)
{
	return !strcmp ((char *) a, (char *) b);
}


