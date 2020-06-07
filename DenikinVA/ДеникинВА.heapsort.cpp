#include <iostream>
using namespace std;

void heapify(int array[], uint16_t size_of_array, int i)
{
	// Объявляем наибольший элемент, используем его как корень
	uint32_t biggest_element = i;

	// Объявляем элементы справа и слева
	uint32_t left_element = 2 * i + 1;
	uint32_t right_element = 2 * i + 2;

	// Сравниваем жлементы справа и слева с самым большим
	if (left_element < size_of_array && array[left_element] > array[biggest_element])
	{
		biggest_element = left_element;
	}
	if (right_element < size_of_array && array[right_element] > array[biggest_element])
	{
		biggest_element = right_element;
	}

	// Проверяем, если больший элемент не корень
	if (biggest_element != i)
	{
		swap(array[i], array[biggest_element]);
		heapify(array, size_of_array, biggest_element);
	}
}

void HeapSort(int array[], uint16_t size_of_array)
{
	// Построение двоичной кучи
	for (int i = size_of_array / 2 - 1; i >= 0; i--)
	{
		heapify(array, size_of_array, i);
	}

	// Перемещение корня в конец и вызов heapify
	for (int i = size_of_array - 1; i >= 0; i--)
	{
		swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}

void Print(int array[], uint16_t size_of_array)
{
	for (int i = 0; i < size_of_array; i++)
	{
		cout << array[i] << " ";
	}
}


int main()
{
	int array[] = { 7, 46, 2, 71, 62, 17 };
	uint16_t size_of_array = sizeof(array) / sizeof(array[0]);
	cout << "Unsorted array: ";
	Print(array, size_of_array);
	HeapSort(array, size_of_array);
	cout << "\n  Sorted array: ";
	Print(array, size_of_array);
	return 0;
}
