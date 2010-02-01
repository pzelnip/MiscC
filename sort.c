#include <stdio.h>

void doSort (void (*sortfn)(int[], int));
void bubblesort (int ar[], int n);
void selectionsort (int ar[], int n);
void print (int ar[], int n);
void swap (int * a, int * b);

int main (void)
{
	doSort (&bubblesort);
	printf ("---------------------------\n");
	doSort (&selectionsort);

	return 0;
}

void doSort (void (*sortfn)(int[], int))
{
	int a[] = {5,1,3,155,2, 22, 7, 382908, 234};
	(*sortfn)(a, 9);
	print (a, 9);
}

void bubblesort (int ar[], int n)
{
	int x, y;

	for (x = 0; x < n - 1; x++)
		for (y = 0; y < n - 1; y++)
			if (ar[y] > ar[y+1])
				swap (&ar[y], &ar[y+1]);
}

void print (int ar[], int n)
{
	int x;

	for (x = 0; x < n; x++)
		printf ("a[%d] = %d\n", x, ar[x]);
}

void selectionsort (int ar[], int n)
{
	int x;

	for (x = 0; x < n - 1; x++)
	{
		int small = x, y;

		for (y = x + 1; y < n; y++)
			if (ar[y] < ar[small])
				small = y;

		swap (&ar[x], &ar[small]);
	}
}

void swap (int * a, int * b)
{
	if (a == b) return;

	*a ^= (*b = (*a ^= *b) ^ *b);
}
