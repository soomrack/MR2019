#include <stdio.h>
#define LEN 10

void printarr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d  ", arr[i]);
	}
	printf("\n");
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void BubbleSort(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				swap(&arr[j - 1], &arr[j]);
			}
		}
	}
	return;
}

void CyclicShiftRight(int* arr, int leftboard, int rightboard)
{
	int temp = arr[rightboard];
	for (int i = rightboard; i > leftboard; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[leftboard] = temp;
	return;
}

void InsertsSort(int* arr, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (arr[0] > arr[i])
		{
			int j = i;
			int flag = 1;
			while ((j >= 0) && (flag))
			{
				if (arr[j] > arr[i])
				{
					CyclicShiftRight(arr, j + 1, i);
					flag = 0;
				}
				j--;
			}
		}
		else
		{
			CyclicShiftRight(arr, 0, i);
		}
	}
	return;
}

int main()
{
	int arr1[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printarr(arr1, LEN);
	BubbleSort(arr1, LEN);
	printarr(arr1, LEN);
	int arr2[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printarr(arr2, LEN);
	InsertsSort(arr2, LEN);
	printarr(arr2, LEN);
	return 0;
}
