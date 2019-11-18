#pragma once
#include <string.h>
#include <vector>
#include <iostream>
extern void addQuestion(std::string question, std::string answer);
extern void initTest(size_t count_of_questions);
class List {
public:
	std::string question; //Вопрос
	std::string answer; //Правильный ответ
	bool check_answer(std::string num)
	{
		if (answer == num) return true;
		return false;
	}
	List() {
		question = "";
		answer = "";

	}
};
extern std::vector<List> questions;
