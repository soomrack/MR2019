#include <stdio.h>
#include <stdint.h>
//Procedure for exchange
void swap (int * a, int * b) { int t = *a; *a = *b; *b = t; }

//Procedure for converting to a binary heap a subtree with root node i
void heapify(int * arr, const int32_t size, const int32_t current_element)
    {
        int32_t largest = current_element;
        int32_t left = 2*current_element + 1;
        int32_t right = 2*current_element + 2;
        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != current_element)
        {
            swap(&arr[current_element], &arr[largest]);
            heapify(arr, size, largest);
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
