#include <iostream>
#include <time.h>
#include "binary_search.h"

#include <algorithm>

using namespace std;

static void printFailure(int *array, int size, int expected, int result, int number);

static void printArray(int *array, int size);

int main()
{
    srand( time(NULL) );

    int error_count = 0;

    for(int i = 0; i < 10000; i++)
    {
        int size = rand() % 20 + 1;
        int *array = new int[size];

        for(int j = 0; j < size; j++)
        {
            array[j] = rand() % 1000;
        }
        sort(array, array + size);
        int expected = rand() % size;
        int result = binarySearch(array, 0, size - 1, array[expected]);

        if(result != expected)
        {
            error_count++;
            printFailure(array, size, expected, result, i + 1);
        }

        delete[] array;
    }

    cout << "Number of errors: " << error_count << endl;
    system("pause");

    return 0;
}

static void printArray(int *array, int size)
{
    cout << "int array[" << size << "] = {";
    for(int i = 0; i < size - 1; i++)
    {
        cout << array[i] << ", ";
    }
    cout << array[size - 1] << "};" << endl;
}

static void printFailure(int *array, int size, int expected, int result, int number)
{
    cout << "Test #" << number << " failed!" << endl << endl;
    cout << "Sorted array: ";
    printArray(array, size);
    cout << "Desired number: " << array[expected] << ";" << endl;
    cout << "Expected result: " << expected << ";" << endl;
    cout << "Your result: " << result << ";" << endl << endl << endl;
}
