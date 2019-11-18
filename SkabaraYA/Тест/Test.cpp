
#include "Header1.h"
#include <locale.h>
#include <Windows.h>
#include <conio.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, s = 0;
	char otvet[20];

	char Q[5][30] = {
		{"В каком городе жил Карлсон?"},
		{"2*3"},
		{"Год крещения Руси"},
	};

	char tA[5][30] = {
		{"Стокгольм"},
		{"6"},
		{"988"},
	};

	for (int i = 0; i <=3; i++) {
		test(Q[i], tA[i]);
	}

}
