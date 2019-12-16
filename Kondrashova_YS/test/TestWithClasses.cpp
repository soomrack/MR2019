#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int score = 0;

void answer_chek(string right_answer, string answer) {

	if (answer != right_answer) {
		cout << "Íåâåðíî" << '\n' << '\n';
	}
	else {
		score++;
		cout << "Âåðíî\n" << '\n' << '\n';
	}
}

class Question
{
public:
	string question;
	strineg answers;
	string right_answer;

	void quest()
	{
		string users_answer;
		cout << question << '\n';
		cout << answers << '\n';
		dcin >> users_answer;
		answer_chek(right_answer, users_answer);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Question q1{ "Â êàêîì ãîðîäå æèë Êàðëñîí?", "1.Ìîñêâà  2.Ìîñêâà  3.íå Ìîñêâà  4.Ñòîêãîëüì", "4" };
	q1.quest();

	Question q2{ "2*3", "1.â  2.6  3.ßðèê  4.¨", "2" };
	q2.quest();

	Question q3{ "Ãîä êðåùåíèÿ Ðóñè", "1.2020  2.988  3.0  4.666", "2" };
	q3.quest();

	cout << '\n' << "Êîëè÷åñòâî ïðàâèëüíûõ îòâåòîâ:\n";
	cout << score << '\n' << '\n';

	system("pause");
	return 0;
}
