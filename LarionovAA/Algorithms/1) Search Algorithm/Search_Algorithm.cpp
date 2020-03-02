
#include <iostream>
#include <cstdlib>

int search(int* array, int firstIndex, int lastIndex, int number)
{
	static int countCall = 0;
	countCall++;
	if (lastIndex == firstIndex)
	{
		if (array[firstIndex] == number)
		{
			std::cout << std::endl <<"- Call count " << countCall;
			countCall = 0;
			return firstIndex;
		}
		else
		{
			std::cout << std::endl << "- Call count " << countCall;
			countCall = 0;
			return -1;
		}
	}

	int middle = (lastIndex - firstIndex) / 2 + firstIndex;

	if (array[middle] < number)
	{
		return search(array, middle + 1, lastIndex, number);
	}
	else
	{
		return search(array, firstIndex, middle, number);
	}
}

int compare(const void* searchkey, const void* element) // for bsearch
{
	return (*(int*)searchkey - *(int*)element);
}

int main()
{
	int arrayOfNumberOne[5] = { 0, 1, 2, 3, 4 };
	int arrayOfNumberTwo[6] = { 77, 88, 99, 111, 222, 333 };
	int arrayOfNumberThree[7] = { 0, 1, 2, 3, 4, 5, 6 };
	int arrayOfNumberFour[9] = { 23, 36, 18, 44, 7, 44, 88, 113, 55 };

	int result = 0;

	result = search(arrayOfNumberOne, 0, 4, 3);
	std::cout << std::endl << "Desired number's index is " << result << std::endl; //right
	result = search(arrayOfNumberTwo, 0, 5, 333);
	std::cout << std::endl << "Desired number's index is " << result << std::endl; //right
	result = search(arrayOfNumberThree, 0, 6, 1);
	std::cout << std::endl << "Desired number's index is " << result << std::endl; //right
	result = search(arrayOfNumberFour, 0, 8, 18);
	std::cout << std::endl << "Desired number's index is " << result << std::endl; //false, because unsorted array


	//Standart function - bsearch
	//void * bsearch( const void * searchkey, const void * baseptr, size_t number, size_t size, int (* funccompar) (const void *, const void *) )
	int key = 3;

	std::cout << std::endl << "____________" << std::endl;

	int* ptr = (int*)bsearch(&key, arrayOfNumberOne, 5, sizeof(int), compare);
	if (ptr != NULL)
	{
		std::cout << std::endl << "This array has a desired number" << std::endl;
	}
	else
	{
		std::cout << std::endl << "This array has't a desired number" << std::endl;
	}

	return 0;
}
