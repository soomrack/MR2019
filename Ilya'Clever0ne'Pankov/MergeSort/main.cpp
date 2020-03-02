#include <iostream>
#include <stdint.h>
#include <time.h>
#include <string.h>

#include <algorithm>

using namespace std;

static void printFailure(int *original, int *result, int *expected, int size);

static void printArray(int *array, int size);

void merge(int32_t *array, int32_t first, int32_t middle, int32_t last);

void mergeSort(int32_t *array, const int32_t size);

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

        mergeSort(result, size);

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

void merge(int32_t *array, int32_t first, int32_t middle, int32_t last)
{
    int32_t left_size = middle - first + 1;
    int32_t right_size = last - middle;

    int32_t *left_array = new int[left_size];
    int32_t *right_array = new int[right_size];

    for(int32_t i = 0; i < left_size; i++)
    {
        left_array[i] = array[i];
    }
    for(int32_t j = 0; j < right_size; j++)
    {
        right_array[j] = array[left_size + j];
    }
    //memcpy(left_array, array, left_size);
    //memcpy(right_array, array + left_size, right_size);

    int32_t left_index = 0;
    int32_t right_index = 0;
    int32_t index = first;

    while(left_index < left_size && right_index < right_size)
    {
        if(left_array[left_index] < right_array[right_index])
        {
            array[index] = left_array[left_index];
            left_index++;
        }
        else
        {
            array[index] = right_array[right_index];
            right_index++;
        }
        index++;
    }

    while(left_index < left_size)
    {
        array[index] = left_array[left_index];
        left_index++;
        index++;
    }

    while(right_index < right_size)
    {
        array[index] = right_array[right_index];
        right_index++;
        index++;
    }

    delete[] left_array;
    delete[] right_array;
}

void mergeSort(int32_t *array, const int32_t size)
{
    if(size > 1)
    {
        int32_t first = 0;
        int32_t last = size - 1;
        int32_t middle = first + (last - first) / 2;

        mergeSort(array, middle + 1);
        mergeSort(array + (middle + 1), size - (middle + 1));
        merge(array, first, middle, last);
    }
}