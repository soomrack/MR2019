#include <stdio.h>
#define LEN 10

void ridding(int* mass, int parent, int child)
{
	while ((mass[parent] < mass[child]) && (child != 0))
	{
		int temp = mass[parent];
		mass[parent] = mass[child];
		mass[child] = temp;
		child = parent;
		parent = (parent - 1) / 2;
	}
}

void heap(int* mass, int parent, int length)
{
	if ((parent * 2 + 2) <= (length))
	{
		int leftchild = parent * 2 + 1;
		int rightchild = parent * 2 + 2;
		ridding(mass, parent, leftchild);
		ridding(mass, parent, rightchild);
		heap(mass, leftchild, length);
		heap(mass, rightchild, length);
	}
	else
	{
		if ((parent * 2 + 1) <= (length))
		{
			int leftchild = parent * 2 + 1;
			heap(mass, leftchild, length);
			ridding(mass, parent, leftchild);
		}
	}
}

void printmass(int* mass, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d  ", mass[i]);
	}
	printf("\n");
}

void printheap(int* mass, int length)
{
	int level = 0;
	int flag = 1;
	int amount = 0;
	while (flag)
	{
		printf("%2d: ", level);
		int quantity = 1;
		for (int i = 0; i < level; i++)
		{
			quantity *= 2;
		}
		if ((amount + quantity) < length)
		{
			for (int i = amount; i < (amount + quantity); i++)
			{
				printf("%3d ", mass[i]);
			}
			printf("\n");
			amount += quantity;
			level++;
		}
		else
		{
			for (int i = amount; i < length; i++)
			{
				printf("%3d ", mass[i]);
			}
			flag = 0;
		}
	}
	printf("\n");
}

int main()
{
	int mass[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printmass(mass, LEN);
	heap(&mass[0], 0, LEN - 1);
	printmass(mass, LEN);
	printheap(mass, LEN);
	return 0;
}
