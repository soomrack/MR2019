#include <iostream>

using namespace std;

int Bubbl(int *Arr, int const size)
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

void insertsort(int *Arr, int const size)
{
    for (int i = 1; i < size ; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Arr[i] < Arr[j])
            {
                int temp1 = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp1;
            }
        }

    }
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
    insertsort(b, 11);
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << "\n";
    }

    return(0);
}

