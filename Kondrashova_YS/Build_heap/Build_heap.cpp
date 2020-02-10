#include "stdio.h"

#define swap(x, y) {int temp = x; x = y; y = temp;}

void regularize_heap(int array[], int i, int heap_size)
{
    int left = 2 * i;
    int right = 2 * i + 1;

    int largest;

    if (left <= heap_size && array[left] > array[i])
    {
        largest = left;
    }
    else largest = i;

    if (right <= heap_size && array[right] > array[largest]) largest = right;

    if (largest != i)
    {
        swap(array[i], array[largest]);
        regularize_heap(array, largest, heap_size);
    }
}

void build_heap(int array[], int n)
{
    int heap_size = n - 1;

    for (int i = (n / 2); i >= 0; i--) regularize_heap(array, i, heap_size);

}

void main()
{
    const int size = 5;
    int array[size] = {1, 4, 2, 5, 0};

    build_heap(array, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
