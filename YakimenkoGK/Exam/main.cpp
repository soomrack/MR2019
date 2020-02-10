#include <algorithm>
#include <iostream>
int search(int elem_quantity, int *array){
    static int k =0;
    int result;
    result = array[0];
    for (int i =1; i<elem_quantity; i++){
        result ^= array[i];
    }
    return  result;
}
using namespace std;
int main() {
    int n = 5;
    int input[5] { 1, 8, 1, 2, 2};
    for (int i=0; i<5; i++){
        cout<< input[i] << " ";
    }
    cout << search(n, input);

}