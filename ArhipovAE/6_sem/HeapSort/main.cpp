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
    for (int index = size / 2 - 1; index >= 0; index--)
        BinaryHeap(arr, size, index);

    for (int index = size - 1; index >= 0; index--){
        swap(arr[0], arr[index]);

        BinaryHeap(arr, index, 0);
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