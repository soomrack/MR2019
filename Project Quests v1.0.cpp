#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Question {
public:
	string question; //Вопрос
	string answer; //Правильный ответ
	bool check_answer(string num)
	{
		if (answer == num) return true;
		return false;
	}
};

std::vector<Question> questions;
unsigned int right_answers = 0;
unsigned int count_of_questions = 3; //для статического переопределения памяти для вектора


void Quest() {
	//Вопросы
	questions[0].question = "Год основания Санкт-Петербургского политехнического университета Петра Великого? \n";
	questions[0].answer = "1899";

	questions[1].question = "Сколько на земле материков начинаются с буквы <А>? \n";
	questions[1].answer = "5";

	questions[2].question = "Самое маленькое натуральное число? \n";
	questions[2].answer = "1";
}

int main()
{
	system("chcp 1251 > null");
	questions.resize(count_of_questions);
	Quest();
	for (unsigned int i = 0; i < count_of_questions; ++i) {
		cout << questions[i].question;

		string writing_ans;
		cin >> writing_ans;

		if (questions[i].check_answer(writing_ans)) {
			right_answers++;
			std::cout << "Ответ верный. +1 балл" << endl;
		}
		else
		std::cout << "Ответ неверный." << right_answers << endl;
	}


	if (right_answers > 2) 
	std::cout << "\nПоздравляем, тест засчитан! Количество набранных баллов: " << right_answers << endl;
	else 
	std::cout << "\nК сожалению, тест не засчитан. Количество набранных баллов: " << right_answers << endl;

	system("pause>>null");
}