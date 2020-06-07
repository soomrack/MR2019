#include <iostream>

int BinarySearch(int* Array, int First, int Last, int X)
{
//Если в функцию передан массив из одного элемента
	if (First == Last)  
	{
		if (Array[First] == X) //Проверяем, является ли этот единственный элемент искомым
		{ 
			return Array[First]; 
		}
		else { return (-1); }
	}

//Если же массив включает больше одного элемента
	int Middle = (Last - First) / 2 + First; //Вычисляем номер среднего элемента и сравниваем с искомым

	if (Array[Middle] < X) 
		return(BinarySearch(Array, Middle + 1, Last, X)); 
	if (Array[Middle] > X)
		return(BinarySearch(Array, First, Middle, X));

	return Middle;
}

int main()
{
	int array[10] = {0,2,12,15,32,35,50,70,80,90};
	int first = 0;
	int last = 9;
	int x = 80;

	int result = BinarySearch(array, first, last, x);
	printf("%d", result);
	return result;
  
}

