#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;



void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		heapify(arr, n, largest);
	}
}


void heap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);


}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout<< arr[i] << " ";
	cout<< "\n";
}

void printArray2(int arr[], int n)
{
	int g = 0;
	int k = 1;

	while (g < n)
	{
		while ((g < k) && (g < n))
		{
			cout << arr[g] << " ";
			g++;
		}

		cout << endl;
		k = k * 2 + 1;
	}

}

int main()
{
	int M[10] = { 7,3,2,9,23,5,1,6,72,4 };

	int n = sizeof(M) / sizeof(M[0]);
	for (int i = 0; i < n; i++)
	{
		cout << M[i]<<" ";
	}
	cout << "\n";

	heap(M, n);

	cout << "Sorted array is \n";
	printArray(M, n);
	printArray2(M, n);
}

