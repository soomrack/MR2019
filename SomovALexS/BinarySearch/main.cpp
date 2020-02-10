#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//d32
void binSearch(vector<int> arr, int find_number){
    int left = 0;
    int right = 20;
    int mid;
    bool flag = false;
    while(left <= right && !flag){
        mid = (left + right) / 2;
        if(arr[mid] == find_number){
            flag = true;
        }
        if(arr[mid] > find_number){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    if(flag){
        cout << endl << mid;
    }else{
        cout << endl << "Netu";
    }
}

int main() {
    vector<int> arr;
    for(int i = 0; i < 20; i++){
        arr.push_back(rand() % 15 +1);
        cout << arr[i] << ' ';
    }
    cout << endl;
    sort(arr.begin(), arr.end());
    for(int i : arr){
        cout << i << ' ';
    }
    binSearch(arr, 5);
}
