#include <iostream>
#include <stdint.h>
#include <cstdlib>
using namespace std;


int32_t GetSize()
{
	int64_t size;
	cin >> size;
	return size;
}
int32_t Sort(int32_t* ArrayToSort, int32_t size)
{
	int32_t keeperMax1 = ArrayToSort[0];
	int32_t keeperMax2 = ArrayToSort[0];
	uint8_t elCounter = 0;

	if (size == 1) keeperMax2 = ArrayToSort[0];

	for (elCounter = 1; elCounter < size; elCounter++)
	{
		if (ArrayToSort[elCounter] > ArrayToSort[elCounter - 1] && ArrayToSort[elCounter] > keeperMax1)
		{
			keeperMax2 = keeperMax1;
			keeperMax1 = ArrayToSort[elCounter];
		}
		else if (ArrayToSort[elCounter] < keeperMax1 && ArrayToSort[elCounter] > keeperMax2)
		{
			keeperMax2 = ArrayToSort[elCounter];
		}
	}
	return keeperMax2;
}
void CreatingTheArray(int32_t* ArrayToSort, int32_t size)
{
	for (uint8_t counter = 0; counter < size; counter++)
	{
		ArrayToSort[counter] = rand() % INT32_MAX;
	}

	for (uint8_t counter = 0; counter < size; counter++)
	{
		cout << ArrayToSort[counter] << endl;
	}
	return;
}
int32_t ArrayToSort[] = { 0 };

int main()
{
	cout << "Hello!" << endl << "Please, write the number of elements:";
	int32_t size = GetSize();
	cout << "Thanks! So, your array:" << endl;
	CreatingTheArray(ArrayToSort, size);
	int32_t SecondElement = Sort(ArrayToSort, size);
	cout << "The second largest element of the array: " << SecondElement << endl << "Goodbye!" << endl << endl;
	return 0;
}
