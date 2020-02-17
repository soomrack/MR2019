#include <iostream>
#include <algorithm>
using namespace std;


int M1[11] = {2, 42, -32, 12, 42, 24, -234, 311, 11, -12, 1212};
int M2[11] = {2, 42, -32, 12, 42, 24, -234, 311, 11, -12, 1212};

int Bubble_Sort(int* array, const int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j=(size-1); j > i; j--)
        {
            if (array[j - 1] > array[j])
                swap(array[j - 1], array[j]);
        }
    }
    return 0;
}

int insertionSort(int* array, const int size)
{
    for (int i = 1; i < size - 1; i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1])
        {
            swap(array[j], array[j + 1]);
            j--;
        }
    }
    return 0;
}

int main()
{
    Bubble_Sort(M1, 11);
    for (int k = 0; k < 11; k++)
    {
        cout << M1[k] << endl;
    }
    cout << endl;

    insertionSort(M2,11);
    for (int g = 0; g < 11; g++)
    {
        cout << M2[g] << endl;
    }
}



   