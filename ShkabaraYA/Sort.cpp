#include <iostream>
#include <utility>

void BubbleSort(int arr[], const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

}


void InsertionSort(int arr[],const int size) {
	int i, key, j;
	for (i = 1; i < size; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	
}

int main()
{
	int a[] = { 1, 4, 2, 5 ,1, 2, 3, 7, 10 };
	BubbleSort(a, 9);
	int b[] = { 1, 4, 2, 5 ,1, 2, 3, 7, 10 };
	InsertionSort(b, 9);

}

