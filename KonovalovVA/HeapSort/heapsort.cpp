#include <iostream>

using namespace std;


void heapify(int arr[], const int size, int index) {
    int largest = index;

    int left_element = 2 * index + 1;
    int right_element = 2 * index + 2;

    if (left_element < size && arr[left_element] > arr[largest])
        largest = left_element;

    if (right_element < size && arr[right_element] > arr[largest])
        largest = right_element;

    if (largest != index) {
        swap(arr[index], arr[largest]);

        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], const int size) {
    for (int index = size / 2 - 1; index >= 0; index--)
        heapify(arr, size, index);

    for (int index = size - 1; index >= 0; index--) {
        swap(arr[0], arr[index]);

        heapify(arr, index, 0);
    }
}


int main() {

    int arr[7];

    for (int i = 0; i < 7; i++) {
        cin >> arr[i]; // считываем элементы
    }

    heapSort(arr, 7);

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " "; // выводим элементы
    }
}