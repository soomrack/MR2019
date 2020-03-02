#include <iostream>
#include <cmath>

void print_binary_heap(const int* array, const int size)
{
	for (int i = 0; ; i++)
	{
		std::cout << std::endl;
		int levelIndex = (int)pow(2, i) - 1; // First level element 
		int k = 0;
		do
		{
			if (levelIndex >= size)
			{
				std::cout << std::endl;
				return;
			}
			std::cout << array[levelIndex] << " ";
			levelIndex++;
			k++;
		} while (k < (int)pow(2, i));
	}
}


void organize_heap_tree_unusual(int* array, int index)
{
	if ( ((index % 2) != 0) && (((index + 1) / 2 - 1) >= 0) )
	{
		if (array[index] > array[(index + 1) / 2 - 1])
		{
			int tmp = array[(index + 1) / 2 - 1];
			array[(index + 1) / 2 - 1] = array[index];
			array[index] = tmp;
		}
		organize_heap_tree_unusual(array, (index + 1) / 2 - 1);
	}

	if ( ((index % 2) == 0) && ((index / 2 - 1) >= 0) )
	{
		if (array[index] > array[index / 2 - 1])
		{
			int tmp = array[(index / 2) - 1];
			array[(index / 2) - 1] = array[index];
			array[index] = tmp;
		}
		organize_heap_tree_unusual(array, index / 2 - 1);
	}

	return;
}

void up_down_binary_heap(int* array, const int size)
{
	for (int i = 0; i < size ; i++)
	{
		organize_heap_tree_unusual(array, i);
	}

	return;
}

void organize_heap_tree_original(int* array, int index, const int size) // another name - Heapify
{
	int left = 2 * (index + 1) - 1;
	int right = 2 * (index + 1);
	int largest = index;

	if ( (left < size) && (array[left] > array[largest]) )
	{
		largest = left;
	}

	if ( (right < size) && (array[right] > array[largest]) )
	{
		largest = right;
	}

	if (largest != index)
	{
		int tmp = array[index];
		array[index] = array[largest];
		array[largest] = tmp;
		organize_heap_tree_original(array, largest, size);
	}

	return;
}

void down_up_binary_heap(int* array, const int size)
{
	for (int i = ((size / 2) - 1); i >= 0; i--)
	{
		organize_heap_tree_original(array, i, size);
	}

	return;
}

int main() 
{
	std::cout << std::endl << std::endl << "Up-Down Binary Heap" << std::endl;

	int arrayOne[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	const int sizeOne = 15;
	int arrayTwo[10] = { 11, 23, 33, 12, 55, 113, 77, 7, 122, 200 };
	const int sizeTwo = 10;

	std::cout << std::endl << "First array before and after" << std::endl << "_________________" << std::endl;

	print_binary_heap(arrayOne, sizeOne);
	up_down_binary_heap(arrayOne, sizeOne);
	print_binary_heap(arrayOne, sizeOne);

	std::cout << std::endl << "Second array before and after" << std::endl << "_________________" << std::endl;

	print_binary_heap(arrayTwo, sizeTwo);
	up_down_binary_heap(arrayTwo, sizeTwo);
	print_binary_heap(arrayTwo, sizeTwo);
	

	std::cout << std::endl << std::endl << "Down-Up Binary Heap" << std::endl;

	int arrayThree[7] = { 3, 6, 9, 12, 15, 18, 21 };
	const int sizeThree = 7;
	int arrayFour[9] = { 1, 43, 5, 11, 13, 88, 921, 74, 0 };
	const int sizeFour = 9;

	std::cout << std::endl << "Third array before and after" << std::endl << "_________________" << std::endl;

	print_binary_heap(arrayThree, sizeThree);
	down_up_binary_heap(arrayThree, sizeThree);
	print_binary_heap(arrayThree, sizeThree);

	std::cout << std::endl << "Fourth array before and after" << std::endl << "_________________" << std::endl;

	print_binary_heap(arrayFour, sizeFour);
	down_up_binary_heap(arrayFour, sizeFour);
	print_binary_heap(arrayFour, sizeFour);

	return 0;
}