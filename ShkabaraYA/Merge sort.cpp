#include <iostream>

void Merge(int arr[], int l, int m, int r) {
	int num1arr, num2arr;
	num1arr = m - l + 1;
	num2arr = r - m;

	int* SubArr1 = new int[num1arr];
	int* SubArr2 = new int[num2arr];

	int i, j;
	for (i = 0; i < num1arr; i++) 
		SubArr1[i] = arr[l + i];
	for (j = 0; j < num2arr; j++) 
		SubArr2[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	int CurIndMerged = l;

	while (i < num1arr && j < num2arr) {
		if (SubArr1[i] <= SubArr2[j]) {
			arr[CurIndMerged] = SubArr1[i];
			i++;
		} 
		else {
			arr[CurIndMerged] = SubArr2[j];
			j++;
		}
		CurIndMerged++;
	}
	
	while (i < num1arr) {
		arr[CurIndMerged] = SubArr1[i];
		CurIndMerged++;
		i++;
	}

	while (j<num2arr) {
		arr[CurIndMerged] = SubArr2[j];
		CurIndMerged++;
		j++;
	}	
}

void MergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = (r + l) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 3, 11, 8, 0, 10, 1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	MergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
