#include <iostream>
#include <utility>
#include <stdio.h>

using namespace std;


static void Bottom_Up_Heapify(int* array, const int size)
{
	if (size == 1)
		return;

	bool swap_counter = true;

	while (swap_counter != false)
	{
		swap_counter = false;
		for (int current_parent = (size) / 2 - 1; current_parent >= 0; current_parent--)
		{
			int current_child = 2 * current_parent + 1;
			int border = current_child + 2;
			while ((current_child < size) && (current_child < border))
			{
				if (array[current_parent] <= array[current_child])
					current_child++;
				else
				{
					swap(array[current_parent], array[current_child]);
					swap_counter = true;
					current_child++;
				}
			}
		}
	}
}


static void HeapSort(int* array, int size)
{
	Bottom_Up_Heapify(array, size);

	int new_size = size;

	for (int current = (size - 1); current > 0; current--)
	{
		swap(array[current], array[0]);
		new_size--;
		Bottom_Up_Heapify(array, new_size);
	}

	//Вывод для проверки	
	for (int counter = 0; counter < size; counter++)
	{
		printf("%d ", array[counter]);
	}

	return;
}

static int Array[7] = {24, 31, 15, 20, 52, 1, 100};
static const int Size = 7;

int main()
{
	HeapSort(Array, Size);
	return 0;
}

