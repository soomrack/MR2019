#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int SB = 0, SW = 0, RZ = 0, LX = 0;

vector <string> Questions = { "1. Что вы любите делать в свободное время ? \n 1) спать \n 2) гулять \n 3) мечтать \n 4) смотреть аниме \n" ,
							"2.Какой ваш любимый цвет ? \n 1) розовый \n 2) красный \n 3) желтый \n 4) влюбленной жабы \n",
							"3.Лучшее ваше качество ? \n 1)мечтательность \n 2) доброта \n 3) сила духа \n 4) саркастичность \n",
							"4.Какой  у вас напарник ? \n 1) конь \n 2) семь гномов \n 3) хамелеон \n 4) корги \n " };


vector <string> Conclude = { "Поздравляем, Вы Спящая красавица, берегитесь игл и ... сладких снов\n\n",
							"Поздравляем, Вы Белоснежка, остерегайтесь яблок\n\n",
							"Поздравляем, Вы Рапунцель, вооружитесь сковородкой и НИКОГДА не ровняйте кончики\n\n",
							"Вы не принцесса, вы Леха, психологический возраст 73\n\n" };

class TestQuestion
{
	
public:
	char answer;

	void OutputQuestion(string message)
	{
		cout << message;
	}
	char GetAnswer()
	{
		cin >> answer;
		return answer;
	}
	int CountPoints(int a = 0)
	{
		
		while (a < 1)
		{
			switch (answer)
			{
			case '1':
				SB++;
				a = 2;
				break;
			case '2':
				SW++;
				a = 2;
				break;
			case '3':
				RZ++;
				a = 2;
				break;
			case '4':
				LX++;
				a = 2;
				break;
			default:
				cout << "Ваше высочество, поправьте ваш ответ\n\n";
				a = 0;
				break;
			}

		}
		a = 0;
		return  SB, SW, RZ, LX;
	}

	string Result()
	{
		string Conclusion;
	
		if (max(max(SB, SW), max(RZ, LX)) == SB)
		{
			Conclusion = Conclude[0];
		}
		if (max(max(SB, SW), max(RZ, LX)) == SW)
		{
			Conclusion = Conclude[1];
		}
		if (max(max(SB, SW), max(RZ, LX)) == RZ)
		{
			Conclusion = Conclude[2];
		}
		if (max(max(SB, SW), max(RZ, LX)) == LX)
		{
			Conclusion = Conclude[3];
		}
		return Conclusion;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	TestQuestion question1;
	question1.OutputQuestion(Questions[0]);
	question1.GetAnswer();
	question1.CountPoints();

	TestQuestion question2;
	question2.OutputQuestion(Questions[1]);
	question2.GetAnswer();
	question2.CountPoints();

	TestQuestion question3;
	question3.OutputQuestion(Questions[2]);
	question3.GetAnswer();
	question3.CountPoints();

	TestQuestion question4;
	question4.OutputQuestion(Questions[3]);
	question4.GetAnswer();
	question4.CountPoints();

	TestQuestion Princess;
	cout << Princess.Result();
}