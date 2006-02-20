#include <iostream>
using namespace std;

// FooFunc is a pointer to a function in class foo that
// takes 2 ints & returns a bool

class foo
{
	typedef bool (*FooFunc)(int x, int y); 
public:

	FooFunc getFunc ();
	
	static bool bar(int x, int y);

private:
	
};

foo::FooFunc foo::getFunc ()
{
	return &(bar);
}

bool foo::bar(int x, int y)
{
	cout << "bar! " << x << " " << y << endl;
	return true;
}

	typedef bool (*FooFunc)(int x, int y); 

int main (void)
{
/*
	foo adam;

	FooFunc blah = adam.getFunc();

	(adam.*blah)(3,4);
*/

	/* works
	FooFunc blah = &(foo::bar);
	blah (3,4);
*/
	foo * adam = new foo;
	FooFunc blah = adam->getFunc();
	blah (3,4);
	return 0;
}
