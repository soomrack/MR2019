#include "questions.h"
#include "mylib.h"
#include "../../SOKOLOV-D-A/CMake_Quiz-with-lib/CMake_Test/CMake_Test_library.h"

#include <stdint.h>

int32_t cmp(const void *a, const void *b);

void function(int32_t *arr, int32_t size, void (*sort)(void *arr, uint32_t lenght, uint32_t size, int32_t (*comp)(const void *a, const void *b)) = std::qsort)
{
    /* operators */
}

int main()
{
    system("chcp 1251 > null");
    initTest();
    Question Test = Question();
    Test.startTest();
    while(1);
}