#include <stdio.h>
#define LEN 10

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void riddling(int* arr, int parent, int length)
{
	printf("Start riddling with parent %d.\n", parent);
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
		printf("Change parent: %d\n", parent);
	}
	if ((arr[parent] < arr[leftchild]) && (leftchild < length))
	{
		swap(&arr[parent], &arr[leftchild]);
	}
	printf("End riddling\n\n");
	return;
}

void heap(int* arr, int rightchild, int length)
{
	printf("Start Heap with rightchild %d\n\n", rightchild);
	if (rightchild != 0)
	{
		int parent = (rightchild - 1) / 2;
		riddling(arr, parent, length);
		printf("End Heap with rightchild %d\n\n", rightchild);
		heap(arr, rightchild - 2, length);
	}
	printf("End of heap construction.\n\n");
	return;
}

void startheap(int* arr, int length)
{
	int parent = (length - 2) / 2;
	if (((length) % 2) == 0)
	{
		printf("StartHeap Yes\n\n");
		int leftchild = length - 1;
		if (arr[parent] < arr[leftchild])
		{
			swap(&arr[parent], &arr[leftchild]);
		}
		heap(arr, leftchild - 1, length);
	}
	else
	{
		printf("StartHeap No\n\n");
		heap(arr, length - 1, length);
	}
	return;
}

void printmass(int* mass, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d  ", mass[i]);
	}
	printf("\n");
	return;
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
	return;
}

int main()
{
	int arr[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printmass(arr, LEN);
	startheap(arr, LEN);
	printmass(arr, LEN);
	printheap(arr, LEN);
	return 0;
}
