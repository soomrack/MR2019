#include "CMake_Test_library.h"
const unsigned int count_of_questions = 3;
std::vector<List> questions(count_of_questions);


void addQuestion()
{
	
	questions.at(0).question = "Какого цвета спина первого апреля? (именительный падеж) \n";
	questions.at(0).answer = "Белый";
	questions.at(1).question = "Президент РФ \n";
	questions.at(1).answer = "Путин";
	questions.at(2).question = "Какой сегодня год? \n";
	questions.at(2).answer = "2019";
}
void initTest()
{
	addQuestion();
	
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