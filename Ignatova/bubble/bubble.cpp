#include <iostream>
#include <stdio.h>

using namespace std;

void bubbleSort(int a[], const int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
        }
    }
}

int main() {
    int A[10] = { 0, 8, 67, 15, 23, 3, 51, 13, 43, 5 };
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
    cout << '\n';
    bubbleSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
}
