#include "questions.h"
#include "mylib.h"
#include "../../SOKOLOV-D-A/CMake_Quiz-with-lib/CMake_Test/CMake_Test_library.h"

#include <stdint.h>

int32_t cmp(const void *a, const void *b);

void function(int32_t *arr, int32_t size, void (*sort)(void *arr, uint32_t lenght, uint32_t size, int32_t (*comp)(const void *a, const void *b)) = std::qsort)
{
    /* operators */
}
void foo(int **arr){
    //for (int i =0; i<n; i++){
    //    *array[n]=5;
    //}
};
int main()
{
   // system("chcp 1251 > null");
   // initTest();
   // Question Test = Question();
   // Test.startTest();
   int **a[2][10];

   int c[2][10] { {1,2,3,4,5,6,7,8,9,10}, {1,2,3,4,5,6,7,8,9,10} };

   int m=10;
    //foo(m, (*c)[2]);
    foo(a[2][10]);
   for (int i =0; i<2; i++){
       for (int j=0; j<10; j++){
       std::cout<<c[i][j];
       }
   }

    return 0;
}