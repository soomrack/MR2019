
#include "QuestionTest.h"

template <typename K>
void PrintMultiplication(const K* array, const K& answer)
{
	string user;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl << "What is the sum of the elements?" << endl;
	cin >> user;
	cout << "Right answer is " << answer << endl;
}

QuestionTest::QuestionTest()
{
	HelloSay();
}

void QuestionTest::HelloSay()
{
	cout << endl << "Please, write your name" << endl;
	cin >> name;
	cout << "Welcome to Test_Number_One," << name << "!" << endl << \
		    "You need to answer some questions!" << endl;
}

void QuestionTest::QuestionStart()
{
	do
	{
		cout << "Are you ready? Write 'Yes' or 'No'?" << endl;
		cin >> start_answer;
	} while (start_answer != "Yes");
	cout << "Okey! Next question..." << endl;
}

void QuestionTest::QuestionOrVariantAnswerShow(const string& text_question, const string& text_answer)
{
	cout << endl << text_question << endl << text_answer << endl;
}

void QuestionTest::AnswerChooseAndCheck(const string& right_answer, const int& right_answer_copy)
{
	cin >> question_answer;
	if (question_answer == right_answer)
	{
		cout << endl << "Congratulations!" << endl;
		score += 1;
	}
	else
	{
		cout << endl << "You are failed!" << endl;
	}
	cout << "Your score - " << score << endl;
	// Write the answer to the end of the vector and extend it
	answer_array.insert(answer_array.end(), right_answer_copy);
}

void QuestionTest::RightAnswerShow()
{
	cout << endl << "Right answers" << endl;
	// Show the contents of the vector
	copy(answer_array.begin(), answer_array.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void QuestionTest::Final()
{
	cin >> question_answer;
	if (question_answer == "0")
	{
		cout << endl << "Wow! It is unpleasant!" << endl;
	}
	else
	{
		cout << endl << "Wow! You are an optimist!" << endl;
	}
	score += 100 - score;
	cout << "Your score - " << score << endl;
	cout << "This was the last question in the test." << endl << \
		    "Thanks you for your attention!" << endl;
}

int QuestionTest::NewGameStart()
{
	do
	{
		cout << endl << "Start a new game? Write 'Yes' or 'No'?" << endl;
		cin >> start_answer;
	} while (start_answer != "Yes");
	cout << endl << "Okey! New game in three..." << endl;
	Sleep(1000);
	cout << "...two..." << endl;
	Sleep(1000);
	cout << "...one..." << endl;
	Sleep(1000);
	return 1;
}

void QuestionTest::ElementsOfArraySum()
{
	double mass1[10] = { 1.01, 2.02, 3.03, 4.04, 5.05, 6.06, 7.07, 8.08, 9.00, 10.1 };
	double answer1 = 55.55;
	PrintMultiplication(mass1, answer1);
	Sleep(1000);
	int mass2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int answer2 = 55;
	PrintMultiplication(mass2, answer2);
}