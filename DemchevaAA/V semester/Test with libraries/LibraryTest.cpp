#include "pch.h"
#include <iostream>
#include <string>
#include "LibraryTest.h"
using namespace std;

int StartTest()
{
tryAgain:
	cout << "" << endl;
	cout << "" << endl;
	cout << "Please, write your name" << endl;
	string a;
	cout << "" << endl;
	cin >> a;
	cout << "" << endl;
	cout << "Welcome to Test_Number_One," << a << "!" << endl;
	cout << "You need to answer some questions!" << endl;
	cout << "Are you ready? Write 'Yes' or 'No'?" << endl;
	cin >> a;
	if (a == "Yes")
	{
		cout << "Okey! First question..." << endl;
	}
	else
	{
		do
		{
			cout << "Are you ready? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
		cout << "Okey! First question..." << endl;
	}
	int score = 0;
	//
	// First Question
	int answer_one;
	cout << "" << endl;
	cout << "1. How much is 2 + 2? Write a number." << endl;
	cout << "" << endl;
	cin >> answer_one;
	if (answer_one == 4)
	{
		cout << "" << endl;
		cout << "Congratulations!" << endl;
		score += 1;
		cout << "Your score - " << score << endl;
		cout << "Next question? Write 'Yes' or 'No'?" << endl;
		cin >> a;
	}
	else
	{
		cout << "" << endl;
		cout << "You are failed!" << endl;
		cout << "Your score - " << score << endl;
		do
		{
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
	}
	if (a == "Yes")
	{
		cout << "Okey! Next question..." << endl;
	}
	else
	{
		do
		{
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
		cout << "Okey! Next question..." << endl;
	}
	//
	// Second Question
	int answer_two;
	cout << "" << endl;
	cout << "2. When was the Polytechnic University founded? Write the year." << endl;
	cout << "" << endl;
	cin >> answer_two;
	if (answer_two == 1899)
	{
		cout << "" << endl;
		cout << "Congratulations!" << endl;
		score += 2;
		cout << "Your score - " << score << endl;
		cout << "Next question? Write 'Yes' or 'No'?" << endl;
		cin >> a;
	}
	else
	{
		cout << "" << endl;
		cout << "You are failed!" << endl;
		cout << "Your score - " << score << endl;
		do
		{
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
	}
	if (a == "Yes")
	{
		cout << "Okey! Next question..." << endl;
	}
	else
	{
		do
		{
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
		cout << "Okey! Next question..." << endl;
	}
	//
	// Third Question
	int answer_three;
	cout << "" << endl;
	cout << "3. Who created this test? Select item and write number." << endl;
	cout << "1) Steve Jobs" << endl;
	cout << "2) Charles Babbage" << endl;
	cout << "3) Anton Larionov" << endl;
	cout << "4) Ivan Kulibin" << endl;
	cout << "" << endl;
	cin >> answer_three;
	if (answer_three == 3)
	{
		cout << "" << endl;
		cout << "Congratulations!" << endl;
		score += 3;
		cout << "Your score - " << score << endl;
		cout << "Next question? Write 'Yes' or 'No'?" << endl;
		cin >> a;
	}
	else
	{
		cout << "" << endl;
		cout << "You are failed!" << endl;
		cout << "Your score - " << score << endl;
		do
		{
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
	}
	if (a == "Yes")
	{
		cout << "Okey! Next question..." << endl;
	}
	else
	{
		do
		{
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
		cout << "Okey! Next question..." << endl;
	}
	//
	// Fourth Question
	int answer_four;
	cout << "" << endl;
	cout << "4. Who invented Google? Select a few items. Write one number fisrt and then another." << endl;
	cout << "1) Lawrence Page" << endl;
	cout << "2) Bruce Wayne " << endl;
	cout << "3) Sergey Brin" << endl;
	cout << "4) Clark Kent" << endl;
	cout << "5) Tony Stark" << endl;
	cout << "" << endl;
	cin >> answer_four;
	if (answer_four == 1 || answer_four == 3)
	{
		cout << "" << endl;
		cout << "First answer is right!" << endl;
		cout << "Next answer, please." << endl;
		cout << "" << endl;
		cin >> answer_four;
		if (answer_four == 1 || answer_four == 3)
		{
			cout << "" << endl;
			cout << "Congratulations! Second answer is right!" << endl;
			score += 4;
			cout << "Your score - " << score << endl;
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		}
		else
		{
			cout << "" << endl;
			cout << "Second answer is wrong!" << endl;
			score += 2;
			cout << "Your score - " << score << endl;
			do
			{
				cout << "Next question? Write 'Yes' or 'No'?" << endl;
				cin >> a;
			} while (a != "Yes");
		}
	}
	else
	{
		cout << "" << endl;
		cout << "First answer is wrong!" << endl;
		cout << "Next answer, please." << endl;
		cout << "" << endl;
		cin >> answer_four;
		if (answer_four == 1 || answer_four == 3)
		{
			cout << "" << endl;
			cout << "Congratulations! Second answer is right!" << endl;
			score += 2;
			cout << "Your score - " << score << endl;
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		}
		else
		{
			cout << "" << endl;
			cout << "Second answer is wrong!" << endl;
			cout << "Your score - " << score << endl;
			do
			{
				cout << "Next question? Write 'Yes' or 'No'?" << endl;
				cin >> a;
			} while (a != "Yes");
		}
	}
	if (a == "Yes")
	{
		cout << "Okey! Next question..." << endl;
	}
	else
	{
		do
		{
			cout << "Next question? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
		cout << "Okey! Next question..." << endl;
	}
	//
	// Last Question
	int answer_last;
	cout << "" << endl;
	cout << "5. What minimum points do you score? Write the number." << endl;
	cout << "" << endl;
	cin >> answer_last;
	if (answer_last == 0)
	{
		cout << "" << endl;
		cout << "Wow! It is unpleasant!" << endl;
		score += 100 - score;
		cout << "Your score - " << score << endl;
		cout << "This was the last question in the test." << endl;
		cout << "Thanks you for your attention!" << endl;
		cout << "Start a new game? Write 'Yes' or 'No'?" << endl;
		cin >> a;
	}
	else
	{
		cout << "" << endl;
		cout << "Wow! You are an optimist!" << endl;
		score += 100 - score;
		cout << "Your score - " << score << endl;
		cout << "This was the last question in the test." << endl;
		cout << "Thanks you for your attention!" << endl;
		do
		{
			cout << "Start a new game? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
	}
	if (a == "Yes")
	{
		cout << "" << endl;
		cout << "Okey! New game in three..." << endl;
		cout << "...two..." << endl;
		cout << "...one..." << endl;
		goto tryAgain;
	}
	else
	{
		do
		{
			cout << "Start a new game? Write 'Yes' or 'No'?" << endl;
			cin >> a;
		} while (a != "Yes");
		cout << "" << endl;
		cout << "Okey! New game in three..." << endl;
		cout << "...two..." << endl;
		cout << "...one..." << endl;
		goto tryAgain;
	}
}