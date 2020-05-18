#include <iostream>
using namespace std;

void heapify(int *arr, int size, int i){
//Фукция, переделывающая дерево в дерево с убывающими элементами
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
//Проверяем, что каждый из элементов потомков меньше родительского
    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;
//Если предок больше, чем потомок, то меняем местами
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr, size, largest);
    }
}

void sort(int *arr, int size){
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for(int i =  size - 1; i >= 0; i--){
        swap(arr[0],arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    sort(array, 10);
    for(int i: array){
        cout << i << ' ';
    }
}
