#include "Header1.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>


void test(const char Question[], const char trueAnswer[]) {
	char Answer[20];

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("%s\n", Question);
	scanf_s("%s", Answer, 20);
	if (strcmp(Answer, trueAnswer) == 0)
	{
		printf("Верно\n");
	}
	else
		printf("Неверно\n");
}



