#include "Lib_test_with_vector.h" 
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	std::vector <std::string> question;
	question.push_back("Введите номер буквы в");
	question.push_back("Введите номер буквы Г");
	question.push_back("Введите номер буквы е");

	std::vector <std::string> answers;
	answers.push_back("1.в  2.г  3.е  4.Ё");
	answers.push_back("1.в  2.Г  3.е  4.Ё");
	answers.push_back("1.В  2.Г  3.е  4.Ё");

	std::vector <std::string> right_answer;
	right_answer.push_back("1");
	right_answer.push_back("2");
	right_answer.push_back("3");

	ba_dom_tss(3);
	std::cout << "Тест на психологический возраст\n" << '\n';
	Sleep(1000);

	for (int i = 0; i < question.size(); i++)
	{
		Question current_question{ question[i], answers[i], right_answer[i] };
		current_question.processing_of_question();
	}

	std::cout << "А теперь перейдем к самому главному вопросу.\n";
	Sleep(1000);
	std::cout << "Сколько вам лет?\n";
	std::string real_age{};
	std::cin >> real_age;

	std::cout << '\n' << "Ваш психологический возраст:\n";
	ba_dom_tss(5);
	std::cout << rand() % 100 << '\n' << '\n';

	system("pause");
	return 0;
}