// Heapsort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//13244
#include <iostream>

void heapsort(int32_t* arr, int32_t size, int32_t count)
{
	int32_t indexofMax = count;
	int32_t left = 2 * count + 1;
	int32_t right = 2 * count + 2;

	// If left child is larger than root 
	if (left<size && arr[left]>arr[indexofMax])
		indexofMax = left;
	// If right child is larger than largest		
	if (right<size && arr[right]>arr[indexofMax])
		indexofMax = right;
	// If largest is not root     
	if (indexofMax != count)
	{
		int swap = arr[indexofMax];
		arr[indexofMax] = arr[count];
		arr[count] = swap;
		heapsort(arr, size, indexofMax);
	}
}
void sort(int32_t* arr, uint32_t size)
{
	// build heap
	for (int count = (size / 2) - 1; count >= 0; count--)
		heapsort(arr, size, count);

	// One by one extract an element from heap 
	for (int count = size - 1; count >= 1; count--)
	{
		// Move current root to end
		int32_t swap = arr[count];
		arr[count] = arr[0];
		arr[0] = swap;
		// call max heapsort on the reduced heap 
		heapsort(arr, count, 0);
	}
}

int32_t getMedian(int32_t* arr, uint32_t size)
{
	sort(arr, size);
	return arr[size / 2];
}


int main(void)
{


	int mediana22;

	int32_t arr[5] = { 0,2,1,5,3 };
	uint32_t size = 5;

	mediana22 = getMedian(arr, size);
	std::cout << mediana22;
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
