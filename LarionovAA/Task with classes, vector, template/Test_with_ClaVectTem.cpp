// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "QuestionTest.h"

int main()
{
tryAgain:
	QuestionTest Test;

	//Question 1
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("1. How much is 2 + 2? Write a number.", "\0");
	Test.AnswerChooseAndCheck("4", 4);

	//Question 2
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("2. When was the Polytechnic University founded ? Write the year.", "\0");
	Test.AnswerChooseAndCheck("1899", 1899);

	//Question 3
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("3. Who created this test? Select item and write number.", \
		                             "1) Steve Jobs\n2) Charles Babbage\n3) Anton Larionov\n4) Ivan Kulibin\n");
	Test.AnswerChooseAndCheck("3", 3);

	//Question 4
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("4. Who invented Google? Select a few items. Write fisrt and next answer together (without space).", \
		                             "1) Lawrence Page\n2) Bruce Wayne\n3) Sergey Brin\n4) Clark Kent\n5) Tony Stark\n");
	Test.AnswerChooseAndCheck("13", 13);

	//Question 5
	Test.QuestionStart();
	Test.QuestionOrVariantAnswerShow("5. What minimum points do you score? Write the number.", "\0");
	Test.Final();

	Test.RightAnswerShow();
	Test.ElementsOfArraySum();

	//New Game?
	int new_game = Test.NewGameStart();

	if (new_game == 1)
	{
		goto tryAgain;
	};

	return 0;
}