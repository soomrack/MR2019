#include <stdio.h>
#include <stdint.h>

void swap (int * a, int * b) { int t = *a; *a = *b; *b = t; }

void bubbleSort (int * a, const uint32_t size) {
    for (uint32_t size_sorted_part = 0; size_sorted_part < size; size_sorted_part++) {
        for (uint32_t size_not_sorted_part = size - 1; size_not_sorted_part > size_sorted_part; size_not_sorted_part--) {
            if (a[size_not_sorted_part] < a[size_not_sorted_part-1]) {
                swap(&a[size_not_sorted_part], &a[size_not_sorted_part-1]);
            }
        }
    }
}

void Vstavkami (int * a, const uint32_t size) {
    for (uint32_t i = 0; i < size; i++){
        uint32_t j = i - 1;
        int x = a[i];
        while (a[j] > x && j >= 0) {
           a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
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