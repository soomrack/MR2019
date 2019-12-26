#include <iostream>
#include "TestLIb.h"
int32_t cmp(const void *a, const void *b);

void function(int32_t *arr, int32_t size, void (*sort)(void *arr, uint32_t lenght, uint32_t size, int32_t (*comp)(const void *a, const void *b)) = std::qsort)
{
    /* operators */
}

int main()
{
    system("chcp 1251 > null");
    Question Test = Question();
    Test.startTest();

    return 0;
}