#include <iostream>

int search(int* a, const int first, const int last, const int x) {
	if (first>=last)
		if (a[first] == x) {
			return (first);
		}
		else
		{
			return(-1);
		}
	int middle = (last - first) / 2 + first;

	if (a[middle] < x) return (search(a, middle + 1, last, x));
	return (search(a, first, middle, x));
}

int main()
{
	int b[10] = { 0, 2, 3, 5, 6, 8, 11, 13, 16, 20 };
 	int z;
	z = search(b, 0, 9, 5);
	std::cout << z;
}


