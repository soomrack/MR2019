#include <stdio.h>
#include <stdint.h>

int32_t bin_search( const int * arr, const int first, const int last, const uint32_t j )
{
    if (first == last) {
        if (arr[first] == j) { return first;}
        else { return -1;}
    }
    int middle = (last - first)/2 + first;
    if (arr[middle] < j) { return bin_search(arr, middle+1, last, j);}
    else { return bin_search(arr, first, middle, j);}
}

int main() {
    int element;
    scanf("%d", &element);
    int size1 = 6;
    int a;
    int arr1[6] = {2, 5, 16, 22, 44, 647};
    a = bin_search(arr1, 0, size1-1, 22);
    printf("%d", a);
    return (1);
}