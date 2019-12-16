#include <iostream>

// Задание: Имеется два массива. Необходимо составить 3 массив, который не содержит одинаковые элементы в 1 и 2. Т.е их выкидывает. 
using namespace std;
const int N1 = 5;
const int N2 = 6;

int array_1[N1] = {1,2,3,4,5};
int array_2[N2] = {5,7,3,9,5,3};
bool flag;
int SP;

//void perebor(int arr1, int arr2, int size1, int size2)
//{
//	
//	for (int i = 0; i < N1; i++)
//	{
//		flag = false;
//		for (int j = 0; j < N2; j++)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				array_2[j] = 0;
//				flag = true;
//				SP++;
//			}
//		}
//		if (flag == true)
//		{
//			array_1[i] = 0;
//			SP++;
//		}
//	}
//}


int main()
{
	//Вывод двух массивов
	cout << "First array: ";
	for (int i = 0; i < N1; i++) 
	{
		cout << array_1[i] << " ";
	}
	cout << "\nSecond array: ";
	for (int i = 0; i < N2; i++)
	{
		cout << array_2[i] << " ";
	}
	SP = 0;
	//Цикл по исключению повторяющихся элементов
	for (int i = 0; i < N1; i++)
	{
		flag=false;
		for (int j = 0; j < N2; j++)
		{
			if (array_1[i] == array_2[j])
			{
				array_2[j] = 0;
				flag = true;
				SP++;
			}
		}
		if (flag == true)
		{
			array_1[i] = 0;
			SP++;
		}
	}
	//Задание 3 динамического массива
	int* array_3 = new int[N1+N2-SP]; //выделение памяти без лишних

	cout << "\nThird array: ";
	SP = 0;
	for (int i = 0; i < N1;i++)
	{
		if (array_1[i] != 0) 
		{ 
			array_3[SP++] = array_1[i]; 
		}
	}
	for (int i = 0; i < N2;i++)
	{
		if (array_2[i] != 0) 
		{ 
			array_3[SP++] = array_2[i];
		}
	}
	for (int i = 0; i < SP;i++)
	{
		cout << array_3[i] << " ";
	}
}

