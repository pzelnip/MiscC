#include <stdio.h>

typedef int (*FPTR) (char *, char *);

struct intCmd {
	char * cmdName;
	FPTR function;
};

typedef struct intCmd intCmd;

int func1 (char *, char *);
int func2 (char *, char *);

int main (void)
{
	int y = 0;
	const intCmd cmdArr[] = {
		{"cmd0", func1}, 
		{"cmd1", func2},
		{NULL}
	};

	while (cmdArr[y].cmdName != NULL)
	{
		printf ("cmdname: %s\n", 
			cmdArr[y].cmdName);
		cmdArr[y].function("string1", "string2");

		y++;
	}

	return 0;
}



int func1 (char * first, char * second)
{
	printf ("Func1: '%s' - '%s'\n", first, second);
	return 0;
}

int func2 (char * first, char * second)
{

	printf ("Func2: '%s' - '%s'\n", first, second);
	return 0;
}
