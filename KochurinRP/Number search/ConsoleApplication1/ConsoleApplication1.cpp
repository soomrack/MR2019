#include "pch.h"
#include <stdio.h>

int Search(int X, int* mass, int first, int last)
{
	if (first >= last-1)
	{
		if (X = mass[first])
		{
			return first;
		}
		else
		{
			if (X = mass[last])
			{
				return last;
			}
			else
			{
				return (-1);
			}
		}
	}
	int middle = (first + last) / 2;
	if (mass[middle] <= X)
	{
		return(Search(X, mass, middle, last));
	}
	else
	{
		return(Search(X, mass, first, middle - 1));
	}
}

int main()
{
	int mass[10] = {-13, 1, 7, 13, 44, 85, 102, 102, 143, 544};
	
	int X = 13;
	int nomber = Search(X, mass, 0, 100);
	if (nomber != -1)
	{
		printf("%d, %d, %d\n\n", nomber, X, mass[nomber]);
	}
	else
	{
		printf("no found %d\n\n", X);
	}
	return 0;
}
