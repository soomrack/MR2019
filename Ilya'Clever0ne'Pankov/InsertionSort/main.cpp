#include <iostream>
#include <stdint.h>
#include <time.h>
#include <string.h>

#include <algorithm>

using namespace std;

static void printFailure(int *original, int *result, int *expected, int size);

static void printArray(int *array, int size);

void insertionSort(int32_t *array, const int32_t size);

void swap(int32_t &a, int32_t &b);

int main()
{
    srand( time(NULL) );

    int error_count = 0;

    for(int i = 0; i < 10000; i++)
    {
        int size = rand() % 20 + 1;
        int *original = new int[size];
        int *result = new int[size];
        int *expected = new int[size];

        for(int j = 0; j < size; j++)
        {
            result[j] = rand() % 1000;
            original[j] = result[j];
            expected[j] = result[j];
        }
        sort(expected, expected + size);

        insertionSort(result, size);

        if(memcmp(result, expected, size) != 0)
        {
            printFailure(original, result, expected, size);

            error_count++;
        }

        delete[] result;
        delete[] original;
        delete[] expected;
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

static void printFailure(int *original, int *result, int *expected, int size)
{
    cout << "Test failed!" << endl << endl;
    cout << "Original array: ";
    printArray(original, size);
    cout << "Your result: ";
    printArray(result, size);
    cout << "Expected result: ";
    printArray(expected, size);
    cout << endl << endl;
}

void swap(int32_t &a, int32_t &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void insertionSort(int32_t *array, const int32_t size)
{
    for(int32_t border = 1; border < size; border++)
    {
        for(int32_t index = border; index > 0; index--)
        {
            if(array[index] < array[index - 1])
            {
                swap(array[index], array[index - 1]);
            }
        }
    }
}