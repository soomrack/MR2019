#include "Header1.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>



void test(const char Question[], const char trueAnswer[]) {
	char Answer[20];

	printf("%s\n", Question);
	scanf_s("%s", Answer, 20);
	if (strcmp(Answer, trueAnswer) == 0)
	{
		printf("Верно\n");
	}
	else
		printf("Неверно\n");
}

void TESTING() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, s = 0;
	char otvet[20];

	char Q[5][30] = {
		{"В каком городе жил Карлсон? "},
		{"2*3"},
		{"Год крещения Руси"},
	};

	char tA[5][30] = {
		{" Стокгольм "},
		{"6"},
		{"988"},
	};

	for (int i = 0; i <= 2; i++) {
		test(Q[i], tA[i]);
	}

}
