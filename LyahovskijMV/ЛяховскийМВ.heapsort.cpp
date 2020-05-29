#include <iostream>

using namespace std;

void Sort(int* arr, const int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		HeapSort(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[i], arr[0]);
		HeapSort(arr, i, 0);
	}
}

void HeapSort(int* array, int numberOfElements, int i)
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
		HeapSort(array, numberOfElements, largest);
	}
}

void Swap(int& a, int& b)
{
	int c = b;

	b = a;

	a = c;
}

void PrintArray(int *array, int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << array[i] << " ";
   }

   cout << endl;
}

int main()
{
   int array1[10] = { 5, 46, 66, 2, 12, 0, 78, 9, 90, 10 };
   int size = 10;

   PrintArray(array1, size);

   Sort(array1, size);

   PrintArray(array1, size);

   return 0;
}