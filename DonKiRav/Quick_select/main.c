#include <stdio.h>
#include <stdint.h>

//Procedure for exchange
void swap (int * a, int * b) { int t = *a; *a = *b; *b = t; }

//Procedure for selecting and locating a pivot element
int allocation(int32_t * arr, const uint32_t left, const uint32_t right)
{
  int pivot = arr[right];
  int position = left;
  for (uint32_t j = left; j <= right; j++)
  {
    if (arr[j] <= pivot)
    {
      swap(&arr[position++], &arr[j]);
    }
  }
  position--;
  return position;
}

int32_t getOrderStatistic( int32_t * arr, const uint32_t size, const uint32_t j )
{
  uint32_t left = 0;
  uint32_t right = size - 1;
  for(;;)
  {
    uint32_t pivot = allocation(arr, left, right);
    if (pivot > j)
    {
      right = pivot - 1;
    }
    else if (pivot < j)
    {
      left = pivot + 1;
    }
    else
    {
      return arr[j];
    }
  }
}

int main() {
    int32_t size1 = 6;
    int a;
    int arr1[6] = {2, 5, 66, 22, 14, 647};
    a = getOrderStatistic(arr1, size1, 3);
    printf("%d", a);
    return (1);
}
