#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Question {
public:
	string question; //Вопрос
	string answer;	 //Правильный ответ
	bool check_answer(string num)
	{
		if (answer == num) return true;
		return false;
	}
	Question() {
		question = "";
		answer = "";

	}
};
extern vector<Question> questions;
extern void List_of_questions();
extern void Quizz_Run();

