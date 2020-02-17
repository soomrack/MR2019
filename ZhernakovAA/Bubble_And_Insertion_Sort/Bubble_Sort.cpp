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
    for (int left = 0; left < size; left++)
    {
        int value = array[left];
        int k = left - 1;
        for (k; k >= 0; k--)
        {
            if (value < array[k])
            {
                array[k + 1] = array[k];
            }
            else
            {
                break;
            }
        }
        array[k + 1] = value;
    }
    return 0;
}

int main()
{
    Bubble_Sort(M1, 11);
    for (int n = 0; n < 11; n++)
    {
        cout << M1[n] << endl;
    }
    cout << endl;

    insertionSort(M2,11);
    for (int g = 0; g < 11; g++)
    {
        cout << M2[g] << endl;
    }
    return 0;
}
   