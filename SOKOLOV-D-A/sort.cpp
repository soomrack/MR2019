#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>




void bubbleSort(int* array, const size_t size)
{
	for(size_t sorted_iteratror = 0; sorted_iteratror < size - 1; sorted_iteratror++)
	for (size_t actual = 0; actual < size - sorted_iteratror - 1 ; actual++)
	{
		if (array[actual] > array[actual + 1])
			std::swap(array[actual], array[actual + 1]);
	}

}

void insertsort(int* arr, const size_t  size)
{
	int key = 0;
	for (size_t sorted_iteratror = 1; sorted_iteratror < size; sorted_iteratror++)
	{
		key = arr[sorted_iteratror];
		int inside_iterator = sorted_iteratror - 1;
		while (inside_iterator >= 0 && key < arr[inside_iterator])
		{
			arr[inside_iterator + 1] = arr[inside_iterator];
			inside_iterator--;
		}
		arr[inside_iterator + 1] = key;
	}

}
int main()
{

	const int size = 11;
	int arr[size] = { 5, 4, 7, 9, 4, 3, 1, 9, 0, 3, 10 };

	bubbleSort(arr, size);
	//insertsort(arr, size);

	}
	return 0;


}
