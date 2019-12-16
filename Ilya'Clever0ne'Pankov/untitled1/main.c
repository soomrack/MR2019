#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    int array[] = {2, 3, 1, 3, 2, -5, -10, -5, 1, -2, -2};
    int number = 0;
    for(int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        number ^= array[i];
    }
    printf("%d", number);
    int a = 2;
    int b = 5;
    swap(&a, &b);
    printf("\n%d, %d", a, b);
}*/

#define M 10
#define N 10

int main()
{
    int32_t **array;
    array = malloc(N * sizeof(int32_t *));
    for(int32_t index = 0; index < N; index++)
    {
        array[index] = malloc(M * sizeof(int32_t));
    }
    for (int32_t i = 0; i < M; i++)
    {
        for (int32_t j = 0; j < N; j++)
        {
            array[i][j] = rand() % 1000;
        }
    }
    for (int32_t i = 0; i < N; i++)
    {
        for (int32_t j = 0; j < M; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    for(int32_t index = 0; index < N; index++)
    {
        free(array[index]);
    }
    free(array);
    int a;
    scanf("%d", a);
}