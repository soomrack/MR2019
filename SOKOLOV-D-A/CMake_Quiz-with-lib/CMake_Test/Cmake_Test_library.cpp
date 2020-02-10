#include "CMake_Test_library.h"
const unsigned int count_of_questions = 3;
std::vector<List> questions(count_of_questions);


void addQuestion()
{
	
	questions.at(0).question = "������ ����� ����� ������� ������? (������������ �����) \n";
	questions.at(0).answer = "�����";
	questions.at(1).question = "��������� �� \n";
	questions.at(1).answer = "�����";
	questions.at(2).question = "����� ������� ���? \n";
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
			std::cout << "����� ������. +1 ����" << std::endl;
		}
		else
			std::cout << "����� ��������." << points << std::endl;
	}

	if (points > 2)
		std::cout << "\n�����������, ���� ��������! ���������� ��������� ������: " << points << std::endl;
	else
		std::cout << "\n� ���������, ���� �� ��������. ���������� ��������� ������: " << points << std::endl;

}