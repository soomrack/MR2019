
#include <iostream>
using namespace std;


int merge_sort(int arr[], int left, int right)
{
    if ((right - left) == 0)
    {
        return arr[0];
    }

    if (right - left == 1) {
        if (arr[right] < arr[left])
            swap(arr[right], arr[left]);
        return arr[1];
    }

    int middle = (right + left) / 2;
    merge_sort(arr, 0, middle);
    merge_sort(arr, middle+1, right);

    int buf[11];
    int xl = left;
    int xr = middle + 1;
    int cur = 0;
    while (right - left + 1 != cur) {
        if (xl > middle)
            buf[cur++] = arr[xr++];
        else if (xr > right)
            buf[cur++] = arr[xl++];
        else if (arr[xl] > arr[xr])
            buf[cur++] = arr[xr++];
        else buf[cur++] = arr[xl++];

    }
    for (int i = 0; i < cur; i++)
        arr[i + left] = buf[i];

}

int main()
{
    int a[11] = { 2,42,-32,12,42,24,-234,311,11,-12,1212 };
    merge_sort(a,0,10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "\n";
    }

}

