#include <iostream>
#include <algorithm>
using namespace std;

void HeapBuild(int* const array, int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        for (int root = 0; root < numberOfElements; root++)
        {
            int left = 2 * root + 1;
            if (left > numberOfElements - 1)
                break;
            int right = 2 * root + 2;
            int MaxOfTwo = max(array[left], array[right]);
            if (array[root] < MaxOfTwo && MaxOfTwo == array[left])
            {
                swap(array[root], array[left]);
            }
            else if (array[root] < MaxOfTwo && MaxOfTwo == array[right])
            {
                swap(array[root], array[right]);
            }
        }
    }
}

int main()
{
    int M[15] = { 7,3,2,9,23,5,1,6,72,4,34,66,757,21,44 };
    int n = sizeof(M) / sizeof(M[0]);
    HeapBuild(M,n);

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
