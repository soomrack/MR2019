// BubbleSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>


void swap(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

// A function to implement bubble sort  
void bubbleSort(int* arr, const int n)
{
    int index, j;
    for (index = 0; index < n - 1; index++)

        // Last index elements are already in place  
        for (j = 0; j < n - index - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void InsertionSort(int* arr, const int n)
{
    int index, j;
    for (int index = 1; index < n; index++)
        for (int j = index; j > 0 && arr[j - 1] > arr[j]; j--) // пока j>0 и элемент j-1 > j, arr-массив int
            swap(&arr[j - 1], &arr[j]);
}


//Without using swap
void InsertionSortSmall(int* arr, const int n)
{
    
    for (int index = 1; index < n; index++)
    {
        int current = arr[index];
        int j = index;
        while (j > 0 && current < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = current;
    }
}

/* Function to print an arr */
void printArray(int* arr, int size)
{
    int index;
    for (index = 0; index < size; index++)
        std::cout << arr[index] << " ";
    std::cout << std::endl;
}


int main()
{
    int arr[] = { 9, 1, 4, 5, 6, 2, 11, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);
    //bubbleSort(arr, n);
    //InsertionSort(arr, n);
    InsertionSortSmall(arr, n);
    std::cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Efirstlorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
