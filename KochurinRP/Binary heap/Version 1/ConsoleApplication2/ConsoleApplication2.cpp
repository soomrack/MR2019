#include "pch.h"
#include <iostream>
#define LEN 10

void replacment(int* mass, int a, int b)
{
	int flag = 1;
	while (flag)
	{
		if (mass[a] < mass[b])
		{
			int temp = mass[a];
			mass[a] = mass[b];
			mass[b] = temp;
			b = a;
			a = (a-1)/2;
		}
		else
		{
			flag = 0;
		}
	}
}

void sort(int* mass, int zero, int length)
{
	if ((zero * 2 + 2) <= (length))
	{
		int first = zero * 2 + 1;
		int second = zero * 2 + 2;
		replacment(mass, zero, first);
		replacment(mass, zero, second);
		sort(mass, first, length);
		sort(mass, second, length);
	}
	else
	{
		if ((zero * 2 + 1) <= (length))
		{
			int first = zero * 2 + 1;
			sort(mass, first, length);
			replacment(mass, zero, first);
		}
	}
}

void print(int* mass, int length)
{
	int level = 0;
	int flag = 1;
	int amount = 0;
	while (flag)
	{
		printf("%2d: ", level);
		int quantity = 1;
		for (int i = 0; i < level; i++)
		{
			quantity *= 2;
		}
		if ((amount + quantity) < length)
		{
			for (int i = amount; i < (amount + quantity); i++)
			{
				printf("%3d ", mass[i]);
			}
			printf("\n");
			amount += quantity;
			level++;
		}
		else
		{
			for (int i = amount; i < length; i++)
			{
				printf("%3d ", mass[i]);
			}
			flag = 0;
		}
	}
}

int main()
{
	int mass[LEN] = {51, -7, 5, 36, 74, 68, 88, 4, 9, -88};
	for (int i = 0; i < LEN; i++)
	{
		printf("%3d  ", mass[i]);
	}
	printf("\n");
	sort(&mass[0], 0, LEN-1);
	for (int i = 0; i < LEN; i++)
	{
		printf("%3d  ", mass[i]);
	}
	printf("\n");
	print(mass, LEN);
	return 0;
}
