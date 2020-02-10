#include "mylib.h"
using namespace std;
int process_answer(string answer, string users_answer)
{
	setlocale(LC_ALL, "Russian");
	if (answer != users_answer)
	{
		cout << "Неверно\n" << endl;
		return 0;
	}
	else
	{
		cout << "Верно\n" << endl;
		return 1;
	}
}

void final_test() {
	setlocale(LC_ALL, "Russian");
	int right = 0;
	int users_answer;
	vector <string> v_question{ "В каком году началась Вторая Мировая война?",
								"Точная дата первого полета человека в космос",
								"В каком году был разработан первый механический аналоговый компьютер?",
								"Как звали основателя компании Apple?",
								"Сколько хромосом у коровы?" };
	vector <string> v_variants{ "1)1940\n2)1939\n3)1917\n4)1941",
								"1)1 января 1977 года\n2)15 июня 1999\n3)12 апреля 1961\n4)23 февраля 1949",
								"1)1888\n2)1927\n3)2018\n4)1934",
								"1)Билл Гейтс\n2)Владимир Путин\n3)Стив Джобс\n4)Илья Ляпцев",
								"1)46\n2)68\n3)38\n4)120" };
	vector <string> v_answer{   "2",
								"3",
								"2",
								"3",
								"4" };
	for (int i = 0; i < v_question.size(); i++) {
		Test curque{ v_question[i], v_variants[i], v_answer[i] };
		right += curque.process_question();
	}
	cout << "Правильных ответов:" << right << endl;
}