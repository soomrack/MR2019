﻿// bubble_insert.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void bubble_sort(int32_t arr[], uint32_t size)
{
	if (size > 1)
	{
		for (uint32_t i = size - 1; i > 0; i--)
		{
			for (uint32_t j = 0; j < i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int buf = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = buf;
				}
			}
		}
	}
}

void insertion_sort(int32_t arr[], uint32_t size)
{
	for (uint32_t left = 0; left < size; left++)
	{
		uint32_t j = left - 1;
		int buf = arr[left];
		while (arr[j] > buf && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = buf;
	}
}
int main()
{
	int32_t array1[6] = { 3, 7, 1, 4, 15, 0 };
	bubble_sort(array1, 6);

	int32_t array2[8] = { 2, 15, 33, 4, 7, 1, 6, 9 };
	insertion_sort(array2, 8);
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