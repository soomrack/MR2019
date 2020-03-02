#include <stdio.h>

void printmass(int* mass, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d  ", mass[i]);
	}
	printf("\n");
}

int Search(int X, int* mass, int first, int last)
{
	printf("%d, %d, %d\n", X, first, last);
	if (first >= last - 1)
	{
		if (mass[first] == X)
		{
			printf("mass: %d, %d, %d\n", X, first, mass[first]);
			return first;
		}
		else
		{
			if (mass[last] == X)
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
	int mass[10] = { -13, 1, 8, 13, 14, 85, 102, 102, 143, 544 };

	int X = 13;
	int nomber = Search(X, mass, 0, 9);
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