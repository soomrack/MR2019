#include <iostream>
#include <ctime>
#include <windows.h>
#include "Lib_classes.h"

class Question
{
public:
	std::string question;
	std::string answers;
	std::string right_answer;

	void processing_of_question()
	{
		std::string users_answer;
		std::cout << question << '\n';
		std::cout << answers << '\n';
		std::cin >> users_answer;
		processing_of_answer(right_answer, users_answer);
	}
};

int main() 
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	std::string real_age;

	ba_dom_tss(3);
	std::cout << "Тест на психологический возраст\n" << '\n';
	Sleep(1000);

	Question question_1{ "Введите номер буквы в", "1.в  2.г  3.е  4.Ё", "1" };
	question_1.processing_of_question();

	Question question_2{ "Введите номер буквы Г", "1.в  2.Г  3.е  4.Ё", "2" };
	question_2.processing_of_question();

	Question question_3{ "Введите номер буквы е", "1.В  2.Г  3.е  4.Ё", "3" };
	question_3.processing_of_question();

	std::cout << "А теперь перейдем к самому главному вопросу.\n";
	Sleep(1000);
	std::cout << "Сколько вам лет?\n";
	std::cin >> real_age;

	std::cout << '\n' << "Ваш психологический возраст:\n";
	ba_dom_tss(5);
	std::cout << rand() % 100 << '\n' << '\n';
												
	system ("pause");
	return 0;
}