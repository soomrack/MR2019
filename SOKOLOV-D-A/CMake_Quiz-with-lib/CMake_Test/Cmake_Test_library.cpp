#include "CMake_Test_library.h"
std::vector<List> questions;
size_t size = 0;
void addQuestion(std::string question, std::string answer)
{
	
	questions[size].question = question;
	questions[size].answer = answer;
	size++;

}
void initTest(size_t count_of_questions) {
	
	int points = 0;
	for (unsigned int i = 0; i < count_of_questions; ++i) {
		std::cout << questions[i].question;

		std::string writing_ans;
		std::cin >> writing_ans;

		if (questions[i].check_answer(writing_ans)) {
			points++;
			std::cout << "Ответ верный. +1 балл" << std::endl;
		}
		else
			std::cout << "Ответ неверный." << points << std::endl;
	}

	if (points > 2)
		std::cout << "\nПоздравляем, тест засчитан! Количество набранных баллов: " << points << std::endl;
	else
		std::cout << "\nК сожалению, тест не засчитан. Количество набранных баллов: " << points << std::endl;

}