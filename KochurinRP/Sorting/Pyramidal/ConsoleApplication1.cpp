#include <stdio.h>
#define LEN 10

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void ridding(int* arr, int parent, int length)
{
	int leftchild = parent * 2 + 1;
	int rightchild = leftchild + 1;
	while (((arr[parent] < arr[rightchild]) || (arr[parent] < arr[leftchild])) && (rightchild < length))
	{
		if ((arr[parent] < arr[leftchild]) && (arr[rightchild] < arr[leftchild]))
		{
			swap(&arr[parent], &arr[leftchild]);
			parent = leftchild;
		}
		else
		{
			if ((arr[parent] < arr[rightchild]) && (arr[leftchild] <= arr[rightchild]))
			{
				swap(&arr[parent], &arr[rightchild]);
				parent = rightchild;
			}
		}
		leftchild = parent * 2 + 1;
		rightchild = leftchild + 1;
	}
	if ((arr[parent] < arr[leftchild]) && (leftchild < length))
	{
		swap(&arr[parent], &arr[leftchild]);
	}
	return;
}

void heap(int* arr, int rightchild, int length)
{
	if (rightchild != 0)
	{
		int parent = (rightchild - 1) / 2;
		ridding(arr, parent, length);
		heap(arr, rightchild - 2, length);
	}
	return;
}

void startheap(int* arr, int length)
{
	int parent = (length - 2) / 2;
	if (((length) % 2) == 0)
	{
		int leftchild = length - 1;
		if (arr[parent] < arr[leftchild])
		{
			swap(&arr[parent], &arr[leftchild]);
		}
		heap(arr, leftchild - 1, length);
	}
	else
	{
		heap(arr, length - 1, length);
	}
	return;
}

void printarr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d  ", arr[i]);
	}
	printf("\n");
	return;
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
	return;
}

void heapsort(int* arr, int length)
{
	for (int i = length - 1; i > 0; i--)
	{
		startheap(arr, i);
		swap(&arr[0], &arr[i]);
	}
	swap(&arr[0], &arr[1]);
	return;
}

int main()
{
	int arr[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printarr(arr, LEN);
	heapsort(arr, LEN);
	printarr(arr, LEN);
	return 0;
}
