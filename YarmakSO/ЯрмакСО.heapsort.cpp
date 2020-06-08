// kod.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stdio.h"
using namespace std;

void heapify(int array[], int index, int heap_index)
{
    int left_element = 2 * index; 
    int right_element = 2 * index + 1; 

    int largest; 

    if (left_element <= heap_index && array[left_element] > array[index])
    {
        largest = left_element;
    }
    else largest = index;

    if (right_element <= heap_index && array[right_element] > array[largest])
    {
        largest = right_element;
    }

    if (largest != index)
    {
        swap(array[index], array[largest]);
        heapify(array, largest, heap_index);
    }
}

void build_heap(int array[], int n)
{
    int heap_size = n - 1;

    for (int index = (n / 2); index >= 0; index--) heapify(array, index, heap_size);

}

void heapsort(int* arr, unsigned int size)
{
    build_heap(arr, size);

    int heap_size = size - 1;

    for (int index = heap_size; index >= 0; index--)
    {
        swap(arr[0], arr[heap_size]);

        heap_size--;

        heapify(arr, 0, heap_size);

    }
}

int main()
{
    const int size = 9;
    int array[size];
    for (int i = 0; i < size; i++) 
    {
        cin >> array[i]; 
    }

    heapsort(array, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
	
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
