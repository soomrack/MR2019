// NaEkzamen.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdint.h>

int32_t getFibonacci(int n)
{

	static int maxDeep = -1;
	static int currentDeep = -1;

	currentDeep++;
	if (currentDeep > maxDeep) {
		maxDeep = currentDeep;
	}

	int result = 1;
	if (n != 1 && n != 2) {
		result = getFibonacci(n - 1) + getFibonacci(n - 2);
	}

	currentDeep--;

	if (currentDeep == -1) {
		printf_s("%i\n", maxDeep);
		maxDeep = 0;
		currentDeep = -1;
	}

	return result;
}


int main()
{
	int a = 7;
	a = getFibonacci(a);
	printf_s("%i \n", a);
	a = 5;
	a = getFibonacci(a);
	printf_s("%i \n", a);

}
