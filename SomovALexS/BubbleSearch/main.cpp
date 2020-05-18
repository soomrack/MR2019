#include <iostream>
using namespace std;

void bubble_search(int* array, int size){
    int circles = size;
    for(int j = 0; j < circles; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
        size--;
    }
}

int main() {
    int mass[10]  = {2,1,5,9,7,8,6,1,2,10};
    bubble_search(mass,10);
    for(int i: mass){
        cout << i << ' ';
    }
}
