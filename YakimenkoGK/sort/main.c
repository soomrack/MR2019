#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <alg.h>
#include <math.h>

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

unsigned int pivot( int32_t *arr, uint32_t i, uint32_t j){
    int median; // Support element? How to say "opornii"?
    median = arr[(i+j)/2];
    int left =i, right = j; //Counters(Indexes) for left and right side of the array
    while (left <= right){
          // On the left side, all elements are smaller than the median,
          // on the right side - bigger. if not, then swap.
          while (arr[left] < median){ left++;}
          while (arr[right] > median ){ right--;}
          if (left >= right){ break;}
          //swap
          //int temp;
          //temp = arr[left];
          //arr[left] = arr[right];
          //arr[right] = temp;
          arr[left] ^= arr[right];
          arr[right] ^= arr[left];
          arr[left] ^= arr[right];
          left++; right--;
    }
    return right;
}

int getOrderStatistic( int32_t * arr, uint32_t size, uint32_t j ){
    unsigned int left =0, right = size-1;
    while(1){
        unsigned int median;
        median = pivot(arr, left, right);
        if (median == j){          // If index of support element == j,
            return (arr[median]);  // support element is order static
        }
        else if (j < median){      // If index of support element > j,
            right = median;        // order statistic in left side of the array
        }
        else { left = median+1;}   // If index of support element < j,
    }                              // order statistic in right side of the array
}
int main() {
    //int a[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    //int b =3;;
    //unsigned int c =4;
    //int d, e;
    //printf(" %d ", *a);


}