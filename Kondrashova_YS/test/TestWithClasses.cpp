#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int score = 0;

void answer_chek(string right_answer, string answer) {

	if (answer != right_answer) {
		cout << "Неверно" << '\n' << '\n';
	}
	else {
		score++;
		cout << "Верно\n" << '\n' << '\n';
	}
}

class Question
{
public:
	string question;
	string answers;
	string right_answer;

	void quest()
	{
		string users_answer;
		cout << question << '\n';
		cout << answers << '\n';
		cin >> users_answer;
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

	cout << '\n' << "Количество правильных ответов:\n";
	cout << score << '\n' << '\n';

	system("pause");
	return 0;
}