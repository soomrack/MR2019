#include "sort_algorithms.h"
#include <cmath>

void bubble_sort(int* array, const int size)
{
	for (int  sizeOfSortedArray= 0; sizeOfSortedArray < size; sizeOfSortedArray++)
	{
		for (int unsortedElement = 0; unsortedElement < size - sizeOfSortedArray - 1; unsortedElement++)
		{
			if (array[unsortedElement] > array[unsortedElement + 1])
			{
				swap(array[unsortedElement], array[unsortedElement + 1]);
			}
		}
	}
}

void insertion_sort(int* array, const int size)
{
	for (int borderOfSortedArray = 1; borderOfSortedArray < size; borderOfSortedArray++)
	{
		int posSortedElem = borderOfSortedArray - 1;
		int unsortedElem = array[borderOfSortedArray];
		while (posSortedElem >= 0 && unsortedElem < array[posSortedElem])
		{
			array[posSortedElem + 1] = array[posSortedElem];
			posSortedElem--;
		}
		array[posSortedElem + 1] = unsortedElem;
	}
}

void heap_sort(int* array, const int size)
{
	for (int sizeUnsortedArray = size; sizeUnsortedArray > 1; sizeUnsortedArray--)
	{
		heapify(array, sizeUnsortedArray, 0);
		swap(array[0], array[sizeUnsortedArray - 1]);
	}
}

void merge_sort(int* array, const int size)
{
	if (size < 2)
	{
		return;
	}
	int left_size = size / 2;
	int right_size = size - left_size;
	merge_sort(&array[0], left_size);
	merge_sort(&array[left_size], right_size);
	int left_index = 0;
	int right_index = left_size;
	int index = 0;
	int* tmp_array = new int[size];
	while (left_index < left_size || right_index < size)
	{
		if (array[left_index] < array[right_index])
		{
			tmp_array[index] = array[left_index];
			index++;
			left_index++;
		}
		else
		{
			tmp_array[index] = array[right_index];
			index++;
			right_index++;
		}
		if (left_index == left_size)
		{
			for (index; index < size; index++, right_index++)
			{
				tmp_array[index] = array[right_index];
			}
			break;
		}
		if (right_index == size)
		{
			for (index; index < size; index++, left_index++)
			{
				tmp_array[index] = array[left_index];
			}
			break;
		}
	}
	for (index = 0; index < size; index++)
	{
		array[index] = tmp_array[index];
	}
	delete[] tmp_array;
}

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void heapify(int* array, const int size, int root)
{
	if (root >= size)
		return;
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (array[largest] < array[left] && left < size)
	{
		largest = left;
	}
	if (array[largest] < array[right] && right < size)
	{
		largest = right;
	}
	if (root != largest)
	{
		swap(array[root], array[largest]);
	}
	sift_up(array, root);
	heapify(array, size, left);
	heapify(array, size, right);
}

void sift_up(int* array, int index)
{
	while (array[index] > array[(index - 1) / 2])
	{
		swap(array[index], array[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
