#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "test.h";

int main()
{
	int32_t number_of_question;
	int32_t score = 0;
	char right_answer[20];
	char answer[20];
	for (number_of_question = 1; number_of_question <= 10; number_of_question++)
	{
		strcpy(right_answer, printQuestion(number_of_question));
		enterYourAnswer(answer);
		if (strcmp(answer, right_answer) == 0) score++;
		printScore(score);
	}
	enterYourAnswer(answer);
}
