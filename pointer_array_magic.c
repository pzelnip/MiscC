#include <stdio.h>

int main (void)
{

	char c = "abcde"[3];	/* assigns 'd' to the char variable c */
	char d = 3["abcde"];	/* does the same thing, the reason is that
				   a[b] is treated by the C compiler as the 
				   expression *(a+b), and since addition is
				   commutative, this is the same as *(b+a) */

	printf ("%c   %c\n", c,d);

	return 0;
}
