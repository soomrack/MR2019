#include "mylib.h"

class Test_with_class
{
	public:
		string question;
		string variants;
		string answer;

		int process_question()
		{
			string users_answer;
			cout << question << endl;
			cout << variants << endl;
			cin >> users_answer;
			int right = process_answer(answer, users_answer);
			return right;
		}
};

int main()
{
	int right = 0;
	setlocale(LC_ALL, "Russian");
	Test_with_class q1{ "В каком году началась Вторая Мировая война?", 
						"1)1940  2)1939  3)1917  4)1941", 
						"2" };
	right += q1.process_question();
	Test_with_class q2{ "Точная дата первого полета человека в космос", 
						"1)1 января 1977 года  2)15 июня 1999  3)12 апреля 1961  4)23 февраля 1949", 
						"3" };
	right += q2.process_question();
	Test_with_class q3{ "В каком году был разработан первый механический аналоговый компьютер?", 
						"1)1888  2)1927  3)2018  4)1934", 
						"2" };
	right += q3.process_question();
	Test_with_class q4{ "Как звали основателя компании Apple?", 
						"1)Билл Гейтс  2)Владимир Путин  3)Стив Джобс  4)Илья Ляпцев", 
						"3" };
	right += q4.process_question();
	Test_with_class q5{ "Сколько хромосом у коровы?", 
						"1)46  2)68  3)38  4)120", 
						"4" };
	right += q5.process_question();
	cout << "правильных ответов: " << right << endl;
	system("pause");
	return 0;
}

