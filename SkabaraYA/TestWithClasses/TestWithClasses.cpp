#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
int score = 0;

void answer_chek(std::string right_answer, std::string answer) {

	if (answer != right_answer) {
		std::cout << "Неверно" << '\n' << '\n';
	}
	else {
		score++;
		std::cout << "Верно\n" << '\n' << '\n';
	}
}

class Question
{
public:
	std::string question;
	std::string answers;
	std::string right_answer;

	void quest()
	{
		std::string users_answer;
		std::cout << question << '\n';
		std::cout << answers << '\n';
		std::cin >> users_answer;
		answer_chek(right_answer, users_answer);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Question q1{ "В каком городе жил Карлсон?", "1.Москва  2.Москва  3.не Москва  4.Стокгольм", "4" };
	q1.quest();

	Question q2{ "2*3", "1.в  2.6  3.Ярик  4.Ё", "2" };
	q2.quest();

	Question q3{ "Год крещения Руси", "1.2020  2.988  3.0  4.666", "2" };
	q3.quest();

	

	std::cout << '\n' << "Ваш результат:\n";
	std::cout << score << '\n' << '\n';

	system("pause");
	return 0;
}