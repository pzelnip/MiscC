#include <iostream>
using std::cout;
using std::endl;

int a;
int b;

void foo (int & x, int & y)
{
	y = b + x;
	cout << "Foo says a = " << a << " and b = " << b << endl;
}

void bar (int & u)
{
	a = u * b;
	foo (a, u);
	b = b - a;
}

int main (void)
{
	a = 10;
	b = 20;
	bar (a);
	cout << "At end a = " << a << " and b = " << b << endl;
	
	return 0;
}
