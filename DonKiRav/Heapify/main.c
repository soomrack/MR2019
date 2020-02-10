#include <stdio.h>
#include <stdint.h>

//Procedure for exchange
void swap (int *a, int *b) { int t = *a; *a = *b; *b = t; }
//Procedure for converting to a binary heap a subtree with root node i
void heapify(int * arr, int32_t n, int32_t i)
{
//Initialize the largest element as root
        int32_t largest = i;
//Initialize the left child
        int32_t left = 2*i + 1;
//Initialize the right child
        int32_t right = 2*i + 2;
//If the left child is larger than the root
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
//If the right child is larger than the largest at the moment
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
//If the biggest element is not root
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
//Recursively convert the affected subtree into a binary heap
            heapify(arr, n, largest);
        }
}

int main() {

    int32_t size1 = 6;
    int arr1[6] = {2, 5, 66, 22, 14, 647};
    for (int32_t i = size1 / 2 - 1; i >= 0; i--)
    {
        heapify(arr1, size1, i);
    }
    for (int32_t i = 0; i < size1; i++) {
    printf("%d ", arr1[i]);}
    return 1;
}
