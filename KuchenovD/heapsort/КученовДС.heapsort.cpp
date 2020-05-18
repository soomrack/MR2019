#include <iostream>
using namespace std;

void print_array(int arr[], int arr_size);
void heap_sort(int arr[], int arr_size);
void heapify(int arr[], int arr_size, int i);

int main() 
{
  setlocale(LC_ALL, "Russian");

  int arr[] = { 7, 345, 15, -2, 86, 1, 57, 90 };
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  cout << "Введенный массив: \n";
  print_array(arr, arr_size);
  heap_sort(arr, arr_size);
  cout << "Массив после сортировки: \n";
  print_array(arr, arr_size);
}


void heapify(int arr[], int arr_size, int i)
{
  int biggest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < arr_size && arr[left] > arr[biggest])
  {
    biggest = left;
  }

  if (right < arr_size && arr[right] > arr[biggest])
  {
    biggest = right;
  }

  if (biggest != i) 
  {
    swap(arr[i], arr[biggest]);
    heapify(arr, arr_size, biggest);
  }
}

void heap_sort(int arr[], int arr_size)
{
  for (int i = arr_size / 2 - 1; i >= 0; i--)
  {
    heapify(arr, arr_size, i);
  }

  for (int i = arr_size - 1; i >= 0; i--) 
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void print_array(int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n\n";
}
