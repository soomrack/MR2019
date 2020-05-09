#include<iostream>

using namespace std;

int MaxSubarraySum(int array[], int size)
{
    int ans = array[0];
    int sum = 0;
    int left = 0;
    int right = 0;
    int minus_position = -1;

    for (int i = 0; i < size; ++i)
    {
        sum = sum + array[i];

        if (sum > ans)
        {
            ans = sum;
            left = minus_position + 1;
            right = i;
        }

        if (sum < 0)
        {
            sum = 0;
            minus_position = i;
        }
    }

    cout << "Maximum subarray sum is " << sum;
    cout << "\nBorders of the subarray are [" << array[left] << ";" << array[right] << "]" << "\n";

    return 0;
}

int main()
{
    int array[] = { -2, -3, 4, -1, -2, 1, 5, -3, 0, 10, -4 };

    int size = sizeof(array) / sizeof(array[0]);

    MaxSubarraySum(array, size);

    return 0;

}
