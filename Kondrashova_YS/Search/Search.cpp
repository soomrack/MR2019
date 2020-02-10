#include <stdio.h>

int search(int* a, int first, int last, int x)
{
	if (first >= last)
	{
		if (a[first] == x) { return (first); }
		else { return(-1); }
	}

	int middle = (last - first) / 2 + first; 

	if (a[middle] < x) return search(a, middle + 1, last, x);

	return search(a, first, middle, x);
}

int main() 
{
	int x = 4444;
	const int size = 10;
	int a[size] = {1, 8, 44, 88, 478, 4444, 7899, 8000, 9898, 9999};

	printf("#%d element = %d ", search(a, 1, 10, x), x);

	return 0;
}