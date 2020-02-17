#include <iostream>

using namespace std;

int Bubbl(int *Arr, const int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (Arr[j-1] > Arr[j])
            {
                int temp = Arr[j - 1];
                Arr[j-1] = Arr[j];
                Arr[j] = temp;
            }
        }
    }
    return(0);
}

//void insertsort(int *Arr, const int size)
//{
//    for (int i = 1; i < size ; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (Arr[i] < Arr[j])
//            {
//                int temp1 = Arr[i];
//                Arr[i] = Arr[j];
//                Arr[j] = temp1;
//            }
//        }
//
//    }
//}

int insertionSort(int* array, const int size)
{
    for (int left = 0; left < size; left++)
    {
        // Вытаскиваем значение элемента
        int value = array[left];
        // Перемещаемся по элементам, которые перед вытащенным элементом
        int i = left - 1;
        for (i; i >= 0; i--)
        {
            // Если вытащили значение меньшее — передвигаем больший элемент дальше
            if (value < array[i])
            {
                array[i + 1] = array[i];
            }
            else
            {
                // Если вытащенный элемент больше — останавливаемся
                break;
            }
        }
        // В освободившееся место вставляем вытащенное значение
        array[i + 1] = value;
    }
    return 0;
}


int main()
{
    int a[11] = {2,42,-32,12,42,24,-234,311,11,-12,1212 };
    Bubbl(a, 11);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "\n";
    }

    cout << "\n";
    cout << "\n";
    cout << "\n";

    int b[11] = { 2,42,-32,12,42,24,-234,311,11,-12,1212 };
    insertionSort(b, 11);
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << "\n";
    }

    return(0);
}

