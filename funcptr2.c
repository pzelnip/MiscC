#include <stdio.h>

#define FUNCCAST (int (*) (char *, ...))

struct s {
	char * str;
	int (* func) (char *, ...);
};

typedef struct s s;

int oneParam(char * s);
int twoParam (char * s1, char * s2);

int main (void)
{
	s y = {"afd", FUNCCAST oneParam};
	s x = {"dfafsad", FUNCCAST twoParam}; 
	y.func ("hello", "dfsaf");
	x.func ("hello", "world");
	return 0;

}

int oneParam (char * s)
{
	printf ("one param %s\n", s);
	return 0;
}

int twoParam (char * s1, char * s2)
{

	printf ("two param '%s' - '%s'\n", s1, s2);
	return 0;
}
