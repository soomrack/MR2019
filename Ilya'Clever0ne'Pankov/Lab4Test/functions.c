#include "functions.h"

#define swap(a, b)                  \
        {                           \
			int32_t buffer = a;     \
			a = b;                  \
			b = buffer;             \
        }                           \
		
static int32_t partition(int32_t *arr, uint32_t size)
{
	int32_t left = 0;
	int32_t right = size - 1;
	int32_t pivot = arr[(left + right) / 2];
	while(left <= right)
	{
		while(arr[left] < pivot)
			left++;
		while(arr[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	return (left + right) / 2;
}

void sort(int32_t *arr, uint32_t size)
{
	if (size > 1)
	{
		int32_t border = partition(arr, size);
		sort(arr, border + 1);
		sort(arr + (border + 1), size - (border + 1));
	}
}

int32_t getMedian(int32_t *arr, uint32_t size)
{
	if (size % 2 != 0)
		return getOrderStatistic(arr, size, size / 2);
	else
		return 0.5 * getOrderStatistic(arr, size, size / 2 - 1) +
		       0.5 * getOrderStatistic(arr, size, size / 2);
}

int32_t getOrderStatistic(int32_t *arr, uint32_t size, uint32_t j)
{
	if (size > 1)
	{
		int32_t border = partition(arr, size);
		if (j <= border)
			return getOrderStatistic(arr, border + 1, j);
		else
			return getOrderStatistic(arr + (border + 1), size - (border + 1), j - (border + 1));
	}
	else return arr[0];
}

ArrayOf11 sortStruct(ArrayOf11 array)
{
	sort(array.elements, array.size); 
	return array;
}