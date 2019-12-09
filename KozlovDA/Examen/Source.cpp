#include "lib.h"
#include <iostream>
#include <bitset>

void byteSort()
{
	int count { 0 };
	for (int i = 0; i < 256; i++)
	{
		std::cout << std::bitset<8>(i ^ (i >> 1)) << '\n';
		count++;
	}
	std::cout << "Amount of numbers - " << count << '\n';
}