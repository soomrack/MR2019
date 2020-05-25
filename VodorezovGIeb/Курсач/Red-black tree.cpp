#include <iostream>
#include "RBTree.h"
#include <ctime>
using namespace std;

int main() {
    int N = 1000*1000*1 ;   //максимум элементов
    RBTree rbTree1;

    //считаем время вставки от 1 до N элементов с шагом в 1 порядок  Красно-черное дерево 
    for (int j = 1; j <= N; j*=10)
    {
        cout << j << " elements" << endl;
        int start_time = clock();
        for (int i = 0; i < j ; i++)
        {
            rbTree1.insertValue(rand());
        }
        int end_time = clock(); // конечное время
        cout  << end_time - start_time << "ms" << "\n-------" << endl;

    }

    return 0;
}