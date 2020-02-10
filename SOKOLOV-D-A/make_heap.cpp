#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

int search(int*arr, int begin, int end, int x)
{
	if (begin >= end)
	{
		if (arr[begin] == arr[end])
			return begin;
		else
			return -1;
	}
	int middle = (end - begin)/2 + begin;
	if (arr[middle] == x)
		return middle;
	else if (arr[middle] < x)
		return search(arr, middle + 1, end, x);
	else
		return search(arr, begin, middle - 1, x);


}



void make_heap(int32_t* arr, int32_t size_of_heap, int32_t rooted_node) {

	//Корень 
	int32_t largest = rooted_node;
	//Левый дочерний элемент
	int32_t l = 2 * rooted_node + 1;
	//Правый дочерний элемент
	int32_t r = 2 * rooted_node + 2;

	//Проверка, на то, чтобы родитель был старше детей
	if (l < size_of_heap && arr[l] > arr[largest])
		largest = l;
	if (r < size_of_heap && arr[r] > arr[largest])
		largest = r;

	//Наибольший элемент "всплывает" наверх, в корень
	if (largest != rooted_node) {
		std::swap(arr[rooted_node], arr[largest]);
		make_heap(arr, size_of_heap, largest);
	}
}

int main()
{
	int element = 3;
	const int size = 11;
	int arr[size] = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3, 10 };

	for (int32_t i = (size / 2) - 1; i >= 0; i--)
		make_heap(arr, size, i);

	for (int k = 0, m = 1 ; k != size; k++)
	{
		if (k == (pow(2, m)) - 1)
		{
			std::cout << std::endl;
			m++;
		}
		std::cout << arr[k]<< " ";
	}
	return 0;


}
