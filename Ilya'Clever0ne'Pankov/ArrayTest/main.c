#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a;
} A;

typedef struct {
    int b;
    A A;
} B;

void printArray(int cols, int array[][cols])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("%\n");
    }
}

void printArray1(int arr[])
{
    for(int k = 0; k < 10; k++)
        printf("%d ", arr[k]);
}

void printArray2(int *arr)
{
    for(int k = 0; k < 10; k++)
        printf("%d ", arr[k]);
}

int main()
{
    srand(1);
    int array[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j] = rand() % 10;
        }
    }

    /*for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("%\n");
    }*/

    printArray(10, array);

    while(1);
    return 0;
}