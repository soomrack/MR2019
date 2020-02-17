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

void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void BubbleSort(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				swap(arr, j - 1, j);
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
