
#include "cstdint"
#include <iostream>
void sort( int32_t * arr, uint32_t size){
    int result_arr[size]; // Additional(result) array
    int step = 1; // The step of partitioning the array

    while (step < size){ // If step == size, the array is already sorted
        int r = 0; // Index of result_arr
        int left_border = 0; // Left border of the sortable bloc
        int median = left_border + step; // Median of the sortable bloc
        int right_border = left_border + step*2; // Right border of the sortable bloc

        while (left_border < size){ // If left_border == size, array is ended
            if (median >= size) { median = size; }              // Bloc dont overflow
            if (right_border >= size) { right_border = size; }  // __________________
            int i1 = left_border, i2 = median; // The indexes of the compared elements
            //START "MERGE"
            while (i1 < median && i2 < right_border){ // Compare elements and
                if (arr[i1] < arr[i2]){             // min element add to result_arr
                    result_arr[r] = arr[i1];
                    r++; i1++;
                }
                else {
                    result_arr[r] = arr[i2];
                    r++; i2++;
                }
            }

            while (i1 < median){           // Add the remaining elements
                result_arr[r] = arr[i1]; // to the array after the comparison
                r++; i1++;               // (only one "while" can be run)
            }

            while (i2 < right_border){     // Add the remaining elements
                result_arr[r] = arr[i2]; // to the array after the comparison
                r++; i2++;               // (only one "while" can be run)
            }

            left_border += step*2;  //
            median += step*2;       // Update borders to move to the next bloc
            right_border += step*2; //
        }
        memcpy(arr,result_arr, sizeof(int)*size); // Update original array
        step *= 2; // Update step
    }

}

int search ( int n, uint32_t left, uint32_t right, int *array){
    uint32_t median = (left + right)/2;
    if (array[median] == n){ return median;}
    else if (array[median] < n){
        left = median;
        search(n, left, right, array);
    }
    else if (array[median] > n){
        right = median;
        search(n, left, right, array);
    }
}

int searchAfterSort( int n, uint32_t left, uint32_t right, int *array){
    sort(array, right+1);
    search(n,left,right,array);
}

using namespace std;
int main(){

    int arr[8]{ 5, 8, 12, 20, 22, 23, 89, 100};
    int n;
    cin >> n;
    cout << search(n,0,7,arr);

}
