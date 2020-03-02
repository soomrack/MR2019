#include <iostream>

using namespace std;

void Sort(int* arr, const int size){
    int counter = 0;
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0 && arr[j - 1] > arr[j]; j--){
            counter++;
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
    cout<< counter <<endl;
}

int main (){
    int arr[10];

    for (int i = 0; i < 10; i++) {
        cin >> arr[i]; // "читаем" элементы в массив
    }

    Sort( arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}
