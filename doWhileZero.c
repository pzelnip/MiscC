
#include <stdio.h>

//
// The do { ... } while (0) loop is a trick in C to turn a group of statements 
// into a single statement.  It is most commonly used in macros like so:

#define SWAP(a, b) do {                 \
                        a ^= b;         \
                        b ^= a;         \
                        a ^= b;         \
                    } while(0) 

//
// You might think that just doing the following would be equivalent:
//
// #define SWAP(a, b) {                   \
//                        a ^= b;         \
//                        b ^= a;         \
//                        a ^= b;         \
//                    } 
//
// But in fact, in the case of an if/else it would not be due to the trailing semicolon
// after the call to the macro:
//
//  // does not compile
//  if (x > y)
//  	SWAP (x,y);
//  else
//      .... some other code
//

// source: http://www.christophermatthews.ca/?q=node/5 and http://c2.com/cgi/wiki?TrivialDoWhileLoop

int main (void)
{
	int x = 42;
	int y = 24;

	printf ("%d %d\n", x, y);

	if (x > y)
		SWAP(x,y);
	else
		SWAP(y,x);

	printf ("%d %d\n", x, y);

	return 0;
}
