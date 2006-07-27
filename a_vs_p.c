#include <stdio.h>

int main (void)
{
	char x[] = "adam is cool";
	char * y = "adam is cool";

	/* note that the size of a char array is the length of the string
	contained in the array, but the size of a char * is just the size
	of a pointer (typically 4 bytes) */
	printf ("Size of char array: %d,  Size of pointer: %d\n", 
		sizeof x / sizeof (char),
		sizeof y / sizeof (char));

	/* modify element of array - legal */
	x[0] = 'A';

	/* modify element of string literal -- UNDEFINED and will likely seg fault! */
	y[0] = 'A';

	/* the reason the above is a problem is because y contains the value which is the
	address of the first character of the string literal "adam is cool".  So y[0] is
	the same as dereferencing that address and trying to store something there, which
	in this case is undefined.  The ANSI C standard allows C compilers to place string
	literals in regions of memory that are protected from modification, which is why
	the above might be a problem.  OTOH if you have a char[] initialized with a string
	literal, what that does is it *guarantees* that the memory that the char[] is 
	pointing to is writable.

	What's better, there's nothing in the C standard that states that if you had code 
	like:

	char * a = "adam is cool";
	char * b = "adam is cool";

	that the two strings "adam is cool" and "adam is cool" have to be in different locations
	in memory.  That is a and b could both be pointing to the same string.  If you don't
	believe me, try the following 3 lines of code:

 	char * a = "adam is cool";
	char * b = "adam is cool";
	printf ("%d   %d\n", a,b);

	when I ran this at home using GCC the printf line above printed the same number twice,
	which is the address of the first character of the string literal "adam is cool".

	Furthermore, what's really wild is if you had code like:

	char * a = "adam is cool";
	char * b = "is cool";

	there's nothing to say that "adam is cool" and "is cool" have to be completely separate
	strings in memory.  IOW, if a contained the address 0x20 then b *could* contain the address 
	0x25 or IOW could be pointing to the middle of the string pointed to by a.  However, it would
	seem that at least GCC doesn't do this (or at least not without any optimization flags 
	set).  

	See "C - A Reference Manual" 3rd Ed by Samuel P. Harbison and Guy L. Steele Jr., page 24-25
	for more info.  Crazy stuff.

	*/

	/* make char pointer point to a different string - legal. */
 	y = "hello";

	/* The above line is essentially like

	int * a = 10;
	a = 20;

	That is, all you're doing is saying a pointer should point to a different location in 
	memory, which is perfectly valid (although in the integer case it will likely cause a
	seg fault, whereas the string case would be perfectly fine subject to the rules above
	about the memory possibly being non-writable).
	*/ 

	/* assign value to array name -- ILLEGAL! (ie - compile time error) */
	//x = "hello";

	/* nor can you assign an array to a pointer: */
	//char * foo = x;


	/* an array name is essentially a "constant pointer", or a pointer which can only
	point to one location in memory and that can never point to a different location in 
	memory.  The above line essentially tries to make that "constant pointer" point to
	a different location in memory.

	Essentially: 

	char [] id;

	is very much like 

	char const * id;

	Or a constant pointer to a character (the above line is C++ syntax, I'm not sure about the
	const keyword in C, as it wasn't originally part of the C language) 

	*/ 

	/* Kinda makes you appreciate Java after all doesn't it? =;-> */
	return 0;
}
