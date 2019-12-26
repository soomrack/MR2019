#include <iostream>
#include <vector>
#include <string>
#include "FinalTestLIB.h"

using namespace std;

vector<Quest> quest;

void Test() 
{
	quest.resize(5);	//.resize Изменяет размер вектора на заданную величину

	quest.at(0).question = "В каком городе жил Карлсон\n1.Стокгольм 2.Москва 3.Смоленск\n\n"; //.at доступ к элементу вектора
	quest.at(0).answer = "1";

	quest.at(1).question = "Сколько будет 2+1?\n1.Один 2.Два 3.Три \n\n";
	quest.at(1).answer = "3";

	quest.at(2).question = "Когда ИММиТ?\n1.Что? 2. ВСЕГДА ИММИТ! 3.Никогда\n\n";
	quest.at(2).answer = "2";

	quest.at(3).question = "Это последний вопрос?\n1.Нет 2.Да 3.Хз\n\n";
	quest.at(3).answer = "1";

	quest.at(4).question = "А это последний вопрос?\n1.Нет 2.No 3.Да\n\n";
	quest.at(4).answer = "3";
}

void Start()
{	
	unsigned int score = 0;

	setlocale(LC_ALL, "Russian");
	
	Test();
	
	for (int i = 0; i < 5; ++i) 
	{
		cout << quest.at(i).question;

		string user_answer;
		cin >> user_answer;

		if (quest.at(i).check_answer(user_answer))
		{
			score++;
			cout << "Верно!\n" << endl;
		}
		else cout << "Неверно!\n" << endl;
	}

	cout << "\nВы набрали " << score << " из 5" << endl;

}

int Result()		//просто демонстрация ради сути метода
{
	GoodNews badNews;
	BadNews& GoodMessage = badNews;
	cout << '\n' << "Результат таков: " << GoodMessage.message() << '\n';

	return 0;
};

/*  Поскольку GoodMessage является ссылкой на родительскую часть объекта GoodNews,
	то, обычно, при обработке GoodMessage.message() вызывался бы BadNews::message(). 
	Тем не менее, поскольку BadNews::message() является виртуальной функцией, 
	то компилятор понимает, что нужно посмотреть, есть ли переопределения этого метода 
	в дочерних классах. И компилятор находит GoodNews::message()					   */