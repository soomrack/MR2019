

#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < size && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < size && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		int32_t temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, size, largest);
	}
}


void sort(int32_t* arr, uint32_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = size - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		int32_t temp2 = arr[i];
		arr[i] = arr[0];
		arr[0] = temp2;
		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}


int main()
{
	int32_t A[10] = { 9,8,7,6,5,4,3,2,1,0 };
	sort(A, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << "\n";
	}
}

