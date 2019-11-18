#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

int process_answer(string answer, string users_answer); 

void final_test();

class Test
{
public:
	string question;
	string variants;
	string answer;

	int process_question()
	{
		string users_answer;
		cout << question << endl;
		cout << variants << endl;
		cin >> users_answer;
		int right = process_answer(answer, users_answer);
		return right;
	}
};