#include <iostream>

using namespace std;
void BinaryHeap(int h[], int index, const int size);
void PrintArr(int arr[], const int size);
int main() {
    int arr[10] = {0, 1, 5, 3, 6, 7, 10, 67, 9, 8};
    BinaryHeap(arr, 10, 0);
    PrintArr(arr, 10);

}

void BinaryHeap(int arr[], const int size, int i){
    int largest = i;
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;


        if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void PrintArr(int arr[], const int size){
    int index = 0;
    int k = 1;
    while (index < 10) {
        while ((index < k) && (index < 10)) {
            cout << arr[index] << "  ";
            index++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}