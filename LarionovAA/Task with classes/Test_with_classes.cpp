#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

class question
{
public:
	int score = 0;
	int user_answer = 0;
	void HelloSay()
	{
		cout << endl << "Please, write your name" << endl;
		string name;
		cin >> name;
		cout << "Welcome to Test_Number_One," << name << "!" << endl << \
			    "You need to answer some questions!" << endl;
	}
	void QuestionStart()
	{
		string answer;
		do
		{
			cout << "Are you ready? Write 'Yes' or 'No'?" << endl;
			cin >> answer;
		} while (answer != "Yes");
		cout << "Okey! Next question..." << endl;
	}
	void QuestionOrVariantAnswerShow(const string text)
	{
		cout << endl << text << endl;
	}
	void AnswerChooseAndCheck(const int right_answer)
	{
		cin >> user_answer;
		if (user_answer == right_answer)
		{
			cout << endl << "Congratulations!" << endl;
			score += 1;
		}
		else
		{
			cout << endl << "You are failed!" << endl;
		}
		cout << "Your score - " << score << endl;
	}
	void Final()
	{
		cin >> user_answer;
		if (user_answer == 0)
		{
			cout << endl << "Wow! It is unpleasant!" << endl;
		}
		else
		{
			cout << endl << "Wow! You are an optimist!" << endl;
		}
		score += 100 - score;
		cout << "Your score - " << score << endl;
		cout << "This was the last question in the test." << endl;
		cout << "Thanks you for your attention!" << endl;
	}
	int NewGameStart()
	{
		string answer;
		do
		{
			cout << endl << "Start a new game? Write 'Yes' or 'No'?" << endl;
			cin >> answer;
		} while (answer != "Yes");
		cout << endl << "Okey! New game in three..." << endl;
		Sleep(1000);
		cout << "...two..." << endl;
		Sleep(1000);
		cout << "...one..." << endl;
		return 1;
	}
};

int main()
{
tryAgain:
	question Test;
		//Greeting
	Test.HelloSay();
		//Question 1
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("1. How much is 2 + 2? Write a number.");
	Test.AnswerChooseAndCheck(4);
		//Question 2
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("2. When was the Polytechnic University founded ? Write the year.");
	Test.AnswerChooseAndCheck(1899);
		//Question 3
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("3. Who created this test? Select item and write number.");
	Test.QuestionOrVariantAnswerShow("1) Steve Jobs");
	Test.QuestionOrVariantAnswerShow("2) Charles Babbage");
	Test.QuestionOrVariantAnswerShow("3) Anton Larionov");
	Test.QuestionOrVariantAnswerShow("4) Ivan Kulibin");
	Test.AnswerChooseAndCheck(3);
		//Question 4
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("4. Who invented Google? Select a few items. Write fisrt and next answer together (without space).");
	Test.QuestionOrVariantAnswerShow("1) Lawrence Page");
	Test.QuestionOrVariantAnswerShow("2) Bruce Wayne");
	Test.QuestionOrVariantAnswerShow("3) Sergey Brin");
	Test.QuestionOrVariantAnswerShow("4) Clark Kent");
	Test.QuestionOrVariantAnswerShow("5) Tony Stark");
	Test.AnswerChooseAndCheck(13);
		//Question 5
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("5. What minimum points do you score? Write the number.");
	Test.Final();
		//New Game?
	int new_game = Test.NewGameStart();
	if (new_game == 1)
	{
		goto tryAgain;
	};
}

