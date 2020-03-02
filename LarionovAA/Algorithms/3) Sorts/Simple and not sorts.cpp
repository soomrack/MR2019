
#include <iostream>

void print_array(int* array, const int size)
{
	std::cout << std::endl;
	for (int i = 0; i <= (size - 1); i++)
	{
		std::cout << array[i] << " ";
	}

	return;
}

void swap(int* array, const int firstIndex, const int secondIndex)
{
	int tmp = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = tmp;
}


void bubble_sort(int* array, const int size) // advanced: add flag
{
	for (int i = 0; i < (size - 1); i++)
	{
		int flag = 0;
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, (j + 1));
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}

	return;
}

void insertion_sort(int* array, const int size)
{
	for (int i = 1; i <= (size - 1); i++)
	{
		int key = array[i]; // buffer
		int k = i - 1;
		while ( (k >= 0) && (array[k] > key) )
		{
			array[k + 1] = array[k];
			k--;
		}
		array[k + 1] = key;
	}

	return;
}

void heapify(int* array, int index, const int size)
{
	int left = 2 * (index + 1) - 1;
	int right = 2 * (index + 1);
	int largest = index;

	if ((left < size) && (array[left] > array[largest]))
	{
		largest = left;
	}

	if ((right < size) && (array[right] > array[largest]))
	{
		largest = right;
	}

	if (largest != index)
	{
		swap(array, index, largest);
		heapify(array, largest, size);
	}

	return;
}

void make_heap(int* array, const int size)
{
	for (int i = ((size / 2) - 1); i >= 0; i--)
	{
		heapify(array, i, size);
	}

	return;
}

void heap_sort(int* array, const int size)
{
	make_heap(array, size);
	int decreasedSize = size;
	while (decreasedSize > 1)
	{
		swap(array, 0, decreasedSize - 1);
		decreasedSize--;
		heapify(array, 0, decreasedSize);
	}

	return;
}

void merge(int* array, int* buffer, int left, int middle, int right)
{
	int leftPtr = left;
	int rightPtr = middle;
	int index = 0;

	while (leftPtr < middle && rightPtr <= right)
	{
		if (array[leftPtr] < array[rightPtr])
		{
			buffer[index] = array[leftPtr];
			leftPtr++;
			index++;
		}
		else
		{
			buffer[index] = array[rightPtr];
			rightPtr++;
			index++;
		}	
	}

	while (leftPtr < middle)
	{
		buffer[index] = array[leftPtr];
		leftPtr++;
		index++;
	}

	while (rightPtr <= right)
	{
		buffer[index] = array[rightPtr];
		rightPtr++;
		index++;
	}

	for (int i = 0; i < index; i++)
	{
		array[left + i] = buffer[i];
	}

	return;
}

void merge_sort(int* array, int* buffer, int left, int right)
{
	if (left == right)
	{
		return;
	}
	int middle = (left + right) / 2;
	merge_sort(array, buffer, left, middle);
	merge_sort(array, buffer, middle + 1, right);
	merge(array, buffer, left, middle + 1, right);

	return;
}


int main()
{
	int arrayOne[6] = { 4, 3, 6, 1, 2, 5 };
	int sizeOne = 6;

	bubble_sort(arrayOne, sizeOne);
	print_array(arrayOne, sizeOne);

	int arrayTwo[10] = { -1, 4, 3, -7, 6, 11, 13, -75, 100, 66 };
	int sizeTwo = 10;

	insertion_sort(arrayTwo, sizeTwo);
	print_array(arrayTwo, sizeTwo);

	int arrayThree[11] = { 5, 33, 7, 11, 66, -87, 0, -3, 32, 10, 99 };
	int sizeThree = 11;

	heap_sort(arrayThree, sizeThree);
	print_array(arrayThree, sizeThree);

	int arrayFour[8] = { -1, 3, 2, -11, 4, -5, 0, -3 };
	int buffer[8] = { 0 };
	int sizeFour = 8;

	merge_sort(arrayFour, buffer, 0, (sizeFour - 1));
	print_array(arrayFour, sizeFour);

	return 0;
}