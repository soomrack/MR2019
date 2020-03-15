#include <iostream>

void sift_up(int* array, int index);
void heapify(int* array, const int size, int root);
void swap(int& a, int& b);

int main()
{
	int array1[10]{ 72, 2, 1, 7, 9, 3, 4, 6 , 23, 5 };
	heapify(array1, 10, 0);
}

void sift_up(int* array, int index)
{
    while (array[index] > array[(index - 1) / 2])
    {
        swap(array[index], array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapify(int* array, const int size, int root)
{
	if (root >= size)
		return;
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (array[largest] < array[left] && left < size)
	{
		largest = left;
	}
	if (array[largest] < array[right] && right < size)
	{
		largest = right;
	}
	if (root != largest)
	{
		swap(array[root], array[largest]);
	}
	sift_up(array, root);
	heapify(array, size, left);
	heapify(array, size, right);
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
