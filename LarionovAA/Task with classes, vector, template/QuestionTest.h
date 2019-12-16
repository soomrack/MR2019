
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "windows.h"

using namespace std;

class QuestionTest
{
private:
	int score = 0;
	string question_answer;
	string name;
	string start_answer;
	vector<int> answer_array;
public:
	// Greeting
	QuestionTest();
	void HelloSay();
	// Desire to start the test
	void QuestionStart();
	// Body of the question
	void QuestionOrVariantAnswerShow(const string& text_question, const string& text_answer);
	// Answer checking and scoring
	void AnswerChooseAndCheck(const string& right_answer, const int& right_answer_copy);
	// End of the test
	void Final();
	// Right answers for the future
	void RightAnswerShow();
	// Desire to repeat the test
	int NewGameStart();

	// In addition
	void ElementsOfArraySum();
};