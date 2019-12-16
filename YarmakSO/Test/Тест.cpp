#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int score = 0;

void answer_check(string right_answer, string answer) 
{
	if (answer != right_answer) 
	{
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
		cout << answers << '\n' << '\n';
		cin >> users_answer;
		answer_check(right_answer, users_answer);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Question q1{ "Какое самое большое млекопитающее на Земле?", "1.Синий кит  2.Слон  3.Жираф  4.Олень 5. Дельфин", "1" };
	q1.quest();

	Question q2{ "В каком году Гагарин побывал в космосе?", "1.1951  2.1961  3.1971  4.1981 5. 1991", "2" };
	q2.quest();

	Question q3{ "Какой самый распространенный химический элемент во Вселенной?", "1.Кремний  2.Гелий  3.Водород  4.Кислород 5.Азот", "3" };
	q3.quest();

	Question q4{ "Какая планета находится ближе всех к Солнцу?", "1.Юпитер  2.Марс  3.Земля  4.Венера 5.Меркурий", "5" };
	q4.quest();

	Question q5{ "Кто был изобретателем телефона?", "1.Белл  2.Маркс  3.Тесла  4.Ньютон 5.Эдисон", "1" };
	q5.quest();

	cout << '\n' << "Ваш результат:\n";
	cout << score<<" из 5" <<'\n' << '\n';

	system("pause");
	return 0;
}