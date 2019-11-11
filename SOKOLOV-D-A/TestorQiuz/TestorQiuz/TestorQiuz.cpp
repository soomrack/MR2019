#include <stdio.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <string.h>


using namespace std;

struct Test
{
	unsigned short point = 0;// Баллы за тест
	char question[200];// Вопрос
	//unsigned short A; //nomer otveta
	char ans1[200];//Ответ 1
	//unsigned short B;//nomer otveta
	char ans2[200];//Ответ 2
	string userAns;//Ответ пользователя 
	bool check;// Верный/неверный
}MyTest;
Test initQuiz(const char* question, const char* answer1, const char* answer2);
Test startQuiz(const char* rightans);

int main()
{
	system("chcp 1251 >> null");
	
	while (1) {
		initQuiz("Год основания СпБ", "1713", "1703");
		startQuiz("1703");
		if (MyTest.userAns == "выйти") break;
		initQuiz("Сколько этажей в ГЗ?", "4", "3");
		startQuiz("3");
		if (MyTest.userAns == "выйти") break;
		initQuiz("Сколько лет Политеху?", "121", "120");
		startQuiz("120");
		if (MyTest.userAns == "выйти") break;
	}
	cout << " \nКоличество баллов : " << MyTest.point << endl;
	system("pause");
	return 0;
}


Test initQuiz(const char* question, const char* answer1, const char* answer2){
	strcpy_s(MyTest.question, question);
	strcpy_s(MyTest.ans1, answer1);
	strcpy_s(MyTest.ans2, answer2);
	return Test();
}

Test startQuiz(const char* rightans)
{

	cout << "Вопрос : " << MyTest.question<< "\nВарианты ответа: \n";
	cout << MyTest.ans1 << endl;
	cout << MyTest.ans2 << endl;
	cout << "Введите ответ или напишите <выйти>\n" ;
	cin >> MyTest.userAns;
	if (MyTest.userAns == rightans) {
		MyTest.check = true;
		MyTest.point += 1;
		cout << "Верно!" << "Количество баллов : " << MyTest.point << endl;
	}
	if ((MyTest.userAns != rightans) && (MyTest.userAns != "выйти")) {
		cout << "Неверно! " << endl;
	}
	return Test();
}
