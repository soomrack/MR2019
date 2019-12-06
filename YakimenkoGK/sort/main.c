#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void sort_new( int32_t * arr, uint32_t size )
{
    //MERGE
    int result_arr[size];
    unsigned int median = size/2; //Imaginary division of an array into two subarrays
    //if (size % 2 == 1) { median++; } //If it is not divisible by 2
    int bloc = 1; //Quantity of sorted elements from each subarray to sort among themselves
    int step; //Step is step)

    while (bloc < size){ //Because the block is already sorted
          unsigned int i = 0, j = median; // Indexes of first and second subarrays
          unsigned int r = 0; // Index of result_arr
          step = bloc; // Because bloc is already sorted

          while (step <= median){ // If the step is greater than the median, then array already sorted

                while (i < step && j < size && j < median + step){ // Fill the result_arr with the smaller of
                      if (arr[i] < arr[j]){                        // the two viewed blocks from each subarray
                          result_arr[r] = arr[i];
                          i++; r++;
                      }
                      else {
                          result_arr[r] = arr[j];
                          j++; r++;
                      }
                }

                while (i < step){ // If the second subarray ended earlier
                      result_arr[r] = arr[i];
                      i++; r++;
                }

                while (j < median + step && j < size){ // If the first subarray ended earlier
                      result_arr[r] = arr[j];
                      j++; r++;
                }
                step += bloc; // Update step
          }

          bloc *= 2; //Update bloc
          memcpy(arr, result_arr, sizeof(int)*size); // Move elements from the final/intermediate
                                                           // array to the original array
    }
}

void merge(int *a, int n)
{
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1) {mid++;}
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int *c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
                // заполняем следующий элемент формируемой последовательности
                // меньшим из двух просматриваемых
                if (a[i] < a[j])
                {
                    c[k] = a[i];
                    i++; k++;
                }
                else {
                    c[k] = a[j];
                    j++; k++;
                }
            }
            while (i < step )
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = a[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j<n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = a[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i<n; i++)
            a[i] = c[i];
    }
}

void mergeSortTRUE(int *a, int n)
{
    int step = 1;  // шаг разбиения последовательности
    int *temp = (int*)malloc(n * sizeof(temp)); // дополнительный массив
    while (step < n)  // пока шаг меньше длины массива
    {
        int index = 0;    // индекс результирующего массива
        int l = 0;      // левая граница участка
        int m = l + step;  // середина участка
        int r = l + step * 2;  // правая граница участка
        while (l<n){
            //m = m < n ? m : n;
            if (m>=n){ m=n;}
            // сортируемый участок не выходит за границы последовательности
            if (r>=n){ r=n;}
            //r = r < n ? r : n;

            int i1 = l, i2 = m; // индексы сравниваемых элементов
            for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
            {
                if (a[i1] < a[i2]) { temp[index] = a[i1]; index++; i1++;} // заполняем участок результирующей последовательности
                else { temp[index++] = a[i2++]; }
            }
            // Или i1 < m или i2 < r - только один из операторов while может выполниться
            while (i1 < m) temp[index++] = a[i1++]; // заносим оставшиеся элементы сортируемых участков
            while (i2 < r) temp[index++] = a[i2++]; // в результирующий массив
            l += step * 2; // перемещаемся на следующий сортируемый участок
            m += step * 2;
            r += step * 2;
        }  // пока левая граница сортируемого участка - в пределах последоватльности
        for (int i = 0; i < n; i++) // переносим сформированный массив обратно в a
            a[i] = temp[i];
        step *= 2; // увеличиваем в 2 раза шаг разбиения
    }
}

void sort( int32_t * arr, uint32_t size )
{
    //GNOME
    int i = 1, j = 2; //initial values for counters
    while (i < size){
        if (arr[i] > arr[i-1]){
            i = j;
            j++;
        }
        else {
            arr[i] ^= arr [i-1];//
            arr[i-1] ^= arr[i];// swap
            arr[i] ^= arr[i-1];//
            i--;
            if (i == 0){
                i = j;
                j++;
            }
        }
    }
}

int32_t getMedian( int32_t * arr, uint32_t size )
{
    sort(arr, size);
    return arr[size/2];
}

int32_t getOrderStatistic( int32_t * arr, uint32_t size, uint32_t j )
{
    int array [size]; //dont touch arr
    memcpy(array, arr, sizeof(int)*size);
    sort(array, size);
    return array[j];
}

void mergesort( int32_t * arr, uint32_t size){
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
int main() {
    int a[8] = {6, 2, 3, 1, 20, 4, 0, 50};

    mergesort(a, 8);

    for (int i =0; i<8; i++){
        printf(" %d ", a[i]);
    }
    return 0;
}