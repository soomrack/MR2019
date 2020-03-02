#include <iostream>

using namespace std;

void BubbleSort( int arr[], const int size);

int main() {


    int arr[10];

    for (int i = 0; i < 10; i++) {
        cin >> arr[i]; // "читаем" элементы в массив
    }

    BubbleSort( arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}


void BubbleSort( int arr[], const int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }

}