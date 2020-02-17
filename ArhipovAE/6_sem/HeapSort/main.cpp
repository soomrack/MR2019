#include <iostream>

using namespace std;

void BinaryHeap(int arr[], const int size, int index){
    int largest = index;

    int left_element = 2 * index + 1;
    int right_element = 2 * index + 2;

    if (left_element < size && arr[left_element] > arr[largest])
        largest = left_element;

    if (right_element < size && arr[right_element] > arr[largest])
        largest = right_element;

    if (largest != index){
        swap(arr[index], arr[largest]);

        BinaryHeap(arr, size, largest);
    }
}

void heapSort(int arr[], const int size){
    for (int i = size / 2 - 1; i >= 0; i--)
        BinaryHeap(arr, size, i);

    for (int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);

        BinaryHeap(arr, i, 0);
    }
}


int main(){

    int arr[10];

    for (int i = 0; i < 10; i++) {
        cin >> arr[i]; // "читаем" элементы в массив
    }

    heapSort(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}