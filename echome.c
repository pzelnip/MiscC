#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getline (char * s, int lim);

int main (void)
{
        char blah[200];
        getline(blah, 200);
        printf ("I got: '%s'\n", blah);
        return 0;
}

int getline(char * s, int lim)
{
        if (fgets(s, lim, stdin) == NULL)
                return 0;
        else
        {
                int x = strlen (s) - 1;
                s[x] = (s[x] == '\n') ? '\0' : s[x];
                return x + 1;
	}
}
