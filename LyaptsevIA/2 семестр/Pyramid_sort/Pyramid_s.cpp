#include <iostream>
#include <algorithm>
using namespace std;

void heap(int* const array, const int numberOfElements, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < numberOfElements && array[left] > array[largest])
		largest = left;

	if (right < numberOfElements && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(array[largest], array[i]);
		heap(array, numberOfElements, largest);
	}
}

void sort(int* arr, const int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heap(arr, size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[i], arr[0]);
		heap(arr, i, 0);
	}
}

int main()
{
	int array[15] = { 7,3,2,9,23,5,1,6,72,4,34,-66,-757,21,44 };
	int n = sizeof(array) / sizeof(array[0]);
	sort(array, 15);
	for (int counter = 0; counter < 15; counter++)
	{
		cout << array[counter] << endl;
	}
}




