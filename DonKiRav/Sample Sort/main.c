#include <stdio.h>
#include <stdint.h>

void swap (int * a, int * b) { int t = *a; *a = *b; *b = t; }

void bubbleSort (int * a, const uint32_t size) {
    for (uint32_t sorted = 0; sorted < size; sorted++) {
        for (uint32_t not_sorted = size - 1; not_sorted > sorted; not_sorted--) {
            if (a[not_sorted] < a[not_sorted-1]) {
                swap(&a[not_sorted], &a[not_sorted-1]);
            }
        }
    }
}

void Vstavkami (int * a, const uint32_t size) {
    for (uint32_t sorted = 0; sorted < size; sorted++){
        uint32_t not_sorted = sorted - 1;
        int x = a[sorted];
        while (a[not_sorted] > x && not_sorted >= 0) {
           a[not_sorted+1] = a[not_sorted];
            not_sorted--;
        }
        a[not_sorted+1] = x;
    }
}
int main() {
    int size1 = 6;
    int arr1[6] = {12, 5, 77, 22, 5, 647};

    bubbleSort(arr1, size1);

    for (uint32_t i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}