#include <stdio.h>
#include <stdint.h>
#include <string.h>

void enterYourAnswer(char *answer)
{
	scanf("%s", answer);
}

void printScore(int32_t score)
{
	printf("%d/10\n", score);
}

char *printQuestion(int32_t number)
{
	switch(number)
	{
		case 1:
		{
			printf("2 + 2 * 2 = ");
			return "6";
		}
		break;

		case 2:
		{
			printf("\nint i = 5;\n");
			printf("++i + ++i = ");
			return "14";
		}
		break;

		case 3:
		{
			printf("\n150 + 150 = ");
			return "300";
		}
		break;

		case 4:
		{
			printf("\nsizeof(int8_t) = ");
			return "1";
		}
		break;

		case 5:
		{
			printf("\nSpeed of ligth (m/s) = ");
			return "299792458";
		}
		break;

		case 6:
		{
			printf("\nAnswer to the Ultimate Question of Life, the Universe, and Everything: ");
			return "42";
		}
		break;

		case 7:
		{
			printf("\nNumber of genders: ");
			return "2";
		}
		break;

		case 8:
		{
			printf("\nNumber of planets in the Solar System: ");
			return "8";
		}
		break;

		case 9:
		{
			printf("\nNumber of letters in the Russian alphabet: ");
			return "33";
		}
		break;

		case 10:
		{
			printf("\nNumber of days in the week: ");
			return "7";
		}
		break;

		default:
		break;
	}
}

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

