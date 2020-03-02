#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <cstdlib>

int comp(const void *a, const void *b){
    return (*(int*)b-*(int*)a);
}
void SiftUP(int i, int *heap){
    while (heap[i]<heap[(i-1)/2]){
        std::swap(heap[i], heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
class Heap {
    static const int SIZE = 100; // максимальный размер кучи
    int *h;         // указатель на массив кучи
    int HeapSize; // размер кучи
public:
    Heap();  // конструктор кучи
    void addelem(int);  // добавление элемента кучи
    void outHeap();  // вывод элементов кучи в форме кучи
    void out();  // вывод элементов кучи в форме массива
    int getmax();  // удаление вершины (максимального элемента)
    void heapify(int);  // упорядочение кучи
};
//Конструктор кучи
Heap :: Heap() {
    h = new int[SIZE];
    HeapSize = 0;
}
//Добавление элемента кучи
void Heap :: addelem(int n) {
    int i, parent;
    i = HeapSize;
    h[i] = n;
    parent = (i-1)/2;
    while(parent >= 0 && i > 0)  {
        if(h[i] > h[parent]) {
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i-1)/2;
    }
    HeapSize++;
}
//Вывод элементов в форме кучи
void Heap:: outHeap(void) {
    int i = 0;
    int k = 1;
    while(i < HeapSize) {
        while((i < k) && (i < HeapSize)) {
           std:: cout << h[i] << " ";
            i++;
        }
        std::cout << std::endl;
        k = k * 2 + 1;
    }
}
//Вывод кучи в форме массива
void Heap:: out(void) {
    for(int i=0; i< HeapSize; i++) {
        std::cout << h[i] << " "; }
    std::cout << std::endl;
}
//Упорядочивание кучи
void Heap:: heapify(int i) {
    int left, right;
    int temp;
    left = 2*i+1;
    right = 2*i+2;
    if(left < HeapSize) {
        if(h[i] < h[left]) {
            temp = h[i];
            h[i] = h[left];
            h[left] = temp;
            heapify(left);
        }
    }
    if(right < HeapSize) {
        if(h[i] < h[right]) {
            temp = h[i];
            h[i] = h[right];
            h[right] = temp;
            heapify(right);
        }
    }
}
using namespace std;
int main() {
    system("chcp 1251");
    system("cls");
    Heap a;
    int elem;
    for(int i =0; i<16; i++){
        elem = rand()%20;
        cout << elem << " ";
        a.addelem(elem);
    }
    a.outHeap();
    a.out();
    return 0;
}