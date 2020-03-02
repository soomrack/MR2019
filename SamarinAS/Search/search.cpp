

#include <iostream>
using namespace std;

int a[11] = { 5,6,7,8,9,10,11,12,13,14};
int x = 10;
int n;

int seach(int* a, int first, int last, const int x)
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
	
	if (a[middle] < x) return (seach(a, middle + 1, last, x));
	if (a[middle] >= x) return (seach(a, first, middle, x));
}


int main()
{
	n = seach(a,0,10,x);
	cout << n;
}

