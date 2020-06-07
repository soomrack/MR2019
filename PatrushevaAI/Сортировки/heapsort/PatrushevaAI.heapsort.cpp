
#include <iostream>

void swap(int& a, int& b)
{
	int iTemp;
	iTemp = a;
	a = b;
	b = iTemp;
}
void heapify(int32_t* arr, int32_t size, int32_t count)
{
	//Инциализируем наибольший элемент как корень
	int32_t indexofMax = count;

	int32_t left = 2 * count + 1; //левый
	int32_t right = 2 * count + 2; // правый

	// Если левый дочерний элемент больше корня
	if (left<size && arr[left]>arr[indexofMax])
		indexofMax = left;

	// Если правый дочерний элемент больше, чем наибольший элемент на данный момент	
	if (right<size && arr[right]>arr[indexofMax])
		indexofMax = right;

	// Если наибольший элемент не является корнем    
	if (indexofMax != count)
	{
		swap(arr[count], arr[indexofMax]);
	

		heapify(arr, size, indexofMax);
	}
}

void heapsort(int arr[], int number)
{
	// Построение кучи (перегруппируем массив)
	for (int i = number / 2 - 1; i >= 0; i--)
		heapify(arr, number, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = number - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}



void printArray(int arr[], int number)
{	
	for (int i = 0; i < number; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
	
}


int main()
{
	int32_t arr1[10] = { 0,8,7,6,4,5,3,2,1,9 };

	int32_t arr2[13] = { 345,99,100,0,8,7,6,4,5,3,2,1,9 };

	int number1 = sizeof(arr1)/sizeof(arr1[0]);
	int number2 = sizeof(arr2) / sizeof(arr2[0]);

	for (int i = 0; i < number2; i++)
	{
		std::cout << arr2[i] << " ";
	}
	std::cout << "\n";

	//heapsort(arr1, number1);
	heapsort(arr2, number2);

	std::cout << "Sorted array is \n";
	//printArray(arr1, number1);
	printArray(arr2, number2);
}
