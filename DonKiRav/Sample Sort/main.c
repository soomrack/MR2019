#include <stdio.h>
#include <stdint.h>

void bubbleSort (int * a, const uint32_t size) {
    int x;
    for (uint32_t i = 0; i < size; i++) {
        for (uint32_t j = size - 1; j > i; j--) {
            if (a[j] > a[j-1]) {
                x = a[j-1];
                a[j-1] = a[j];
                a[j] = x;
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

    Vstavkami(arr1, size1);

    for (uint32_t i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
