#include <stdio.h>
#define LEN 10

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void ridding(int* arr, int parent, int child)
{
	while ((arr[parent] < arr[child]) && (child != 0))
	{
		swap(&arr[parent], &arr[child]);
		child = parent;
		parent = (parent - 1) / 2;
	}
}

void heap(int* arr, int parent, int length)
{
	if ((parent * 2 + 2) <= (length))
	{
		int leftchild = parent * 2 + 1;
		int rightchild = parent * 2 + 2;
		ridding(arr, parent, leftchild);
		ridding(arr, parent, rightchild);
		heap(arr, leftchild, length);
		heap(arr, rightchild, length);
	}
	else
	{
		if ((parent * 2 + 1) <= (length))
		{
			int leftchild = parent * 2 + 1;
			heap(arr, leftchild, length);
			ridding(arr, parent, leftchild);
		}
	}
}

void printarr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d  ", arr[i]);
	}
	printf("\n");
}

void printheap(int* arr, int length)
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
				printf("%3d ", arr[i]);
			}
			printf("\n");
			amount += quantity;
			level++;
		}
		else
		{
			for (int i = amount; i < length; i++)
			{
				printf("%3d ", arr[i]);
			}
			flag = 0;
		}
	}
	printf("\n");
}

int main()
{
	int arr[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printarr(arr, LEN);
	heap(arr, 0, LEN - 1);
	printarr(arr, LEN);
	printheap(arr, LEN);
	return 0;
}
