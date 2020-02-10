#include <iostream>
using namespace std;

int a[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 110, 111 };
int x = 14;
int numerus;

int search(int* a, int first, int last, const int x)
{
	if (first == last)
		if (a[first] == x) 
		{ 
			return(first);
		}
		else 
		{
			return(-1);
		}
	int middle = (last - first) / 2 + first;

	if (a[middle] < x) 
		return (search(a, middle + 1, last, x));
	if (a[middle] > x) 
		return (search(a, first, middle, x));
}

int main()
{
	numerus = search(a, 0, 10, x);
	cout << numerus << endl;
}




