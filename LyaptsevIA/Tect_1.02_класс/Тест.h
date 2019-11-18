#pragma once
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <mciapi.h>
#include <vector>
#pragma comment(lib, "Winmm.lib")
using namespace std;

void Test();

int Proverka(int V, int K);

class Test_class
{
public:
	string question;
	string variants;
	int answer;

	int process_question()
	{
		int users_answer;
		cout << question << endl;
		cout << variants << endl;
		cin >> users_answer;
		int right = Proverka(answer, users_answer);
		return right;
	}
};