/*

Call by value result (CBVR) isn't natively supported by C++, but we can fake it by
adding extra code.

CBVR makes a copy of an actual parameter, as in the case of call by value, but 
"writes back" the result upon exiting the function and thus you see changes made 
to formal parameters outside of the function as is the case in call by reference.
The difference is that you won't see changes to the referenced variables until
you exit the function.  For example:

int a = 3;

void bar (int x)
{
   x = 10;
   cout << a << endl;
} 

void foo ()
{
   bar (a);
   cout << a << endl;
}

Would print out 33 if using call by value, 1010 if using call by reference, and
310 if using call by value result.

Thus to simulate CBVR we just need to make local copies of actual parameters upon 
entry to a function inside the caller, make the formal parameters be references 
in the callee, and then upon returning to the caller assign the reference copies
to the actual paramters. 

An alternative approach would be to inside the callee copy the formal
parameter to a copy, do work to the copy, and then at exit assign the
copy to the formal (which must be a reference).
*/

#include <iostream>
using std::cout;
using std::endl;

int a;
int b;

void foo (int & xFormal, int & yFormal)
{
	// make copy of formal param -- CBVR semantics
	int x = xFormal;
	int y = yFormal;

	y = b + x;
	cout << "Foo says a = " << a << " and b = " << b << endl;

	// copy local copy to formal param -- CBVR semantics
	xFormal = x;
	yFormal = y;
}

void bar (int & uFormal)
{
	// make copy of formal param -- CBVR semantics
	int u = uFormal;
 
	a = u * b;
	foo (a, u);
	b = b - a;

	// copy local copy to formal param -- CBVR semantics
	uFormal = u;
}

int main (void)
{
	a = 10;
	b = 20;

	bar (a);

	cout << "At end a = " << a << " and b = " << b << endl;
	
	return 0;
}
