#include <iostream>
#define LEN 10

void Combine(int* arr, int size1, int size2)
{
	int* mass1 = (int *)malloc(sizeof(size1) * size1);
	int* mass2 = (int *)malloc(sizeof(size2) * size2);
	for (int i = 0; i < size1; i++)
	{
		mass1[i] = arr[i];
	}
	for (int i = 0; i < size2; i++)
	{
		mass2[i] = arr[size1 + i];
	}
	int count1 = 0;
	int count2 = 0;
	for (int count = 0; count < size1 + size2; count++)
	{
		if ((count1 < size1) && (count2 < size2))
		{
			if ((mass1[count1] > mass2[count2]))
			{
				arr[count] = mass1[count1];
				count1++;
			}
			else
			{
				arr[count] = mass2[count2];
				count2++;
			}
		}
		else
		{
			while (count1 < size1)
			{
				arr[count] = mass1[count1];
				count++;
				count1++;
			}
			while (count2 < size2)
			{
				arr[count] = mass2[count2];
				count++;
				count2++;
			}
		}
	}
	return;
}

void MergeSort(int* arr, int size)
{
	int size1 = size / 2;
	int size2 = size - size1;
	if (size1 > 1)
		MergeSort(arr, size1);
	if (size2 > 1)
		MergeSort(arr + size1, size2);
	Combine(arr, size1, size2);
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

int main()
{
	int arr[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printarr(arr, LEN);
	MergeSort(arr, LEN);
	printarr(arr, LEN);
	return 0;
}
