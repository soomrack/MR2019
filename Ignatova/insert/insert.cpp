#include <iostream>

void insertSort(int a[], const int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
            a[j] = a[j - 1];
        a[j] = x;
    }
}

int main() {
    int A[10] = { 0, 8, 67, 15, 23, 3, 51, 13, 43, 5 };
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
    cout << '\n';
    insertSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
}
