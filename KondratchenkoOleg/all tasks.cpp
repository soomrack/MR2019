#include <iostream>
using namespace std;

//бинарный поиск
int binary_search(int *arr, int first, int last, int x)
{
	int middle = (last - first) / 2 + first;
	if (first-last <= 1)
	{
		if (arr[first] == x)
			return first;
		if (arr[last] == x)
			return last;
		if (arr[middle] == x)
			return middle;
		else return -1;
	}
	if (arr[middle] >= x)
		return binary_search(arr, first, middle, x);
	else
		return binary_search(arr, middle + 1, last, x);
}

//представление массива в виде кучи
void heap(int *arr, int size, int pointer) 
{
	{
		int largest = pointer;
		int left = 2 * pointer + 1;
		int right = 2 * pointer + 2;
		if (left < size && arr[left] > arr[largest])
			largest = left;
		if (right < size && arr[right] > arr[largest])
			largest = right;
		if (largest != pointer)
		{
			swap(arr[pointer], arr[largest]);
			heap(arr, size, largest);
		}
	}
}

//создание кучи
void heap_creation(int *arr, const uint32_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heap(arr, size, i);
	}
}

//пирамидальная сортировка
void sort_heap(int* arr, const int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heap(arr, i, 0);
	}
}

//сортировка пузырьком
void sort_bubble(int *arr, const size_t size)
{
	for (size_t sorted_part = 0; sorted_part < size; sorted_part++)
	{
		for (size_t unsorted_part = 0; unsorted_part < size-(sorted_part+1); unsorted_part++)
		{
			if (arr[unsorted_part] > arr[unsorted_part + 1])
			swap(arr[unsorted_part + 1], arr[unsorted_part]);
		}
	}
}

//сортировка вставками
void sort_insert(int *arr, const int size)
{
	for (int i = 0; i <size; i++)
	{
		int j = i - 1;
			while ((j >= 0) & (arr[j] > arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				j--;
			}
	}
}

//вывод массива
void cout_array(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	const int size = 5;
	//k статистика
	int k_element = 9;
	
	int arr0[size] = {5,2,4,7,8};
	int k = binary_search(arr0, 0, size, k_element);
	cout << k << std::endl;

	//создание кучи
	int arr1[size] = { 5,2,7,3,9 };
	heap_creation(arr1, size);
	sort_heap(arr1, size);
	cout_array(arr1, size);


	//сортировка пузырьком
	int arr2[size] = { 6,3,7,2,3 };
	sort_bubble(arr2, size);
	cout_array(arr2, size);

	//сортировка вставками
	int arr3[size] = {2,8,4,5,1};
	sort_insert(arr3, size);
	cout_array(arr3, size);
}
