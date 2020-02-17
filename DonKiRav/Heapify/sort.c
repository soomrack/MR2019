#include <stdio.h>
#include <stdint.h>

//Procedure for exchange
void swap (int *a, int *b) { int t = *a; *a = *b; *b = t; }

//Procedure for converting to a binary heap a subtree with root node i
void heapify(int * arr, const int32_t n, const int32_t i)
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

//The main function that performs heap sorting
void heapSort(int * arr, const int32_t n)
{
  //Heap building (array rearrangement)
  for (int32_t i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
  //One by one we extract elements from a heap
  for (int32_t i = n - 1; i >= 0; i--)
  {
    //Move the current root to the end
    swap(&arr[0], &arr[i]);
    //Call the heapify procedure on the reduced heap
    heapify(arr, i, 0);
  }
}

int main() {
    int size1 = 6;
    int arr1[6] = {12, 5, 77, 22, 5, 647};

    heapSort(arr1, size1);

    for (uint32_t i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
