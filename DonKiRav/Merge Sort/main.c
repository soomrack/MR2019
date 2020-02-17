#include <stdio.h>

void merge_sort(int * arr, int * buff, int left_border, int right_border) {

    if (right_border <= left_border)
        return;
    int middle = left_border + (right_border - left_border) / 2;
    merge_sort(arr, buff, left_border, middle);
    merge_sort(arr, buff, middle + 1, right_border);

    for (int k = left_border; k <= right_border; k++)
        buff[k] = arr[k];

    int i = left_border, j = middle + 1;
    for (int k = left_border; k <= right_border; k++) {
        if (i > middle) {
            arr[k] = buff[j];
            j++;
        } else if (j > right_border) {
            arr[k] = buff[i];
            i++;
        } else if (buff[j] < buff[i]) {
            arr[k] = buff[j];
            j++;
        } else {
            arr[k] = buff[i];
            i++;
        }
    }
}

int main() {
    unsigned int size1 = 6;
    int arr1[6] = {12, 5, 77, 22, 5, 647};
    int buf[size1];
    merge_sort(arr1, buf, 0, size1);

    for (unsigned int i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
