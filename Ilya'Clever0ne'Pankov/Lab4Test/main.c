#include "functions.h"

int main(void)
{
	int32_t array1[10] = {9, 6, 3, 7, 0, 5, 8, 1, 4, 2};
	int32_t array2[13] = {85, 2, 5, 151, 139, 1, 4, 97, 9, 70, 92, 7, 135}; 
	
	sort(array1, 10);
	int32_t median = getMedian(array2, 13);
	
	ArrayOf11 array = {
	.size = 11,
	.elements = {3, -4, -1, 5, -2, -3, -5, 0, 2, 4, 1}
	};
	
	//array = sortStruct(array);
	
    return 0;
}
