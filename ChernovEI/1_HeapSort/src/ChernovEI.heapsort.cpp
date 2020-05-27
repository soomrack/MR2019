#include <iostream>

using namespace std;


void heapify(int arr[], int length, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, length, largest);
    }
}

void heapSort(int arr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, length, i);
    }

    for (int i = length - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int length) {
    cout << "[" << arr[0];
    for (int i = 1; i < length; ++i) {
        cout << ", " << arr[i];
    }
    cout << "]" << endl;
}

int main() {
    const int N = 6;
    int a[N] = {12, 11, 13, 5, 6, 7};

    heapSort(a, N);

    cout << "Sorted array: \n";
    printArray(a, N);
}