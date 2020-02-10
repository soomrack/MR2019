#include <iostream>
using namespace std;

int binary_search(int* arr, int begin, int end, int x)
{
	if (begin >= end)
	{
		if (arr[begin] == x)
			return begin;		//k статистика
		else
			return -1;		//-1: отсутствие x элемента в массиве
	}
	int middle = (end - begin) / 2 + begin;
	if (arr[middle] < x)
		return binary_search(arr, middle + 1, end, x);
	else
		return binary_search(arr, begin, middle - 1, x);
}

int main()
{
	int k_element = 8;					//искомый элемент
	const int size = 11;					//размер массива
	int arr[size] = {5,2,4,7,8,11,12,13,124,1,6};		//массив
	int k = binary_search(arr, 0, size, k_element);		//k статистика
	std::cout << k << std::endl;
}