#include <iostream>
using namespace std;

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapBuild(int arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapBuild(arr, n, largest);
    }
}

int main()
{
    int M[15] = { 7,3,2,9,23,5,1,6,72,4,34,66,757,21,44 };
    int n = sizeof(M) / sizeof(M[0]);
    for (int i = n / 2 - 1; i >= 0; i--)
        heapBuild(M, n, i);

    // Вывод на экран
    int g = 0;
    int k = 1;
    while (g < n)
    {
        while (g < k && g < n) 
        {
            cout << M[g] << " ";
            g++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}
