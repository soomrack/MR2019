#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

void Merge(int* Array, int first, int last)
{
	int* mas = new int[100];
	int middle = (first + last) / 2;
	int start = first;		
	int final = middle + 1;
	
	for (int j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (Array[start] < Array[final])))
		{
			mas[j] = Array[start];
			start++;
		}
		else
		{
			mas[j] = Array[final];
			final++;
		}

	for (int j = first; j <= last; j++)
	{
		Array[j] = mas[j];
	}

	delete[]mas;
};

void MergeSort(int* A, int first, int last)
{
	if (first < last)
	{
		MergeSort(A, first, (first + last) / 2);     //sorting of the left side
		MergeSort(A, (first + last) / 2 + 1, last);  //sorting of the right side
		Merge(A, first, last);
	}
};

void main()
{
	srand(time(0));

	int size;
	cout << "Size of the array > "; cin >> size;
	int* Rand_array = new int[100];
	
	for (int i = 1; i <= size; i++)
	{
		Rand_array[i] = rand() % 100 -100;
		cout << i << " element > " << Rand_array[i] << "\n";
	}

	MergeSort(Rand_array, 1, size);

	cout << "The array after sort: ";

	for (int i = 1; i <= size; i++) cout << Rand_array[i] << " ";
	
	delete[]Rand_array;
}