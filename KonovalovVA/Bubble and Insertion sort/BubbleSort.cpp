#include <stdio.h>
#include <stdint.h>
void Swap(int* arr, int a, int b)
{
    int buf = arr[a];
    arr[a] = arr[b];
    arr[b] = buf;
}
void BubbleSort(int* arr, const int size) 
{
    int buf;
    for (int border = 0; border < size; border++)
    {
        for (int j = size - 1; j > border; j--)
        {
            if (arr[j] > arr[j - 1]) 
            {
                Swap(arr, j - 1, j);
            }
        }
    }
}

void InsertionSort(int* arr, const int size) 
{
    for (int border = 0; border < size; border++) 
    {
        int j = border - 1;
        int buf = arr[border];
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
    int size_1 = 9;
    int array_1[9] = {5, 1, 15, 12, 42, 33, 16, 87, 115};
    BubbleSort(array_1, size_1);
    for (int border = 0; border < size_1; border++)
    {
        printf("%d ", array_1[border]);
    }
    printf("\n");
    int size_2 = 5;
    int array_2[5] = { 13, 9, 198, 55, 22 };
    InsertionSort(array_2, size_2);
    for (int border = 0; border < size_2; border++)
    {
        printf("%d ", array_2[border]);
    }
    return 0;
}
