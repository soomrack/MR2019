#include <iostream>
#include <algorithm>
using namespace std;

int mas[] = { 6, 7, 3, 2 };

// вспомогательная функция нахождения факториала числа
int factorial(int i)
{
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}

void narayana(int array[], const int n)
{
    // реализация первого шага
    int i = n - 2;
    while (i >= 0 && array[i] > array[i + 1])
        i--;
    if (i == -1)
        return;
    // реализация второго шага
    int j = n - 1;
    while (array[j] < array[i])
        j--;
    swap(array[i], array[j]);
    // реализация третьего шага
    for (int t = i + 1, k = n - 1; t < k; t++, k--)
        swap(array[t], array[k]);
    // вывод новой перестановки в консоль
    for (i = 0; i < n; i++)
        cout << array[i];
}

// сортировка
int bubble_Sort(int* array, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (array[j - 1] > array[j])
                swap(array[j - 1], array[j]);
        }
    }
    return 0;
}

// применение алгоритма Нарайаны
void application(int array[], int n)
{
    bubble_Sort(array, n); // сортировка массива по возрастанию
    for (int g = 0; g < n; g++)
        cout << array[g];
    int f = factorial(n); // нахождение количества возможных перестановок
    for (int r = 1; r < f; r++)
    {
        cout << "\n";
        narayana(array, n);
    }
}

int main()
{
    const int size = sizeof(mas) / sizeof(mas[0]);
    //narayana(mas, size);
    //cout << "\n";
    application(mas, size);
}
