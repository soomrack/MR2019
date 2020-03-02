#include <iostream>
#include <vector>

using namespace std;

void heapStruct() {
    vector<int> arr;
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
    for (int o = 0; o < 20; o++) {
        cin >> tmp;
        arr.push_back(tmp);
        for (int i = arr.size() / 2 - 1; i >= 0; i--) {
            int largest = i;
            int right = 2 * i + 1;
            int left = 2 * i + 2;
            if(arr.size() % 2 == 0){
                if (arr[largest] < arr[right]) {
                    swap(arr[largest], arr[right]);
                }
                if (i == (arr.size() / 2 - 1)) {
                    continue;
                }
                if (arr[largest] < arr[left]) {
                    swap(arr[largest], arr[left]);
                }
            }else{
                if (arr[largest] < arr[right]) {
                    swap(arr[largest], arr[right]);
                }
                if (arr[largest] < arr[left]) {
                    swap(arr[largest], arr[left]);
                }
            }
        }
    }
    for (int j : arr) {
        cout << j << ' ';
    }
}

int main() {
    heapStruct();

}
