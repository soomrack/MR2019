#include <iostream>
#include <algorithm>
using namespace std;


int M1[11] = { 2, 42, -32, 12, 42, 24, -234, 311, 11, -12, 1212 };
int M2[11] = { 2, 42, -32, 12, 42, 24, -234, 311, 11, -12, 1212 };

int Bubble_Sort(int* array, const int size)
{
    for (int first_couter = 0; first_couter < size - 1; first_couter++)
    {
        for (int second_couter = (size - 1); second_couter > first_couter; second_couter--)
        {
            if (array[second_couter - 1] > array[second_couter])
                swap(array[second_couter - 1], array[second_couter]);
        }
    }
    return 0;
}

int insertionSort(int* array, const int size)
{
    for (int left = 0; left < size; left++)
    {
        int value = array[left];
        int counter = left - 1;
        for (counter; counter >= 0; counter--)
        {
            if (value < array[counter])
            {
                array[counter + 1] = array[counter];
            }
            else
            {
                break;
            }
        }
        array[counter + 1] = value;
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

    insertionSort(M2, 11);
    for (int g = 0; g < 11; g++)
    {
        cout << M2[g] << endl;
    }
    return 0;
}