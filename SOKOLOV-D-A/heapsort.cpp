#include <iostream>


static void sieve_heap(int32_t* arr, const int32_t size_of_heap, int32_t rooted_node)
{
	int32_t root = rooted_node;
	int32_t left_node = 2 * rooted_node + 1;
	int32_t right_node = 2 * rooted_node + 2;

	if (left_node < size_of_heap && arr[left_node] > arr[root])
		root = left_node;
	if (right_node < size_of_heap && arr[right_node] > arr[root])
		root = right_node;

	if (root != rooted_node) {
		std::swap(arr[rooted_node], arr[root]);
		sieve_heap(arr, size_of_heap, root);
	}
}


void heapsort(int32_t* arr, const uint32_t size)
{

	//Создание кучи из неупорядочных данных
	for (int32_t i = (size / 2) - 1; i >= 0; i--)
		sieve_heap(arr, size, i);

	//Сортировка
	for (int32_t i = size - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		sieve_heap(arr, i, 0);
	}




int main()
{
	int element = 3;
	const int size = 11;
	int arr[size] = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3, 10 };

	heapsort(arr,size);
	
	return 0;


}
