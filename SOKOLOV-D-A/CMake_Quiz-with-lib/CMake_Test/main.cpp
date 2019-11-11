#include "CMake_Test_library.h"
#include "stdint.h"
#include "stdlib.h"
#include <iostream>
#define COUNT_OF_QUESTIONS 4    // количество вопросов
int main()
{
	system("chcp 1251 > null");
	questions.resize(COUNT_OF_QUESTIONS);
	addQuestion("Год основания Санкт-Петербургского политехнического университета Петра Великого? \n", "1899");
	addQuestion("Сколько на земле материков начинаются с буквы <А>? \n", "5");
	addQuestion("Самое маленькое натуральное число? \n", "1");
	addQuestion("Сколько букв в русском алфавите? \n", "33");
	initTest(COUNT_OF_QUESTIONS);
	system("pause>>null");
	return 0;
}