// Quickselect.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
// Partition using Lomuto partition scheme
int32_t partition(int32_t* a, int32_t left, int32_t right, int32_t pivotIndex) {
    // Pick pivotIndex as pivot from the array
    int32_t pivot = a[pivotIndex];
    int32_t swap;

    // Move pivot to end
    //SWAP(a[pivotIndex], a[right]);
    swap = a[pivotIndex];
    a[pivotIndex] = a[right];
    a[right] = swap;

    // elements less than pivot will be pushed to the left of pIndex
    // elements more than pivot will be pushed to the right of pIndex
    // equal elements can go either way
    int32_t pIndex = left;
    int i;

    // each time we finds an element less than or equal to pivot, pIndex
    // is incremented and that element would be placed before the pivot.
    for (i = left; i < right; i++) {
        if (a[i] <= pivot) {
            //SWAP(a[i], a[pIndex]);
            swap = a[i];
            a[i] = a[pIndex];
            a[pIndex] = swap;
            pIndex++;
        }
    }

    // Move pivot to its final place
    //SWAP(a[pIndex], a[right]);
    swap = a[pIndex];
    a[pIndex] = a[right];
    a[right] = swap;

    // return pIndex (index of pivot element)
    return pIndex;
}

// Returns the k-th smallest element of list within left..right (inclusive)
int32_t quickselect(int32_t* A, int32_t left, int32_t right, int32_t k) {
    while (1) {
        // If the array contains only one element, return that element
        if (left == right)
            return A[left];

        // select a pivotIndex between left and right
        int32_t pivotIndex = left + rand() % (right - left + 1);

        pivotIndex = partition(A, left, right, pivotIndex);

        // The pivot is in its final sorted position
        if (k == pivotIndex)
            return A[k];

        // if k is less than the pivot index
        else if (k < pivotIndex)
            right = pivotIndex - 1;

        // if k is more than the pivot index
        else
            left = pivotIndex + 1;
    }
}



int32_t getMedian(int32_t* arr, uint32_t size) {
    return quickselect(arr, 0, size - 1, size / 2);
}

int main(void)
{
    //	int a;
    int32_t arr[5] = { 0,2,1,5,3 };
    uint32_t size = 5;

    int32_t mediana = getMedian(arr, size);

    for (int count = 0; count < 5; count++)
        printf("%d ", arr[count]);
    printf("\n");
    std::cout << mediana;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
