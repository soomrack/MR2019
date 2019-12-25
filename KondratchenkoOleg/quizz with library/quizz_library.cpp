#include <iostream>
#include <vector>
#include <string>
#include "quizz_header.h"
using namespace std;
vector<Question> questions;
const unsigned int	count_of_questions	= 5;	//для статического переопределения памяти для вектора
unsigned int		right_answers		= 0;	//счетчик правильных ответов


void List_of_questions() {
	questions.resize(count_of_questions); //задание размера с учетом количества вопросов
	//Вопросы
	questions.at(0).question	= "Год основания Санкт-Петербургского политехнического университета Петра Великого? \n";
	questions.at(0).answer		= "1899";

	questions.at(1).question	= "Сколько на земле материков начинаются с буквы <А>? \n";
	questions.at(1).answer		= "5";

	questions.at(2).question	= "Самое маленькое натуральное число? \n";
	questions.at(2).answer		= "1";

	questions.at(3).question	= "Какой из этих народов населяет территорию Шри-Ланки? \n•Невары \n•Ведды \n•Бхотия \n•Мяо \n";
	questions.at(3).answer		= "Ведды";

	questions.at(4).question = "Вальс какого композитора стал впоследствии песенкой (Жил был у бабушки серенький козлик...?) \n•Моцарт \n•Шопен \n•Брамс \n•Штраус \n";
	questions.at(4).answer = "Моцарт";
}

void Quizz_Run()
{
	system("chcp 1251 > null");
	List_of_questions();	//подключение вопросов
	for (unsigned int i = 0; i < count_of_questions; ++i) {
		cout << questions.at(i).question;
		string writing_ans;
		cin >> writing_ans;

		if (questions.at(i).check_answer(writing_ans)) {
			right_answers++;
			cout << "\nОтвет верный. +1 балл \nСледующий вопрос:\n" << endl;
		}
		else
			cout << "\nОтвет неверный.\nСледующий вопрос:\n" << endl;
	}

	if (right_answers > 3)
		cout << "\nПоздравляем, тест засчитан! Количество набранных баллов: " << right_answers << endl;
	else
		cout << "\nК сожалению, тест не засчитан. Количество набранных баллов: " << right_answers << endl;

	system("pause>>null");
}
