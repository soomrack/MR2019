#include <iostream>

using namespace std;
void BinaryHeap(int h[], int index, const int size);
void PrintArr(int arr[], const int size);
int main() {
    int arr[10] = {0, 1, 5, 3, 6, 7, 10, 67, 9, 8};
    BinaryHeap(arr, 10, 0);
    PrintArr(arr, 10);

}

void BinaryHeap (int arr[], int index, const int size){
    int left, right;
    int temp;
    left = 2*index+1;
    right = 2*index+2;
    if((arr[index] < arr[left]) && (left < size))  {
        temp = arr[index];
        arr[index] = arr[left];
        arr[left] = temp;
        BinaryHeap(arr, left, size);
    }
    if((arr[index] < arr[right]) && (right < size)) {
        temp = arr[index];
        arr[index] = arr[right];
        arr[right] = temp;
        BinaryHeap(arr, right, size);
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