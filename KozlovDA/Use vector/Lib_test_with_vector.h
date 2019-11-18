#ifndef LIB_CLASSES_H
#define LIB_CLASSES_H

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>

void ba_dom_tss(int dots);
void processing_of_answer(std::string right_answer, std::string answer);

class Question
{
public:
	std::string question;
	std::string answers;
	std::string right_answer;

	void processing_of_question()
	{
		std::string users_answer;
		std::cout << question << '\n';
		std::cout << answers << '\n';
		std::cin >> users_answer;
		processing_of_answer(right_answer, users_answer);
	}
};

#endif 
