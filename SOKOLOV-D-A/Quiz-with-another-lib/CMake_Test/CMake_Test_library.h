#pragma once
#include <string.h>
#include <vector>
#include <iostream>
extern void initTest();
class List {
public:
	std::string question; //������
	std::string answer; //���������� �����
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
