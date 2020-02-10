#include <iostream>

using namespace std;

void buildHeap(int *array, int size);

void siftUp(int *array, int index);

void siftDown(int *array, const int size, int index);

void swap(int &a, int &b);

int main()
{
    int size = 7;
    int array[] = {6, 3, 2, 7, 1, 4, 5};
    buildHeap(array, 7);

    cout << "int array[" << size << "] = {";
    for(int i = 0; i < size - 1; i++)
    {
        cout << array[i] << ", ";
    }
    cout << array[size - 1] << "};" << endl;

    system("pause");

    return 0;
}

void buildHeap(int *array, int size)
{
    /*int index = 0;
    while(index < size)
    {
        siftUp(array, index);
        index++;
    }*/

    int index = size / 2;
    while(index >= 0)
    {
        siftDown(array, size, index);
        index--;
    }
}

void siftUp(int *array, int index)
{
    while(array[index] > array[(index - 1) / 2])
    {
        swap(array[index], array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void siftDown(int *array, const int size, int index)
{
    while(2 * index + 1 < size)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest_index = left;
        if(right < size && array[right] > array[left])
        {
            largest_index = right;
        }
        if(array[index] < array[largest_index])
        {
            swap(array[index], array[largest_index]);
            index = largest_index;
        }
        else break;
    }
}

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}